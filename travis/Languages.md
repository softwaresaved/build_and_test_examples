Create a Travis CI job for popular programming languages
========================================================

Travis CI can build and run code written in many languages, including C, C++, Fortran, Java, PHP and Python, either directly or via automated build tools like Make or ANT. It can also run unit tests, for example written in CUnit, CppUnit, googletest, FRUIT, JUnit, PHPUnit or nosetests, and report on the success or failure of tests. For example, Travis CI provides out-of-the-box support for:

* C: gcc, clang, autotools, make.
* C++: gcc, clang, autotools, make.
* Java: versions of Oracle JDK and OpenJDK, ANT, Maven, Gradle. 
* PHP: versions of PHP, PHPUnit,  XDebug.
* Python: versions of Python 2 and 3, nose, pytest and mock test libraries.
* and many other [languages](http://docs.travis-ci.com/user/languages/).

For more information, see the Travis CI pages on:

* [C](http://docs.travis-ci.com/user/languages/c/)
* [C++](http://docs.travis-ci.com/user/languages/cpp/)
* [Java](http://docs.travis-ci.com/user/languages/java/)
* [PHP](http://docs.travis-ci.com/user/languages/php/)
* [Python](http://docs.travis-ci.com/user/languages/python/)

Declare the language
--------------------

`.travis.yml` supports a `language` section which tells Travis CI which build environment it should use. Depending on the language selected, a language-specific section (e.g. `jdk`, `php` or `python`) can then be used to specify which versions of the language the job is to be run under. Travis CI will run the job for each of these versions.

* Edit `.travis.yml`, clear its current contents, and declare your language and any versions of the language you want to test.

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
  - cp -r include/gtest $TRAVIS_BUILD_DIR/include
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

We use nosetests' `-v` and `--with-coverage` flags to print out information about the tests being run and a code coverage report.

Commit, push to trigger
----------------------

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
```

C++:

```
```

Java:

```
```

PHP:

```
```

Python:

```
```

---
---
---


* On the configuration page, under the Advanced Project Options heading, click Advanced...
* Select Use custom workspace.
* Enter the directory with your code e.g. one of:

```
$HOME/build_and_test_examples/c
$HOME/build_and_test_examples/cpp
$HOME/build_and_test_examples/java
$HOME/build_and_test_examples/php
$HOME/build_and_test_examples/python
```

* Scroll down the page to under the Build heading.

For C, C++, Fortran, PHP and Python:

* Click Add build step and select Execute shell.
* Enter the commands that compile the code and tests and run the tests.
* C:

```
export C_INCLUDE_PATH=$HOME/include:$C_INCLUDE_PATH
export LIBRARY_PATH=$HOME/lib:$LIBRARY_PATH
export LD_LIBRARY_PATH=$HOME/lib:$LD_LIBRARY_PATH
make test
make xunit-report
```

* C++:

```
export CPLUS_INCLUDE_PATH=$HOME/include:$CPLUS_INCLUDE_PATH
export LIBRARY_PATH=$HOME/lib:$LIBRARY_PATH
export LD_LIBRARY_PATH=$HOME/lib:$LD_LIBRARY_PATH
make googletest
```

* Fortran:

```
make test
```

* PHP:

```
phpunit --log-junit TestResults.xml --bootstrap src/autoload.php test/FibonacciTest.php
```

* Python

```
nosetests --with-xunit
```

For Java, Jenkins has in-built support for ANT:

* Click Add build step and select Invoke ANT.
* Enter the ANT target that compiles the code and tests and runs the JUnit tests e.g.:

```
test
```

For all languages:

* Click Save.
* On the new page that appears, click Build Now.
* You should see a new job scheduled in the Build History table.
* When it completes, the little ball should be blue which means the job succeeded without errors.
* Click the job link e.g. `28-Sep-2015 14:15:42`.
* The build results page for that job will appear.
* Click Console Output and you should see the output from the command-line.
* Click Workspace and you can browse the directory in which the build commands are run.
* Click Back to Project.
* Click Back to Dashboard to see the Jenkins front page which summarises all the projects set up and the success (or failure) of the last job for each of these. Clicking on the green "run" icon will re-run the associated job.

Publish test results
--------------------

Jenkins can parse XML test results, in JUnit-compliant XML results file, and present test in a more useful, interactive way, that allows the test packages, classes, modules, classes, methods and functions to be browsed. Many test frameworks either output JUnit-compliant XML directly (e.g. googletest, FRUIT, JUnit, PHPUnit and nosetests) or in an XML format that can be converted into a JUnit-compliant XML results file (e.g. CUnit - our `make xunit-report` target does this conversion). CppUnit outputs an XML file, `TestResults.xml`, but this is not in xUnit-compliant XML format and a conversion does not, yet, exist.

To instruct Jenkins to parse these result files

* Click your job.
* Click Configure.
* Under the Post-build Actions heading, click Add post-build action.
* Select Publish JUnit test result report.
* In the Test report XMLs field. enter the location of the test report XML file e.g.
  - C:  `TestResults.xml`
  - C++ and googletest: `TestResults.xml`
  - Fortran: `result.xml`
  - Java: `build/test/xml/TESTS-TestSuites.xml`
  - PHP: `TestResults.xml`
  - Python:  `nosetests.xml`
* If you get a warning that your file `doesn't match anything` you can ignore this as the file hasn't been created yet.
* Click Save.
* Click Build Now.
* When the job completes, click the job's link in the Build History table.
* Now on the build results page for that job, there is a Test Result link which should also say (no failures).
* Click the Test Result link and you can browse the test results. These are hierarchically organised by:
  - C: C source file and function name.
  - C++: source file and function name. 
  - Fortran: source file and function name.
  - Java: package, class and method name.
  - PHP: file, class and function name.
  - Python: package, class and function name.

How Jenkins behaves when there are errors
-----------------------------------------

* Edit your code or tests so a test fails e.g. edit edit the Fibonacci function to always return `1` by updating:
  - C: `src/fibonacci.c`
  - C++: `src/fibonacci.h`
  - Fortran: `src/fibonacci.f90`
  - Java: `src/math/Fibonacci.java`
  - PHP: `src/Fibonacci.php`
  - Python: `src/fibonacci.py`





* Click Back to Project.
* Click Build Now.

* This time the ball in the Build History table should be one of yellow or red.
  - C, Fortran and Java will show as yellow.  Yellow means the build is unstable. Jenkins [defines](https://wiki.jenkins-ci.org/display/JENKINS/Terminology) a build as unstable if it was built successfully but a test result publisher has noted that a test has failed. This is because CUnit, FRUIT, and JUnit (invoked via ANT's `junit` task) returns an exit code of `0`, indicating success, Jenkins executes the post-build action to parse the test results file and so detects the test failures.
  - C++, PHP and Python will show as red. This means the build failed. This is because googletest, PHPUnit and nosetests return an exit code of `1` if any test fails. 
* Click the job link.
* Click the Test Result link and you can browse to see the individual test functions that failed. Remember, too that the console output is always available via the Console Output link.
* Click Back to project then Back to dashboard.





Further information
-------------------

For more information on Travis CI's support for Java, see [Building a Java Project](http://docs.travis-ci.com/user/languages/java/).


For more information on Travis CI's support for Python, see [Building a Python Project](http://docs.travis-ci.com/user/languages/python/).
