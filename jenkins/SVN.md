Configure a job to run when updates are committed to Subversion
===============================================================

Jenkins can be configured to detect and respond to changes made to code or files held under Subversion. If the code is changed, then the server can automatically spawn a new build-and-test job. This means that the software is rebuilt and tested every time the code is changed. Since the server can be remote from your own machine, it means you can continue working while the tests are under way.

Create a Subversion repository
------------------------------

If you don't have one already, create a Subversion repository based on our Python examples in `$HOME/build_and_test_examples/python`:

```
$ svnadmin create $HOME/SVNROOT
$ cp -r build_and_test_examples/python python
$ cd python/
$ rm -f nosetests.xml *.pyc */*.pyc .gitignore 
$ svn import file://$HOME/SVNROOT/example -m "Initial import"
```

Create a job that checks out the repository and runs a job
----------------------------------------------------------

Now, let's create a job to check out the repository and run `nosetests`:

* On the Jenkins front page, click New Item.
* Enter a name in the Item name field e.g. `SVN job`.
* Select Freestyle software project.
* Click OK.
* On the configuration page, under Source Code Management, select Subversion.
* Enter:
 * Repository URL: `file://$HOME/SVNROOT/example`
 * Local module directory (optional): `.`
* Scroll down the page to under the Build heading.
* Click Add build step and select Execute shell.
* Enter the commands that run the tests using nosetests:

```
nosetests --with-xunit
```

* Under the Post-build Actions heading, click Add post-build action.
* Select Publish JUnit test result report.
* In the Test report XMLs field enter the location of the test report XML file e.g. `nosetests.xml`.
* If you get a warning that `nosetests.xml doesn't match anything` you can ignore this as the file hasn't been created yet.
* Click Save.
* Click Build Now.
* When the job completes, click on the job's link in the Build History table.
* Click on Console Output and you should see the commands that check the repository out.

Though we are using a local repository, Jenkins can be used with remote repositories whether these be hosted on your own servers or on a third-party service.

Jenkins provides a lot of control over what is checked out from the repository e.g. modules, directories, branches or tags, and usernames/passwords or other credentials used to authenticate with the repository etc.

Configure a job to poll Subversion - TODO
----------------------------------

Now we could configure the job to run periodically e.g. every 5 minutes. The checked out repository would be updated and the code rebuilt and run. 

Another option is to poll the repository which can be enabled by selecting the Poll SCM option under the Build Triggers heading on the project's configuration page. This takes a "schedule" that is the same as Build periodically (see [Configure a job to run periodically](./Periodic.md)). Jobs are only triggered if updates or changes to the repository have been made since the last job run.

One problem with polling is that it is very expensive. Ideally we want Subversion to tell Jenkins when changes have been made and so trigger Jenkins to rerun the job. Jenkins allows us to do this.

Configure Subversion to notify Jenkins of changes
-------------------------------------------------

We can configure Subversion with a script that, when Subversion changes, pings a Jenkins URL that, in turn, triggers a specific Jenkins job or all jobs that depend upon the repository.

* In the project configuration, select the Poll SCM option under Build Triggers. 
* Ensure that the associated Schedule form is empty.

Subversion has a `hooks` directory which can hold a `post-commit` file, which contains commands that are invoked when changes to to the repository are committed. You can update this to invoke a script when anything changes as follows:

 * Create a `post-commit` file, or edit it if one exists, in your Subversion repository's `hooks/` directory (e.g. `$HOME/svn-repository/hooks`), and add:

```
#!/bin/bash
REPOS="$1"
REV="$2"
UUID=`svnlook uuid $REPOS`
wget \
 --header "Content-Type:text/plain;charset=UTF-8" \
 --post-data "`svnlook changed --revision $REV $REPOS`" \
 --output-document "-" \
 --timeout=2 \
 http://localhost:8080/subversion/${UUID}/notifyCommit?rev=$REV 
exit 0
```

* Set this to be executable:

```
$ chmod +x $HOME/svn-repository/hooks/post-commit
```

Check notifications work
------------------------

* Check out your Python code:

```
$ mkdir svn-checkout
$ cd svn-checkout
$ svn co file://$HOME/svn-repository/python
$ cd python
```

* Edit `src/fibonacci.py` and change it to return `-1` always.
* Commit the change:

```
$ svn commit -m "Introduced a bug" src/fibonacci.py
```

* In Jenkins, you should see a job being spawned which will fail, as the tests will now fail.
* Now fix the bug you introduced and, again, commit the change.
* Again, you should see a job being spawned that, this time, will pass.
