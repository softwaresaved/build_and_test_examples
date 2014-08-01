Create a Jenkins Python job
===========================

Jenkins can run any Python script. It can also run Python's `nosetests` and report on the success or failure of tests.

* On the Jenkins front-page, click New Item.
* Enter a name in the Item name field e.g. `Python job`.
* Select Build a free-style software project.
* Click OK.
* On the configuration page, under the Advanced Project Options heading, click Advanced ...
* Select Use custom workspace.
* Enter the directory with your shell script e.g. `/home/user/build_and_test_examples/python`.
* Scroll down the page to under the Build heading, and click Add build step and select Execute shell.
* Enter the command that runs the tests e.g.:

<p/>

    nosetests --with-xunit

* Click Save.
* On the new page that appears, click Build Now.
* You should see a new job scheduled in the Build History table.
* When it completes, the little ball should be blue indicating success.
* Click on the job link e.g. `30-Jul-2012 14:15:42`.
* The build results page for that job will appear.
* Click on Console Output and you should see the output from the command-line.
* Click Workspace and you can browse the directory in which the build commands are run.

Publish test results
--------------------

`nosetests`, with the `--with-xunit` option set, outputs test results in xUnit-compliant XML. By default, this file is called `nosetests.xml`. Jenkins can parse and present this information in a more useful way. So:

* Click Configure.
* Under the Post-build Actions heading, click Add post-build action.
* Select Publish JUnit test result report.
* In the Test report XMLs field enter location of the test report XML document name e.g. `nosetests.xml`.
* If you get a warning that `nosetests.xml doesn't match anything` you can ignore this as the file hasn't been created yet.
* Click Save.
* Click Build Now.
* When the job completes, click on the job's link in the Build History table.
* Now on the build results page for that job, there is a Test Result which should also say (no failures).
* Click on the Test Result link and you can browse the test results. These are hierarchically organised by Python module, class and function name.
* If you like, edit your code or tests so a test fails e.g. edit `src/fibonacci.py` to always return `1`.
* Now click Back to Project.
* Click Build Now.
* This time the ball in the Build History table should be red.
* Click on the job's link and then the Test Result link and you can browse to see the individual test functions that failed. Remember, too that the console output is always available via the Console Output link.
* Click Back to project then Back to dashboard. The Jenkins front-page summarises all the projects set up and the success (or failure) of the last job. Clicking on the green "run" icon for any project will run the associated job.
