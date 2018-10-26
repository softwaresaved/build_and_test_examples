Create a Jenkins shell script job
=================================

Jenkins can run any shell script and report on the success or failure depending on whether the script exits with 0, for success, or non-zero, for failure.

* On the Jenkins front page, click New Item.
* Enter a name in the Item name field e.g. `Shell job`. Note that Jenkins uses the terms "project" and "job" interchangeably.
* Select Freestyle project.
* Click OK.
* On the configuration page, under the Advanced Project Options heading, click Advanced...
* Select Use custom workspace.
* Enter the directory with your shell script e.g. `$HOME/build_and_test_examples/sh`.
* Scroll down the page to under the Build heading. 
* Click Add build step and select Execute shell.
* Enter:

```
./fibonacci.sh 20
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
* Click Back to Dashboard to see the Jenkins fromt page which summarises all the projects set up and the success (or failure) of the last job for each of these. Clicking on the green arrow "run" icon will re-run the associated job.

How Jenkins behaves when there are errors
-----------------------------------------

* Click Shell job.
* Click Configure.
* Edit the configuration and remove `20` from the build step so it is just:

```
./fibonacci.sh
```

* Save the configuration and click Build Now.
* Now when the job completes, there will be a little red ball next to the job link, which means the job failed with an error.
* Click the job link.
* Click Console Output and you should see the output from the command-line, including the reason for the failure.
* Click Back to project then Back to dashboard.

Summary
-------

Though this is a very simple example, it demonstrates an important concept - Jenkins can run any script or set of scripts in this way. All Jenkins does is check the return values from the scripts:

* If the return value is 0 the script has succeeded, if it is non-zero the script has failed. 
* If all the scripts succeed then the job succeeds. If any script fails then the job fails.
