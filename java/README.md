Java, JUnit and ANT
===================

Prerequisites
-------------

**Java JDK and JRE**:

To check if Java JDK and JRE are installed already:

```
$ javac -version
javac 1.6.0_24

$ java -version
java version "1.6.0_24"
OpenJDK Runtime Environment (IcedTea6 1.11.3) (6b24-1.11.3-1ubuntu0.11.04.1)
OpenJDK Client VM (build 20.0-b12, mixed mode, sharing)
```

Output may vary depending on the Java implementation e.g. for Oracle:

```
$ javac -version
javac 1.7.0_60

$ java -version
java version "1.7.0_60"
Java(TM) SE Runtime Environment (build 1.7.0_60-b19)
Java HotSpot(TM) 64-Bit Server VM (build 24.60-b09, mixed mode)
```

If Java JDK and JRE are not installed, then see one of:

* [Oracle Java](http://www.oracle.com/technetwork/java/javase/overview/index.html).
* [OpenJDK Java](http://openjdk.java.net/).

**ANT build tool**:

To check if ANT is installed already:

```
$ ant -version
Apache Ant version 1.7.1 compiled on November 24 2010
```

If not, then see [Apache ANT](http://ant.apache.org/bindownload.cgi).

After installing, ensure ANT is in your path e.g.

```
$ export PATH=$HOME/apache-ant-1.7.1/bin:$PATH
```

**JUnit test framework**:

This is provided.

* File: `lib/junit-4.10.jar`
* License: JUnit license, `JUNIT_LICENSE.txt`.
* Web site: http://junit.org.
* Used by: test code in `test/`.

Usage
-----

Compile and JAR:

```
$ ant jar
```

Run:

```
$ java -classpath build/lib/math.jar math.Fibonacci 30
fib(30) = 832040
```

Compile and run tests and view XML xUnit-style test report:

```
$ ant test
$ cat build/test/xml/TESTS-TestSuites.xml 
```

Convert above XML test report into HTML:

```
$ ant test-report
$ cat build/test/html/index.html
```

Clean up:

```
$ ant clean
```
