C, CUnit and Make
=================

Prerequisites
-------------

**gcc**:

To check if gcc is installed already:

```
$ gcc -v
gcc version 4.4.7 20120313 (Red Hat 4.4.7-3) (GCC) 
```

**CUnit 2.1-2**:

To download, build and install see [CUnit](http://cunit.sourceforge.net/). The following provides a quick summary of the key steps to build and install CUnit in your home directory:

```
$ wget http://downloads.sourceforge.net/project/cunit/CUnit/2.1-2/CUnit-2.1-2-src.tar.bz2
$ tar -xvjpf CUnit-2.1-2-src.tar.bz2
$ cd CUnit-2.1-2
$ ./configure --prefix=$HOME
$ make
$ make install
$ ls $HOME/include/CUnit
Util.h     TestDB.h  CUnit_intl.h  CUError.h  Basic.h
TestRun.h  MyMem.h   CUnit.h       Console.h  Automated.h
$ ls $HOME/lib
libcunit.a   libcunit.so    libcunit.so.1.0.1
libcunit.la  libcunit.so.1
$ ls $HOME/share/CUnit
CUnit-List.dtd  CUnit-Run.dtd  Memory-Dump.dtd
CUnit-List.xsl  CUnit-Run.xsl  Memory-Dump.xsl
$ export C_INCLUDE_PATH=$HOME/include:$C_INCLUDE_PATH
$ export LIBRARY_PATH=$HOME/lib:$LIBRARY_PATH
$ export LD_LIBRARY_PATH=$HOME/lib:$LD_LIBRARY_PATH
```

2.1-2 is the version the code has been tested against. Other versions may also be OK.

**xsltproc**:

To check if xsltproc is installed already:

```
$ xsltproc -version
Using libxml 20706, libxslt 10126 and libexslt 815
xsltproc was compiled against libxml 20706, libxslt 10126 and libexslt 815
libxslt 10126 was compiled against libxml 20706
libexslt 815 was compiled against libxml 20706
```

**CUnit to JUnit XSL transform**:

This is provided.

* Files: `cunit-to-junit.xsl`.
* Version: Unspecified.
* Licence: Unspecified. Written by Oliver van Porten.
* Web site: http://www.van-porten.de/2009/05/cunit-tests-in-hudson/. 
* Web site: https://bitbucket.org/mcdeck/cunit-to-junit

Usage
-----

Compile:

```
$ make fibonacci
```

Run:

```
$ ./fibonacci 30
```

Compile and run tests and view XML test report:

```
$ make test
$ cat CUnitAutomated-Results.xml 
```

Convert above XML test report into an XML xUnit-style test report:

```
$ make xunit-report
$ cat TestResults.xml
```

Clean up:

```
$ make clean
```
