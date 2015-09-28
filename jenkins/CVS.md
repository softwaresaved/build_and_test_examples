Configure a job to run when updates are committed to CVS
========================================================

Jenkins can be configured to detect and respond to changes made to code or files held under CVS. If the code is changed, then the server can automatically spawn a new build-and-test job. This means that the software is rebuilt and tested every time the code is changed. Since the server can be remote from your own machine, it means you can continue working while the tests are under way.

Create a CVS repository
-----------------------

If you don't have one already, create a CVS repository based on our Python examples in `$HOME/build_and_test_examples/python`:

```
$ cvs -d $HOME/CVSROOT init
$ cd $HOME/build_and_test_examples/python
$ cvs -d $HOME/CVSROOT/ import -m "Initial Import" python vendor-tag release-tag
```

Create a job that checks out the repository and runs a job
----------------------------------------------------------

Now, let's create a job to check out the repository and run `nosetests`:

* On the Jenkins front-page, click New Item.
* Enter a name in the Item name field e.g. `Python CVS job`.
* Select Build a free-style software project.
* Click OK.
* A configuration page will appear.
* Under Source Code Management, select CVS.
* Enter:
 * CVSROOT: `/home/user/CVSROOT`
 * Module(s): `python`
* Scroll down the page to under the Build heading, click Add build step and select Execute shell.
* Enter:

```
nosetests --with-xunit
```

* Click Save.
* Under the Post-build Actions heading, click Add post-build action.
* Select Publish JUnit test result report.
* In the Test report XMLs field, enter the location of the test report XML file e.g. `nosetests.xml`.
* Click Save.
* Click Build Now.
* When the job completes, click on the job's link in the Build History table.
* Now click on Console Output and you should see the commands that check the repository out.

Though we are using a local repository here Jenkins can be used with remote repositories whether these be hosted on your own servers or in a hosting environment such as SourceForge, GoogleCode, GitHub or BitBucket. 

Likewise, Jenkins provides a lot of control over what is checked out from the repository e.g. modules, directories, branches or tags, and usernames/passwords or other credentials used to authenticate with the repository etc

Configure a job to poll CVS
---------------------------

Now we could configure the job to run periodically e.g. every 5 minutes. The checked out repository would be updated and the code rebuilt and run. 

Another option is to poll the repository which can be enabled by selecting the Poll SCM option under the Build Triggers heading on the project's configuration page. This takes a "schedule" that is the same as Build periodically (see [Configure a job to run periodically](./Periodic.md)). Jobs are only triggered if updates or changes to the repository have been made since the last job run.

One problem with polling is that it is very expensive. Ideally we want CVS to tell Jenkins when changes have been made and so trigger Jenkins to rerun the job. Jenkins allows us to do this.

Configure CVS to notify Jenkins of changes
------------------------------------------

We can configure CVS with a script that, when CVS changes, pings a Jenkins URL that, in turn, triggers a Jenkins job.

* In the project configuration, select the Poll SCM option under Build Triggers. 
* Ensure that the associated Schedule form is empty.

CVS has a `loginfo` file which contains commands that are invoked when changes to to the repository are committed. You can update this to invoke a script when anything changes as follows:

* Create a script `$HOME/cvs-notify-jenkins.sh` with the content:

```
#!/bin/bash
wget "http://localhost:8080/job/Python%20CVS%20job/build?token=CVS-BUILD"
```

* Set this to be executable:

```
$ chmod +x $HOME/cvs-notify-jenkins.sh
```

* Now, check out the repository configuration files:

```
$ mkdir cvs-root-checkout
$ cd cvs-root-checkout/
$ cvs -d $HOME/CVSROOT co CVSROOT
$ cd CVSROOT
```

* Edit `loginfo` and add a line:

```
ALL $HOME/cvs-notify-jenkins.sh
```

* Now commit:

```
$ cvs commit -m "Added Jenkins notification on commit"
```

Check notifications work
------------------------

* Check out your Python code:

```
$ cd $HOME
$ mkdir cvs-checkout
$ cd cvs-checkout
$ cvs -d $HOME/CVSROOT/ co python
$ cd python
```

* Edit `src/fibonacci.py` and change it to return `-1` always.
* Commit the change:

```
$ cvs commit -m "Introduced a bug" src/fibonacci.py
```

* In Jenkins, you should see a job being spawned which will fail, as the tests will now fail.
* Now fix the bug you introduced and, again, commit the change.
* Again, you should see a job being spawned that, this time, will pass.
