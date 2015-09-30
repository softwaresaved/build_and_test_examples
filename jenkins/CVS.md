Configure a job to run when updates are committed to CVS
========================================================

Jenkins can be configured to detect and respond to changes made to code or files held under CVS. If the code is changed, then the server can automatically spawn a new build-and-test job. This means that the software is rebuilt and tested every time the code is changed. Since the server can be remote from your own machine, it means you can continue working while the tests are under way.

Create a CVS repository
-----------------------

Create a CVS repository based on the Python examples in `$HOME/build_and_test_examples/python`:

```
$ cvs -d $HOME/CVSROOT init
$ cp -r build_and_test_examples/python python
$ cd python/
$ rm -f nosetests.xml *.pyc */*.pyc .gitignore 
$ cvs -d $HOME/CVSROOT import -m "Initial import" python vendor-tag release-tag

Create a job that checks out the repository and runs tests
----------------------------------------------------------

* On the Jenkins front page, click New Item.
* Enter a name in the Item name field e.g. `CVS job`.
* Select Freestyle software project.
* Click OK.
* On the configuration page, under Source Code Management, select CVS.
* Enter:
 * CVSROOT: `$HOME/CVSROOT`, replacing `$HOME` with the full path to your home directory e.g. `/home/user`.
 * Location: Head
 * Modules Remote Name: `python`
* Scroll down the page to under the Build heading.
* Click Add build step and select Execute shell.
* Enter the commands that run the tests using nosetests:

```
nosetests --with-xunit
```

* Under the Post-build Actions heading, click Add post-build action.
* Select Publish JUnit test result report.
* In the Test report XMLs field enter the location of the test report XML file, `nosetests.xml`.
* Click Save.
* Click Build Now.
* When the job completes, click on the job's link in the Build History table.
* Click on Console Output and you should see the commands that check the repository out.

Though we are using a local repository, Jenkins can be used with remote repositories whether these be hosted on your own servers or on a third-party service.

Jenkins provides a lot of control over what is checked out from the repository e.g. modules, directories, branches or tags, and usernames/passwords or other credentials used to authenticate with the repository etc.

Configure a job to poll CVS
---------------------------

We can configure Jenkins to poll the repository for changes. This can be enabled by selecting the Poll SCM option under the Build Triggers heading on the project's configuration page. This takes a "schedule" that is the same as Build periodically (see [Configure a job to run periodically](./Periodic.md)). Jobs are only triggered if updates or changes to the repository have been made since the last job run.

One problem with polling is that it is very expensive. It would be better for CVS to tell Jenkins when changes have been made and so trigger Jenkins to rerun the job. Jenkins allows us to do this.

Configure CVS to notify Jenkins of changes
------------------------------------------

We can configure CVS with a script that, when changes are made to the repository, pings a Jenkins URL that, in turn, triggers a Jenkins job:

* Go to the configuration page for the project.
* Scroll down to Build Triggers.
* Select Poll SCM.
* Check that the Schedule form is empty.
* Click Save.
* Create a script `$HOME/CVSROOT/CVSROOT/cvs-notify-jenkins.sh` to trigger our Jenkins job:

```
#!/bin/bash
wget "http://localhost:8080/job/CVS%20job/build?token=CVS-BUILD"
```

* If you are using a different host or port name then replace `localhost` or `8080` with these.
* Set this script to be executable:

```
$ chmod +x $HOME/CVSROOT/CVSROOT/cvs-notify-jenkins.sh
```

* Check out the CVS configuration files:

```
$ mkdir cvs-checkout
$ cd cvs-checkout/
$ cvs -d $HOME/CVSROOT co CVSROOT
$ cd CVSROOT
```

* CVS has a `loginfo` file which contains commands that are invoked when changes to to the repository are committed. Edit `loginfo` and add this line which will call the script to trigger a Jenkins job, whenever a change is commited to CVS:

```
ALL $CVSROOT/CVSROOT/cvs-notify-jenkins.sh
```

* Commit changes:

```
$ cvs commit -m "Added Jenkins notification on commit"
```

To check the notifications work:

* Check out the Python code:

```
$ cd $HOME/cvs-checkout
$ cvs -d $HOME/CVSROOT co python
$ cd python
```

* Edit `test/test_fibonacci.py` and add a new test:

```  
def test_fibonacci10(self):
    """ Test fibonacci(55). """
    self.assertEqual(55, fibonacci(10))

```
* Commit the change:

```
$ cvs commit -m "Added test_fibonacci10" test/test_fibonacci.py
```

* In Jenkins, you should see a job being spawned and the new test being run.
* When the job completes, click on the job's link in the Build History table.
* There should be a section called Changes, with information from CVS.
* Click on Test Result and you should see that the new test was run.
