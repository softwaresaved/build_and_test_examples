C++, CppUnit, googletest and Make
=================================

Prerequisites
-------------

**c++**:

To check if `c++` is installed already:

```

$ c++ -v
gcc version 4.4.7 20120313 (Red Hat 4.4.7-3) (GCC) 
```

**CppUnit test framework**:

To download, build and install see [CppUnit](http://www.freedesktop.org/wiki/Software/cppunit/). The following provides a quick summary of the key steps to build and install CppUnit in your home directory:

```
$ wget http://dev-www.libreoffice.org/src/cppunit-1.13.2.tar.gz
$ tar -xvzf cppunit-1.13.2.tar.gz
$ cd cppunit-1.13.2
$ ./configure --prefix=$HOME
$ make
$ make install 
$ ls $HOME/include/cppunit
AdditionalMessage.h          Protector.h           TestResultCollector.h
Asserter.h                   SourceLine.h          TestResult.h
BriefTestProgressListener.h  SynchronizedObject.h  TestRunner.h
CompilerOutputter.h          TestAssert.h          TestSuccessListener.h
config                       TestCaller.h          TestSuite.h
config-auto.h                TestCase.h            TextOutputter.h
Exception.h                  TestComposite.h       TextTestProgressListener.h
extensions                   TestFailure.h         TextTestResult.h
Message.h                    TestFixture.h         TextTestRunner.h
Outputter.h                  Test.h                tools
plugin                       TestLeaf.h            ui
portability                  TestListener.h        XmlOutputter.h
Portability.h                TestPath.h            XmlOutputterHook.h
$ ls $HOME/lib
libcppunit-1.13.so.0      libcppunit.a   libcppunit.so
libcppunit-1.13.so.0.0.2  libcppunit.la
$ ls $HOME/share/cppunit
html
$ export CPLUS_INCLUDE_PATH=$HOME/include:$CPLUS_INCLUDE_PATH
$ export LIBRARY_PATH=$HOME/lib:$LIBRARY_PATH
$ export LD_LIBRARY_PATH=$HOME/lib:$LD_LIBRARY_PATH
```

**googletest test framework**:

To download, build and install see [googletest](https://code.google.com/p/googletest/). The following provides a quick summary of the key steps to build and install googletest in your home directory:

```
$ wget https://googletest.googlecode.com/files/gtest-1.7.0.zip
$ unzip gtest-1.7.0.zip 
$ cd gtest-1.7.0/
$ ./configure --prefix=$HOME --with-pthreads=no
$ make
$ cp -r include/gtest $HOME/include
$ cp lib/.libs/* $HOME/lib/
$ ls $HOME/include/gtest
gtest-death-test.h  gtest-param-test.h.pump  gtest-spi.h
gtest.h             gtest_pred_impl.h        gtest-test-part.h
gtest-message.h     gtest-printers.h         gtest-typed-test.h
gtest-param-test.h  gtest_prod.h             internal
$ ls $HOME/lib
libgtest.a    libgtest_main.a    libgtest_main.so        libgtest.so
libgtest.la   libgtest_main.la   libgtest_main.so.0      libgtest.so.0
libgtest.lai  libgtest_main.lai  libgtest_main.so.0.0.0  libgtest.so.0.0.0
$ export CPLUS_INCLUDE_PATH=$HOME/include:$CPLUS_INCLUDE_PATH
$ export LIBRARY_PATH=$HOME/lib:$LIBRARY_PATH
$ export LD_LIBRARY_PATH=$HOME/lib:$LD_LIBRARY_PATH
```

Usage
-----

Compile:

```
$ make fibonacci
```

Run:

```
$ ./fibonacci 30
fibonacci(30) = 832040
```

Compile and run CppUnit tests and view XML test report:

```
$ make test
$ cat TestResults.xml 
```

Compile and run googletest tests and view XML xUnit-style test report:

```
$ make googletest
$ cat TestResults.xml 
```

Clean up:

```
$ make clean
```

Comments on CppUnit 1.13.2
--------------------------

According to Wikipedia, "CppUnit has been forked several times and the current, actively maintained version is by Markus Mohrhard of the LibreOffice project (which uses CppUnit heavily)". This is the version used above.

Documentation for an earlier version are in the last three links below:

* Wikipedia - [CppUnit](http://en.wikipedia.org/wiki/CppUnit).
* LibreOffice [CppUnit](http://www.freedesktop.org/wiki/Software/cppunit/).
* Original [CppUnit](http://sourceforge.net/apps/mediawiki/cppunit/index.php?title=Main_Page) project on SourceForge.
* [CppUnit Cookbook](http://cppunit.sourceforge.net/doc/1.11.6/cppunit_cookbook.html).
* [CppUnit assertons](http://cppunit.sourceforge.net/doc/1.11.6/group___assertions.html).

If during `configure` you get:

```
dirname: extra operand `/bin'
```

edit `configure` and replace all occurrences of:

```
 /* automatically generated */
```

with:

```
 $ac_prefix_conf_INP
```

See CppUnit [support request 53](http://sourceforge.net/p/cppunit/support-requests/53/) for more information.

`cppunit-config` displays C++ flags to use:

```
$ cd ~/bin
$ ./cppunit-config --cflags
-I$HOME/include
$ ./cppunit-config --libs
-L$HOME/lib -lcppunit -ldl
```
