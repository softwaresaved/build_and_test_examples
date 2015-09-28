Create a Jenkins Python job
===========================

Jenkins can run Python scripts. It can also run unit tests, for example, via nosetests, and report on the success or failure of tests.

* On the Jenkins front page, click New Item.
* Enter a name in the Item name field e.g. `Python job`. Note that Jenkins uses the terms "project" and "job" interchangeably.
* Select Freestyle project.
* Click OK.
* On the configuration page, under the Advanced Project Options heading, click Advanced...
* Select Use custom workspace.
* Enter the directory with your Python scripts e.g. `$HOME/build_and_test_examples/python`.
* Scroll down the page to under the Build heading.
* Click Add build step and select Execute shell.
* Enter the commands that run the tests using nosetests:

```
nosetests
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

Python unit tests run using nosetests output an XML file in an xUnit-compliant format. By default, this file is called  `nosetests.xml`. Jenkins can publish XML test results, in xUnit-compliant XML. Jenkins can then parse and present this information in a more useful way. So:

* Click Python job.
* Click Configure.
* In the Execute shell commands, replace the line:

```
nosetests
```

* with the following line, to tell nosetests to create an xUnit-compliant test report:

```
nosetests --with-xunit
```

* Under the Post-build Actions heading, click Add post-build action.
* Select Publish JUnit test result report.
* In the Test report XMLs field enter location of the test report XML document name e.g. `nosetests.xml`.
* If you get a warning that `nosetests.xml doesn't match anything` you can ignore this as the file hasn't been created yet.
* Click Save.
* Click Build Now.
* When the job completes, click on the job's link in the Build History table.
* Now on the build results page for that job, there is a Test Result link which should also say (no failures).
* Click on the Test Result link and you can browse the test results. These are hierarchically organised by Python package, class and function name.

How Jenkins behaves when there are errors
-----------------------------------------

* Edit your scripts or tests so a test fails e.g. edit `src/fibonacci.py` to always return `1`.
* Click Back to Project.
* Click Build Now.
* This time the ball in the Build History table should be red. This means the build failed. This is because nosetests returns an exit code of 1 when the tests fail. 
* Click on the job's link and then the Test Result link and you can browse to see the individual test functions that failed. Remember, too that the console output is always available via the Console Output link.
