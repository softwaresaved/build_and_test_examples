Create a Jenkins job for popular programming languages
======================================================

Jenkins can build and run C, C++, Fortran, Java, PHP and Python code, either directly or via automated build tools like Make or ANT. It can also run unit tests, for example written in CUnit, CppUnit, googletest, FRUIT, JUnit, PHPUnit or nosetests, and report on the success or failure of tests.

* On the Jenkins front page, click New Item.
* Enter a name in the Item name field e.g. one of `C job`, `Cpp job`, `Fortran job`, `Java job`, `PHP job`, `Python job`. Note that Jenkins uses the terms "project" and "job" interchangeably.
* Select Freestyle project.
* Click OK.

Build and test code
-------------------

* On the configuration page, under the Advanced Project Options heading, click Advanced...
* Select Use custom workspace.
* Enter the directory with your code e.g. one of:

```
$HOME/build_and_test_examples/c
$HOME/build_and_test_examples/cpp
$HOME/build_and_test_examples/fortran
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
