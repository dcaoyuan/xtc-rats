#!/bin/bash

make_target="vmlinux"
verbose=
while getopts :m:v opt; do
    case $opt in
        m)
            make_target="$OPTARG"
            ;;
        v)
            verbose=true
            ;;
        \?)
            echo "(`basename $0`)" "Invalid argument: -$OPTARG"
            ;;
        :)
            echo "(`basename $0`)" "-$OPTARG requires an argument."
            ;;
    esac
done

shift $(($OPTIND - 1))

arch=$1

if [ "$arch" == "" ]; then
    cat <<EOT
USAGE: `basename $0` [-v] [-m make_target] arch

    -v print all make output to stderr
EOT
    exit 1
fi

if [ ! -z "$verbose" ]; then
    # print all makefile output to stderr
    make -i -f ~/src/kmax/Makefile.kcu ARCH=$arch \
        CC="echo gcc" LD="echo ld" ar="echo ar" $make_target >&2
fi

make -i -f ~/src/kmax/Makefile.kcu ARCH=$arch \
    CC="echo gcc" LD="echo ld" ar="echo ar" $make_target 2>&1 \
    | egrep "^gcc|^echo gcc" | awk '{print$NF}' | grep "\.c$"
