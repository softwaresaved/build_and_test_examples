
C++, CppUnit, googletest and Make
=================================

Prerequisites
-------------

**c++**:

To check if it is installed already:

    $ c++ -v
    gcc version 4.4.7 20120313 (Red Hat 4.4.7-3) (GCC) 

**CppUnit 1.13.2**:

To download, build and install see
[CppUnit](http://www.freedesktop.org/wiki/Software/cppunit/). See
below for notes on installing. 

After installing ensure that the `bin`, `include` and `lib`
directories holding the CppUnit files are in your paths e.g.

    $ export C_INCLUDE_PATH=/home/user/include:$C_INCLUDE_PATH
    $ export LIBRARY_PATH=/home/user/lib:$LIBRARY_PATH
    $ export LD_LIBRARY_PATH=/home/user/lib:$LD_LIBRARY_PATH

1.13.22 is the version the code has been tested against. Other
versions may also be OK.

**googletest 1.7.0**:

To download, build and install see
[googletest](https://code.google.com/p/googletest/). See
below for notes on installing. 

After installing ensure that the `bin`, `include` and `lib`
directories holding the googletest files are in your paths e.g.

    $ export C_INCLUDE_PATH=/home/user/include:$C_INCLUDE_PATH
    $ export LIBRARY_PATH=/home/user/lib:$LIBRARY_PATH
    $ export LD_LIBRARY_PATH=/home/user/lib:$LD_LIBRARY_PATH

1.7.0 is the version the code has been tested against. Other
versions may also be OK.

Usage
-----

Compile:

    $ make fibonacci

Run:

    $ ./fibonacci 30

Compile CppUnit tests:

    $ make cppunittests

Run CppUnit tests and view XML test report:

    $ ./cppunittests
    $ cat TestResults.xml 

Or:

    $ make runcppunittests
    $ cat TestResults.xml 

Compile googletest tests:

    $ make googletests

Run googletest tests and view XML test report:

    $ ./googletests --gtest_output="xml:TestResults.xml"
    $ cat TestResults.xml 

Or:

    $ make rungoogletests
    $ cat TestResults.xml 

Clean up:

    $ make clean

Notes on how to install CppUnit 1.13.2
--------------------------------------

According to Wikipedia, CppUnit has been forked several times and the
current, actively maintained version is by Markus Mohrhard of the
LibreOffice project (which uses CppUnit heavily)". Documentation
for an earlier version are in the last three links below:

* Wikipedia - [CppUnit](http://en.wikipedia.org/wiki/CppUnit).
* LibreOffice [CppUnit](http://www.freedesktop.org/wiki/Software/cppunit/).
* Original [CppUnit](http://sourceforge.net/apps/mediawiki/cppunit/index.php?title=Main_Page) project on SourceForge.
* [CppUnit Cookbook](http://cppunit.sourceforge.net/doc/1.11.6/cppunit_cookbook.html).
* [CppUnit assertons](http://cppunit.sourceforge.net/doc/1.11.6/group___assertions.html).

For full instructions on how to download, build and install see
[CppUnit](http://www.freedesktop.org/wiki/Software/cppunit/).

Download LibreOffice CppUnit `cppunit-1.13.2.tar.gz`.

Install in `/home/user`:

    $ tar -xvzf cppunit-1.13.2.tar.gz
    $ cd cppunit-1.13.2
    $ ./configure --prefix=/home/user
    $ make
    $ make check
    $ make install
    $ ls /home/user/include
    cppunit
    $ ls /home/user/share
    cppunit
    $ ls /home/user/lib
    libcppunit-1.13.so.0      libcppunit.la
    libcppunit-1.13.so.0.0.2  libcppunit.so
    libcppunit.a
    $ ls /home/user/lib/pkgconfig
    cppunit.pc
    $ ls /home/user/bin
    cppunit-config

If during `configure` you get:

    dirname: extra operand `/bin'

edit `configure` and replace all occurrences of:

     /* automatically generated */

with:

     $ac_prefix_conf_INP

See CppUnit [support request
53](http://sourceforge.net/p/cppunit/support-requests/53/) for more information.

`cppunit-config` displays C++ flags to use:

    $ cd ~/bin
    $ ./cppunit-config --cflags
    -I/home/user/include
    $ ./cppunit-config --libs
    -L/home/user/lib -lcppunit -ldl

Notes on how to install googletest
----------------------------------

For full instructions on how to download, build and install see
[googletest](https://code.google.com/p/googletest/).

Download `gtest-1.7.0.zip`.

Install in `/home/user`:

    $ unzip gtest-1.7.0.zip 
    $ cd gtest-1.7.0/
    $ ./configure --prefix=/home/user --with-pthreads=no.
    $ make
    $ cp -r include/gtest /home/user/include
    $ cp -r include/gtest/ /home/include
    $ cp -r lib/.libs/* ~/lib/
    $ ls /home/include
    gtest
    $ ls /home/lib
    libgtest.a         libgtest_main.so
    libgtest.la        libgtest_main.so.0
    libgtest.lai       libgtest_main.so.0.0.0
    libgtest_main.a    libgtest.so
    libgtest_main.la   libgtest.so.0
    libgtest_main.lai  libgtest.so.0.0.0
