Create a Jenkins Java job
============================

Jenkins can build and run Java code, either directly or via ANT. It can also run unit tests, for example written in FRUIT, again directly or via ANT, and report on the success or failure of tests.

* On the Jenkins front page, click New Item.
* Enter a name in the Item name field e.g. `Java job`. Note that Jenkins uses the terms "project" and "job" interchangeably.
* Select Freestyle project.
* Click OK.
* On the configuration page, under the Advanced Project Options heading, click Advanced...
* Select Use custom workspace.
* Enter the directory with your Java code e.g. `$HOME/build_and_test_examples/fortran`.
* Scroll down the page to under the Build heading.
* Click Add build step and select Invoke ANT.
* Enter the ANT target that compiles the code and tests and runs the JUnit tests e.g.:

```
test
```

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

Publish test results
--------------------

Java unit tests written using JUnit, and invoked via ANT (using ANT's `junit` and `junitreport` tasks) can output an XML file in an xUnit-compliant format. By default this file is called `TESTS-TestSuites.xml`. Jenkins can parse and present this information in a more useful way. So:

* Click Java job.
* Click Configure.
* Under the Post-build Actions heading, click Add post-build action.
* Select Publish JUnit test result report.
* In the Test report XMLs field enter the location of the test report XML file e.g. `build/test/xml/TESTS-TestSuites.xml`.
* If you get a warning that `build/test/xml/TESTS-TestSuites.xml doesn't match anything` you can ignore this as the file hasn't been created yet.
* Click Save.
* Click Build Now.
* When the job completes, click on the job's link in the Build History table.
* Now on the build results page for that job, there is a Test Result link which should also say (no failures).
* Click on the Test Result link and you can browse the test results. These are hierarchically organised by Java packge, class and method name.

How Jenkins behaves when there are errors
-----------------------------------------

* Edit your code or tests so a test fails e.g. edit `src/math/Fibonacci.java` to always return `1`.
* Click Back to Project.
* Click Build Now.
* This time the ball in the Build History table should be yellow. This means the build is unstable. Jenkins [defines](https://wiki.jenkins-ci.org/display/JENKINS/Terminology) a build as unstable if it was built successfully but a test result publisher has noted that a test has failed. While ANT's `junit` task returns an exit code of 0, indicating success, Jenkins executes our post-build action to parse the test results file and so detects the test failures.
* Click on the job's link and then the Test Result link and you can browse to see the individual test functions that failed. Remember, too that the console output is always available via the Console Output link.
