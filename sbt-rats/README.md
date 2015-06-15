sbt-rats provides a plugin that enables the [Rats! parser generator](https://cs.nyu.edu/rgrimm/xtc/rats.html) to be used in Scala projects.

The plugin enables you to use the [Rats! parser generator](https://cs.nyu.edu/rgrimm/xtc/rats.html) with Scala projects that are built using the [Scala build tool sbt](https://www.scala-sbt.org). The parser can be specified directly using a Rats! specification or using a simplified syntactic notation. The syntactic notation can also be translated into a Scala implementation of abstract syntax trees and a pretty printer for those trees. Pretty-printing support is provided by the [Kiama language processing library](https://kiama.googlecode.com).

sbt-rats is a project of the [Programming Languages Research Group](https://wiki.mq.edu.au/display/plrg/Welcome) in the [Department of Computing](http://www.comp.mq.edu.au/) at [Macquarie University](http://www.mq.edu.au) and is led by [Tony Sloane](https://bitbucket.org/inkytonik) (inkytonik).

## Usage

For information on usage, see the [documentation](https://bitbucket.org/inkytonik/sbt-rats/src/default/wiki/usage.md).

There is also a [giter8](http://github.com/n8han/giter8#readme) template showing a [simple usage of the plugin with Kiama](https://github.com/inkytonik/kiama-rats.g8).

## News

* April 21, 2015: [version 2.2.0](https://bitbucket.org/inkytonik/sbt-rats/src/default/notes/2.0.1.markdown) released on [bintray](https://bintray.com/inkytonik/sbt-plugins/sbt-rats/view)
* April 21, 2015: project moved to [BitBucket](https://bitbucket.org/inkytonik/sbt-rats)
* October 26, 2012: [version 2.1.0](https://bitbucket.org/inkytonik/sbt-rats/src/default/notes/2.1.0.markdown) released
* August 9, 2012: Slides for a ScalaSyd talk on sbt-rats [posted](https://speakerdeck.com/inkytonik/sbt-rats-packrat-parser-generation-for-scala).

## License

sbt-rats is released under the New BSD License.  See LICENSE for details.
