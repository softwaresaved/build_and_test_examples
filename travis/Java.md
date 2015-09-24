Create a Travis CI Java job
=============================

Travis CI supports testing Python code under various versions of Java e.g. Oracle JDK 7 and 8 and Open JDK 6 and 7. It also provides ANT, Maven and Gradle.

Updaye `.travis.yml` to run tests of Python Fibonnaci series code
-----------------------------------------------------------------

The [java](./java) directory contains a Java implementation of the Fibonacci series function and tests for this function. We can customise our `.travis.yml` job to run these tests under both Oracle JDK 8 and Open JDK 7 as follows.

* Open `.travis.yml` in an editor.
* Update its contents to be:

```
language: java

jdk:
  - oraclejdk8
  - openjdk7

before_install:
  - cd java
```

* `language` tells Travis CI which build environment we wish.
* `jdk` tells Travis CI which versions of Java we want to run this job under. Here, we request that Travis CI runs the job twice, once under Oracle JDK 8 and once under Open JDK 7.
* `script` tells Travis CI to change into the `java` directory then TODO TODO TODO to run all the tests it can find.

TODO

* `ant test` by default.

TODO

* Commit these changes your repository and push the changes to GitHub:

```
$ git commit -m "Updated .travis.yml to run Fibonacci tests in python/ under both Python 2.7 and 3.4" .travis.yml
$ git push origin master
```

* Visit https://travis-ci.org/USERNAME/build_and_test_examples.
* There will be two jobs for this job - one for each version of Java.
* Both jobs should be coloured green with a tick, indicating that they passed.
* Click on one of the jobs.
* You should see that the tests run and all passed e.g.

```
test:
    [junit] Running math.FibonacciTest
    [junit] Tests run: 5, Failures: 0, Errors: 0, Time elapsed: 0.121 sec
...
BUILD SUCCESSFUL
Total time: 3 seconds
The command "ant test" exited with 0.
```

* Now, go back and click on the Python 3.4 job:
* You should see that there was an error:

```
ERROR: Failure: SyntaxError (Missing parentheses in call to 'print' (fibonacci.py, line 36))
```

* This is because the Python code is not compatible with Python 3.4. Python 3.4 expects the arguments to its `print` command to be surrounded by parentheses.

Introduce a bug
---------------

* Open `python/src/fibonacci.py` in an editor.
* Add parentheses to the three `print` lines:

```
print("Usage: python fibonacci.py N")
print("  where N >= 0")
print("fibonacci(%d) = %d" % (n, fib))
```

* Commit these changes your repository and push the changes to GitHub.
* Look at your Travis CI job page.
* This time both the Python 2.7 and Python 3.4 tests should have passed.
* Click on the Python 3.4 job. 
* You should see that the tests run and all passed e.g.

```
Test fibonacci(0). ... ok
Test fibonacci(1). ... ok
Test fibonacci(2). ... ok
Test fibonacci(3). ... ok
Test fibonacci(30). ... ok
----------------------------------------------------------------------
Ran 5 tests in 0.717s
OK
```

Installing a package
--------------------

Suppose we want to generate a test coverage report - a report on the statements in our Fibonacci series implementation that were executed by our tests. `nosetests` supports a `--with-coverage` command-line option to generate this report, but this needs the Python `coverage` package to have been installed.

We can request that Travis CI install this package by adding a `before_install` section to `.travis.yml`:

* Add the following section after the `python` section:

```
before_install:
  - pip install coverage
```

* This installs the `coverage` package using Python's `pip` package installer. Note that `.travis.yml` also supports an `install` section, which contains steps that are executed after those in `before_install`. In this example, we could put our `pip` command in either section.
* Update the call to `nosetests` to generate a test coverage report:

```
  - nosetests -v --nocapture --with-coverage
```

* Commit these changes your repository and push the changes to GitHub.
* Travis CI should rerun the job, and in the logs you should see both the installation of `coverage` and a test coverage report:

```
$ pip install coverage
```

```
Name            Stmts   Miss  Cover   Missing
---------------------------------------------
python.py           0      0   100%   
python/src.py       0      0   100%   
fibonacci.py       20     11    45%   36-37, 40-48
---------------------------------------------
TOTAL              20     11    45%   
```

Further information
-------------------

For more information on Travis CI's support for Java, see [Building a Java Project](http://docs.travis-ci.com/user/languages/java/).



ant runTests
Java JUnit tests, when invoked from ANT (via the ANT `junit` task) can output test results in xUnit-compliant XML. By default this file is called `TESTS-TestSuites.xml`. Jenkins can parse and present this information in a more useful way. So:

* Click Configure.
* Under the Post-build Actions heading, click Add post-build action.
* Select Publish JUnit test result report.
* In the Test report XMLs field enter location of the test report XML document name e.g. `build/test-xml/TESTS-TestSuites.xml`.
* If you get a warning that `build/test-xml/TESTS-TestSuites.xml doesn't match anything` you can ignore this as the file hasn't been created yet.
* Click Save.
* Click Build Now.
* When the job completes, click on the job's link in the Build History table.
* Now on the build results page for that job, there is a Test Result which should also say (no failures).
* Click on the Test Result link and you can browse the test results. These are hierarchically organised by Java package, class and method name.

* If you like, edit your code or tests so a test fails e.g. edit `src/math/Fibonacci.java` to always return `1`.

