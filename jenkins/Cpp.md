Create a Jenkins C++ job
========================

Jenkins can build and run C++ code, either directly or via Make. It can also run unit tests, for example written in CppUnit or googletest, again directly or via Make, and report on the success or failure of tests.

* On the Jenkins front page, click New Item.
* Enter a name in the Item name field e.g. `Cpp job`. Note that Jenkins uses the terms "project" and "job" interchangeably.
* Select Freestyle project.
* Click OK.
* On the configuration page, under the Advanced Project Options heading, click Advanced...
* Select Use custom workspace.
* Enter the directory with your C++ code e.g. `$HOME/build_and_test_examples/cpp`.
* Scroll down the page to under the Build heading.
* Click Add build step and select Execute shell.
* Enter the commands that compile the code and tests and run the CppUnit tests e.g.:

```
export CPLUS_INCLUDE_PATH=$HOME/include:$CPLUS_INCLUDE_PATH
export LIBRARY_PATH=$HOME/lib:$LIBRARY_PATH
export LD_LIBRARY_PATH=$HOME/lib:$LD_LIBRARY_PATH
make test
```

* This sets paths to include the locations of CppUnit and googletest include files and libraries.
* Click Save.
* On the new page that appears, click Build Now.
* You should see a new job scheduled in the Build History table.
* When it completes, the little ball should be blue which means the job succeeded without errors.
* Click the job link e.g. `28-Sep-2015 14:15:42`.
* The build results page for that job will appear.
* Click Console Output and you should see the output from the command-line.
* Click Workspace and you can browse the directory in which the build commands are run.
* Click Back to Project.
* Click Back to Dashboard to see the Jenkins fromt page which summarises all the projects set up and the success (or failure) of the last job for each of these. Clicking on the green "run" icon will re-run the associated job.

How Jenkins behaves when there are errors
-----------------------------------------

* Edit your code or tests so a test fails e.g. edit `src/fibonacci.h` to always return `1`.
* Click the green *run* icon by Cpp job.
* This time the ball in the Build History table should be red. This means the build failed. This is because CppUnit returns an exit code of 1 when the tests fail. 
* Click the job link.
* Click Console Output and you should see the output from the command-line, including the reason for the failure.

Publish test results
--------------------

CppUnit outputs an XML file, `TestResults.xml`, but this is not in xUnit-compliant XML format so cannot be parsed and presented by Jenkins in this way.

However, googletest does output an XML file in an xUnit-compliant format. By default, this file is called `TestResults.xml`. Jenkins can publish XML test results, in xUnit-compliant XML. Jenkins can then parse and present this information in a more useful way. So:

* Click Back to Project.
* Click Configure.
* In the Execute shell commands, replace the line:

```
make test
```

* with the following line, to build and run the code and googletest unit tests:

```
make googletest
```

* Under the Post-build Actions heading, click Add post-build action.
* Select Publish JUnit test result report.
* In the Test report XMLs field, enter the location of the test report XML file e.g. `TestResults.xml`.
* If you get a warning that `TestResults.xml doesn't match anything` you can ignore this as the file hasn't been created yet.
* Click Save.
* Click Build Now.
* When the job completes, click on the job's link in the Build History table.
* Now on the build results page for that job, there is a Test Result link which should also say (no failures).
* Click on the Test Result link and you can browse the test results. These are hierarchically organised by C++ source file and function name.

How Jenkins behaves when there are errors
-----------------------------------------

* Edit your code or tests so a test fails e.g. edit `src/fibonacci.h` to always return `1`.
* Click Back to Project.
* Click Build Now.
* This time the ball in the Build History table should be red. This means the build failed. This is because googletest returns an exit code of 1 when the tests fail. 
* Click on the job's link and then the Test Result link and you can browse to see the individual test functions that failed. Remember, too that the console output is always available via the Console Output link.
* Click Back to project then Back to dashboard.
