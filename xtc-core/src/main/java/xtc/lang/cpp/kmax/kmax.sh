#!/bin/bash

# Extract the compilation units by running make.

export PATH=~/src/make/:$PATH

if [ $# -lt 1 ]; then
    echo "USAGE: `basename $0` arch"
    exit 1
fi

arch=$1
# User-mode Linux only supports x86
if [ $arch == "um" ]; then
    archdir=x86/um
else
    archdir=$arch
fi

if [ ! -d arch/$archdir ]; then
    echo "invalid architecture: $arch"
    exit 1
fi

# # mips won't work without turning off this config var
# if [ $arch == "mips" ]; then
#     cat > fudge <<EOF
# CPU_DADDI_WORKAROUNDS
# CPU_LOONGSON2F_WORKAROUNDS
# EOF
#     fudge="-a fudge"
# else
#     fudge=
# fi

action=everyyes

echo "preparing kernel source..."
# make ARCH=$arch clean mrproper >/dev/null 2>&1
make ARCH=$arch symlinks >/dev/null 2>&1

if [[ ! -f $arch.depsym || ! -f $arch.idepsym ]]; then
    echo "checking inclusive/exclusive kconfig strategies"
    ARCH=$arch check_dep --depsym arch/$archdir/Kconfig | sort > $arch.depsym.tmp
    mv $arch.depsym.tmp $arch.depsym
    ARCH=$arch check_dep --idepsym arch/$archdir/Kconfig | sort > $arch.idepsym.tmp
    mv $arch.idepsym.tmp $arch.idepsym
    diff $arch.depsym $arch.idepsym > /dev/null
    if [ $? -ne 0 ]; then
        echo "ERROR: depsym does not match idepsym: $config_file in $dir" >&2
        exit 1
    fi
fi

echo "generating configuration..."
ARCH=$arch check_dep $fudge --$action arch/$archdir/Kconfig

# echo "getting kcus using vmlinux target"
# kcu.sh -m vmlinux $arch | sort | uniq > $arch.$action.vmlinux

if [ ! -f $arch.alldirs ]; then
    echo "getting all kcu directories"
    make -i -f ~/src/kmax/Makefile.kcu ARCH=$arch alldirs | tail -n1 \
        > $arch.alldirs.tmp
    mv $arch.alldirs.tmp $arch.alldirs
else
    echo "$arch.alldirs already exists"
fi

if [ ! -f $arch.$action.alldirs ]; then
    echo "getting kcus using $arch.alldirs kcu directories"
    for subdir in `cat $arch.alldirs`; do
        echo "getting kcus from $subdir" >&2
        kcu.sh -m $subdir $arch
    done | sort | uniq > $arch.$action.alldirs.tmp
    mv $arch.$action.alldirs.tmp $arch.$action.alldirs
else
    echo "$arch.$action.alldirs already exists"
fi

if [ ! -f $arch.$action.extras.alldirs ]; then
    echo "look for makefile patterns"
    for subdir in `cat $arch.alldirs`; do
        find $subdir -type d | while read subdir; do
            echo "looking at patterns in $subdir" >&2
            kbuild_patterns.py $subdir | egrep "^force_off" \
                | cut -d' ' -f2- | while read i; do
                rm -rf force_off.tmp
                for v in $i; do
                # TODO: check that $v is actually in $arch.idepsym
                # remove CONFIG_ prefix
                    echo $v | cut -c8- >> force_off.tmp
                done
                echo "getting compilation units without $i..." >&2
                ARCH=$arch check_dep --$action -a force_off.tmp \
                    arch/$archdir/Kconfig >&2
                kcu.sh -m $subdir/ $arch # Kbuild target subdir must
                                         # end in forward-slash
            done
        done
    done | sort | uniq > $arch.$action.extras.alldirs.tmp
    mv $arch.$action.extras.alldirs.tmp $arch.$action.extras.alldirs
else
    echo "$arch.$action.extras.alldirs already exists"
fi

if [ ! -f $arch.pattern_counts ]; then
    echo "counting makefile patterns"
    for subdir in `cat $arch.alldirs`; do
        find $subdir -type d | while read subdir; do
            echo "counting patterns in $subdir" >&2
            kbuild_patterns.py $subdir | egrep "^count_" | grep -v " 0$"
        done
    done > $arch.pattern_counts.tmp

    for c in count_inconditional count_inconditionaloff count_reassignments; do
        echo "sum_$c" `sum.sh $c 1 < $arch.pattern_counts.tmp`
    done > $arch.pattern_counts
else
    echo "$arch.pattern_counts already exists"
fi
