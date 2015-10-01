Create a Travis CI job for popular programming languages
========================================================

Travis CI can build and run code written in many languages, including C, C++, Fortran, Java, PHP and Python, either directly or via automated build tools like Make or ANT. It can also run unit tests, for example written in CUnit, CppUnit, googletest, JUnit, PHPUnit or nosetests, and report on the success or failure of tests. For example, Travis CI provides out-of-the-box support for:

* C: gcc, clang, autotools, make.
* C++: gcc, clang, autotools, make.
* Java: versions of Oracle JDK and OpenJDK, ANT, Maven, Gradle. 
* PHP: versions of PHP, PHPUnit,  XDebug.
* Python: versions of Python 2 and 3, nose, pytest and mock test libraries.
* and many other [languages](http://docs.travis-ci.com/user/languages/).

Declare the language
--------------------

`.travis.yml` supports a `language` section which tells Travis CI which build environment it should use. Depending on the language selected, a language-specific section (e.g. `jdk`, `php` or `python`) can then be used to specify which versions of the language the job is to be run under. Travis CI will run the job for each of these versions.

* Edit `.travis.yml`, clear its current contents, and declare your language and any versions of the language you want to test. You can only declare one language in `travis.yml`.

**C**

```
language: c
```

**C++**

```
language: cpp
```

**Java**

```
language: java

jdk:
  - oraclejdk8
  - openjdk7
```

Here, we request that Travis CI runs the job twice, once under Oracle JDK 8 and once under Open JDK 7.

**PHP**

```
language: php

php:
  - 5.4
  - 5.5
```

**Python**

```
language: python

python:
  - "2.7"
  - "3.4"
```

Here, we request that Travis CI runs the job twice, once under Python 2.7 and once under Python 3.4.

List packages to install
------------------------

An `addons` section can, amongst other things, be used to install any packages we need. This can be used to specify packages that, if working locally, we'd need to install using the `apt` package manager. For example, if we wanted to use `graphviz` we could write:

```
addons:
  apt:
    packages:
    - graphviz
```

None of our examples below need any additional packages.

Define pre-install steps
------------------------

A `before_install` section lists the steps that need to be executed before we can build, run or test our code.

By default, Travis CI will run commands in the root of our Git repository i.e. within `build_and_test_examples`. So, to use our language-specific examples, we need to change into the appropriate directory. We can do this as a `before_install` step.

For certain languages, we also need to download, build and install additional dependencies.

**C**

We download, build and install CUnit, then change into our `c` directory:

```
before_install:
  - wget http://downloads.sourceforge.net/project/cunit/CUnit/2.1-2/CUnit-2.1-2-src.tar.bz2
  - tar -xvjpf CUnit-2.1-2-src.tar.bz2
  - cd CUnit-2.1-2
  - ./configure --prefix=$TRAVIS_BUILD_DIR
  - make
  - make install
  - export C_INCLUDE_PATH=$TRAVIS_BUILD_DIR/include:$C_INCLUDE_PATH
  - export LIBRARY_PATH=$TRAVIS_BUILD_DIR/lib:$LIBRARY_PATH
  - export LD_LIBRARY_PATH=$TRAVIS_BUILD_DIR/lib:$LD_LIBRARY_PATH
  - cd ..
  - cd c
```

**C++**

We download, build and install googletest, then change into our `cpp` directory:

```
before_install:
  - wget https://googletest.googlecode.com/files/gtest-1.7.0.zip
  - unzip gtest-1.7.0.zip 
  - cd gtest-1.7.0/
  - ./configure --prefix=$TRAVIS_BUILD_DIR --with-pthreads=no
  - make
  - mkdir $TRAVIS_BUILD_DIR/include/
  - cp -r include/gtest $TRAVIS_BUILD_DIR/include
  - mkdir $TRAVIS_BUILD_DIR/lib/
  - cp lib/.libs/* $TRAVIS_BUILD_DIR/lib/
  - cd ..
  - export CPLUS_INCLUDE_PATH=$TRAVIS_BUILD_DIR/include:$CPLUS_INCLUDE_PATH
  - export LIBRARY_PATH=$TRAVIS_BUILD_DIR/lib:$LIBRARY_PATH
  - export LD_LIBRARY_PATH=$TRAVIS_BUILD_DIR/lib:$LD_LIBRARY_PATH
  - cd cpp
```

**Java**

ANT is pre-installed by Travis CI, JUnit is held within our `java` directory, so all we need to do is change into our `java` directory:

```
before_install:
  - cd java
```

**PHP**

PHPUnit is pre-installed by Travis CI, so all we need to do is change into our `php` directory:

```
before_install:
  - cd php
```

**Python**

nosetests is pre-installed by Travis CI, but we will install the Python coverage package, using the Python `pip` package installer, so we can generate a code coverage report, a report on the lines of code executed by our tests. We will then change into our `python` directory:

```
before_install:
  - pip install coverage
  - cd python
```

Build and test code
-------------------

Now we are ready to run our build. We specify the build steps in a `script` entry. Certain languages have default actions they take if the `script` entry is omitted.

**C**

If there is no `script` entry then Travis CI will execute:

```
./configure && make && make test
```

As we don't have a `configure` script, we need to provide a `script` section with the commands we want to run:

```
script:
  - make test
```

**C++**

If there is no `script` entry then Travis CI will execute:

```
./configure && make && make test
```

As we don't have a `configure` script, we need to provide a `script` section with the commands we want to run:

```
script:
  - make googletest
```

**Java**

If there is no `script` entry then Travis CI will execute:

```
ant test
```

As this command will compile and run our example, we do not need to provide an explicit `script` section. However, we could provide one if we wanted to be explicit as to how our code is built and tested:

```
script:
  - ant test
```

**PHP**

If there is no `script` entry then Travis CI will execute:

```
phpunit
```
  
However, to run our PHP tests we need to provide a bootstrap value, so we need to provide a `script` section with the PHPUnit command we want to run:

```
script:
  - phpunit --bootstrap src/autoload.php --debug --coverage-text test
```

We use PHPUnit's `--debug` and `--coverage-text` flags to print out information about the tests being run and a code coverage report.

**Python**

Python needs a `script` entry to specify how to run any tests:

```
script: 
  - nosetests -v --with-coverage
```

We use nosetests `-v` and `--with-coverage` flags to print out information about the tests being run and a code coverage report.

Example `.travis.yml` files
---------------------------

Following the above examples you should have a completed `.travis.yml` file that looks like one of the following:

* C: [.travis.yml](./examples/c-travis.yml).
* C++: [.travis.yml](./examples/cpp-travis.yml).
* Java: [.travis.yml](./examples/java-travis.yml).
* PHP: [.travis.yml](./examples/php-travis.yml).
* Python: [.travis.yml](./examples/python-travis.yml).

Commit and push to trigger a new build
--------------------------------------

Now, we should commit the changes to `travis.yml` to trigger a new build:

* Commit and push changes:

```
$ git commit -m "Updated .travis.yml to configure build environment, install dependencies and build and run tests" .travis.yml
$ git push origin master
```

* Visit https://travis-ci.org/USERNAME/build_and_test_examples.
* If building C and C++ there should be a single job.
* If building Java, PHP, and Python there should be a single job with two sub-jobs, one for each version of these languages we are testing under.
* Jobs should be coloured green with a tick, indicating that they passed.
* Click on one of the jobs.
* You should see that the tests run and all passed e.g.

C:

```
$ make test
gcc -O3 -c test/fibonacci_cunit_test.c -o fibonacci_cunit_test.o -Isrc -Itest -I/home/travis/include
gcc -O3 -c src/fibonacci.c -o fibonacci.o -Isrc -Itest -I/home/travis/include
gcc -O3 -c test/cunit_test_driver.c -o cunit_test_driver.o -Isrc -Itest -I/home/travis/include
gcc -O3 -o fibonacci-tests fibonacci_cunit_test.o fibonacci.o cunit_test_driver.o -Isrc -Itest -I/home/travis/include -lcunit
./fibonacci-tests
     CUnit - A unit testing framework for C - Version 2.1-2
     http://cunit.sourceforge.net/
Suite: Fibonacci Suite
  Test: test_fibonacci_1 ...passed
  Test: test_fibonacci_2 ...passed
  Test: test_fibonacci_3 ...passed
  Test: test_fibonacci_30 ...passed
Run Summary:    Type  Total    Ran Passed Failed Inactive
              suites      1      1    n/a      0        0
               tests      4      4      4      0        0
             asserts      4      4      4      0      n/a
Elapsed time =    0.000 seconds
The command "make test" exited with 0.
Done. Your build exited with 0.
```

C++:

```
$ make googletest
c++ -c test/fibonacci_google_test.cc -o fibonacci_google_test.o -Isrc -Itest -I/home/travis/include
c++ -o fibonacci-googletests src/fibonacci.h fibonacci_google_test.o -Isrc -Itest -I/home/travis/include -lgtest -lgtest_main
./fibonacci-googletests --gtest_output="xml:TestResults.xml"
Running main() from gtest_main.cc
[==========] Running 4 tests from 1 test case.
[----------] Global test environment set-up.
[----------] 4 tests from FibonacciTest
[ RUN      ] FibonacciTest.fibonacci1
[       OK ] FibonacciTest.fibonacci1 (0 ms)
[ RUN      ] FibonacciTest.fibonacci2
[       OK ] FibonacciTest.fibonacci2 (0 ms)
[ RUN      ] FibonacciTest.fibonacci3
[       OK ] FibonacciTest.fibonacci3 (0 ms)
[ RUN      ] FibonacciTest.fibonacci30
[       OK ] FibonacciTest.fibonacci30 (6 ms)
[----------] 4 tests from FibonacciTest (6 ms total)
[----------] Global test environment tear-down
[==========] 4 tests from 1 test case ran. (6 ms total)
[  PASSED  ] 4 tests.
The command "make googletest" exited with 0.
Done. Your build exited with 0.
```

Java:

```
$ ant test
Buildfile: /home/travis/build/mikej888/build_and_test_examples/java/build.xml
init:
    [mkdir] Created dir: /home/travis/build/mikej888/build_and_test_examples/java/build
    [mkdir] Created dir: /home/travis/build/mikej888/build_and_test_examples/java/build/lib
    [mkdir] Created dir: /home/travis/build/mikej888/build_and_test_examples/java/build/classes
    [mkdir] Created dir: /home/travis/build/mikej888/build_and_test_examples/java/build/test
    [mkdir] Created dir: /home/travis/build/mikej888/build_and_test_examples/java/build/test/classes
compile:
    [javac] Compiling 1 source file to /home/travis/build/mikej888/build_and_test_examples/java/build/classes
compile-tests:
    [javac] Compiling 1 source file to /home/travis/build/mikej888/build_and_test_examples/java/build/test/classes
test:
    [mkdir] Created dir: /home/travis/build/mikej888/build_and_test_examples/java/build/test/xml
    [junit] Running math.FibonacciTest
    [junit] Testsuite: math.FibonacciTest
    [junit] Tests run: 5, Failures: 0, Errors: 0, Time elapsed: 0.11 sec
    [junit] Tests run: 5, Failures: 0, Errors: 0, Time elapsed: 0.11 sec
    [junit] 
    [junit] Testcase: testFib3 took 0.007 sec
    [junit] Testcase: testFib30 took 0.007 sec
    [junit] Testcase: testFibMinusOne took 0 sec
    [junit] Testcase: testFib1 took 0 sec
    [junit] Testcase: testFib2 took 0 sec
BUILD SUCCESSFUL
Total time: 2 seconds
The command "ant test" exited with 0.
Done. Your build exited with 0.
```

PHP:

```
$ phpunit --bootstrap src/autoload.php --debug --coverage-text test
PHPUnit 4.5.0 by Sebastian Bergmann and contributors.
Starting test 'Maths\FibonacciTest::testFib0'.
.
Starting test 'Maths\FibonacciTest::testFib1'.
.
Starting test 'Maths\FibonacciTest::testFib2'.
.
Starting test 'Maths\FibonacciTest::testFib3'.
.
Starting test 'Maths\FibonacciTest::testFib30'.
.
Time: 1.42 minutes, Memory: 10.00Mb
OK (5 tests, 5 assertions)
Code Coverage Report:     
  2015-10-01 11:23:36     
                          
 Summary:                 
  Classes: 100.00% (1/1)  
  Methods: 100.00% (1/1)  
  Lines:   100.00% (16/16)
\Maths::Fibonacci
  Methods: 100.00% ( 1/ 1)   Lines: 100.00% (  7/  7)
The command "phpunit --bootstrap src/autoload.php --debug --coverage-text test" exited with 0.
Done. Your build exited with 0.
```

Python:

```
$ nosetests -v --with-coverage
Test fibonacci(0). ... ok
Test fibonacci(1). ... ok
Test fibonacci(2). ... ok
Test fibonacci(3). ... ok
Test fibonacci(30). ... ok
Name            Stmts   Miss  Cover   Missing
---------------------------------------------
python.py           0      0   100%   
python/src.py       0      0   100%   
fibonacci.py       20     11    45%   36-37, 40-48
---------------------------------------------
TOTAL              20     11    45%   
----------------------------------------------------------------------
Ran 5 tests in 2.211s
OK
The command "nosetests -v --with-coverage" exited with 0.
Done. Your build exited with 0.
```

Further information
-------------------

For more information on Travis CI's support for the languages above, see the Travis CI pages on:

* [C](http://docs.travis-ci.com/user/languages/c/)
* [C++](http://docs.travis-ci.com/user/languages/cpp/)
* [Java](http://docs.travis-ci.com/user/languages/java/)
* [PHP](http://docs.travis-ci.com/user/languages/php/)
* [Python](http://docs.travis-ci.com/user/languages/python/)

