import sbt._
import sbt.Keys._

object Build extends sbt.Build {

  lazy val xtc_rats = Project("xtc-rats", file("."))
    .aggregate(xtc_core, sbt_rats)
    .settings(Formatting.buildFileSettings: _*)

  lazy val xtc_core = Project("xtc-core", file("xtc-core"))
    .settings(basicSettings: _*)
    .settings(
      version := "2.4.1-SNAPSHOT",
      scalaVersion := "2.10.5")
    .settings(libraryDependencies ++= Seq(
      "junit" % "junit" % "4.8.2",
      "net.sf.jbddi" % "jbddi-core" % "1.0.1"))

  lazy val sbt_rats = Project("sbt-rats", file("sbt-rats"))
    .dependsOn(xtc_core)
    .settings(basicSettings: _*)
    .settings(
      sbtPlugin := true,
      version := "3.0.0-SNAPSHOT",
      scalaVersion := "2.10.5")
    .settings(Formatting.settings: _*)
    .settings(libraryDependencies ++= Seq(
      "com.googlecode.kiama" % "kiama_2.10" % "1.8.0"))

  lazy val basicSettings = Seq(
    organization := "com.wandoulabs.chana",
    scalacOptions ++= Seq("-unchecked", "-feature", "-deprecation"),
    javacOptions ++= Seq("-source", "1.6"),
    resolvers ++= Seq(
      "Spray repo" at "http://repo.spray.io",
      "Sonatype OSS Releases" at "https://oss.sonatype.org/content/repositories/releases",
      "Sonatype OSS Snapshots" at "https://oss.sonatype.org/content/repositories/snapshots",
      "Typesafe repo" at "http://repo.typesafe.com/typesafe/releases/"))
}

object Formatting {
  import com.typesafe.sbt.SbtScalariform
  import com.typesafe.sbt.SbtScalariform.ScalariformKeys
  import ScalariformKeys._

  val BuildConfig = config("build") extend Compile
  val BuildSbtConfig = config("buildsbt") extend Compile

  // invoke: build:scalariformFormat
  val buildFileSettings: Seq[Setting[_]] = SbtScalariform.noConfigScalariformSettings ++
    inConfig(BuildConfig)(SbtScalariform.configScalariformSettings) ++
    inConfig(BuildSbtConfig)(SbtScalariform.configScalariformSettings) ++ Seq(
      scalaSource in BuildConfig := baseDirectory.value / "project",
      scalaSource in BuildSbtConfig := baseDirectory.value,
      includeFilter in (BuildConfig, format) := ("*.scala": FileFilter),
      includeFilter in (BuildSbtConfig, format) := ("*.sbt": FileFilter),
      format in BuildConfig := {
        val x = (format in BuildSbtConfig).value
        (format in BuildConfig).value
      },
      ScalariformKeys.preferences in BuildConfig := formattingPreferences,
      ScalariformKeys.preferences in BuildSbtConfig := formattingPreferences)

  val settings = SbtScalariform.scalariformSettings ++ Seq(
    ScalariformKeys.preferences in Compile := formattingPreferences,
    ScalariformKeys.preferences in Test := formattingPreferences)

  val formattingPreferences = {
    import scalariform.formatter.preferences._
    FormattingPreferences()
      .setPreference(RewriteArrowSymbols, false)
      .setPreference(AlignParameters, true)
      .setPreference(AlignSingleLineCaseStatements, true)
      .setPreference(DoubleIndentClassDeclaration, true)
      .setPreference(IndentSpaces, 2)
  }
}

