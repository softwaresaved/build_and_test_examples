Create a Jenkins shell script job
=================================

Jenkins can run any shell script and report on the success or failure depending on whether the script exits with 0, success, or non-zero, failure.

* On the Jenkins front-page, click New Item.
* Enter a name in the Item name field e.g. `Shell job`.
* Select Build a free-style software project.
* Click OK.
* On the configuration page, under the Advanced Project Options heading, click Advanced ...
* Select Use custom workspace.
* Enter the directory with your shell script e.g. `/home/user/build_and_test_examples/sh`.
* Scroll down the page to under the Build heading, and click Add build step and select Execute shell.
* Enter:

<p/>

    ./fibonacci.sh 20

* Click Save.
* On the new page that appears, click Build Now.
* You should see a new job scheduled in the Build History table.
* When it completes, the little ball should be blue indicating success.
* Click on the job link e.g. `30-Jul-2012 14:15:42`.
* The build results page for that job will appear.
* Click on Console Output and you should see the output from the command-line.
* Now, edit the configuration and remove `20` from the build step so it is just:

<p/>

    ./fibonacci.sh

* Save the configuration and click Build Now.
* Now when the job completes, there will be a little red ball next to the job link, indicating failure.

Though this is a very simple example, it demonstrates an important concept - Jenkins can run any script or set of scripts in this way. All it does is check the return values from the scripts:

* If the return value is 0 the script has succeeded, if it is non-zero the script has failed. 
* If all the scripts succeed then the job succeeds. If any script fails then the job fails.
