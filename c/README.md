C, CUnit and Make
=================

Prerequisites
-------------

**gcc**:

To check if it is installed already:

    $ gcc -v
    gcc version 4.4.7 20120313 (Red Hat 4.4.7-3) (GCC) 

**CUnit 2.1-2**:

To download, build and install see
[CUnit](http://cunit.sourceforge.net/). See below for notes on
installing. 

After installing ensure that the `bin`, `include` and `lib`
directories holding the CUnit files are in your paths e.g.

    $ export C_INCLUDE_PATH=/home/user/include:$C_INCLUDE_PATH
    $ export LIBRARY_PATH=/home/user/lib:$LIBRARY_PATH
    $ export LD_LIBRARY_PATH=/home/user/lib:$LD_LIBRARY_PATH

2.1-2 is the version the code has been tested against. Other versions
may also be OK.

**xsltproc**:

To check if it is installed already:

    $ xsltproc -version
    Using libxml 20706, libxslt 10126 and libexslt 815
    xsltproc was compiled against libxml 20706, libxslt 10126 and libexslt 815
    libxslt 10126 was compiled against libxml 20706
    libexslt 815 was compiled against libxml 20706

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

    $ make fibonacci

Run:

    $ ./fibonacci 30

Compile tests:

    $ make tests

Run tests and view XML test report:

    $ ./tests
    $ cat CUnitAutomated-Results.xml 

or:

    $ make runtests
    $ cat CUnitAutomated-Results.xml 


View results as XML xUnit-style test report:

    $ make report
    $ cat TestResults.xml

Clean up:

    $ make clean

Notes on how to install CUnit 2.1.2
-----------------------------------

For full instructions on how to download, build and install see
[CUnit](http://cunit.sourceforge.net/).

Download `CUnit-2.1-2-src.tar.bz2`.

Install in `/home/user`:

    $ tar -xvjpf CUnit-2.1-2-src.tar.bz2  
    $ cd CUnit-2.1-2/
    $ ./configure --prefix=/home/user
    $ make
    $ make install
    $ ls /home/user/include
    CUnit
    $ ls /home/user/share
    CUnit
    $ ls /home/user/lib
    libcunit.a   libcunit.so    libcunit.so.1.0.1
    libcunit.la  libcunit.so.1
    $ ls /home/user/lib/pkgconfig
    cunit.pc
