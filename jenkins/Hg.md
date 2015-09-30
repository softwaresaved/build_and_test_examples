
Configure a job to run when updates are committed to Mercurial
==============================================================

Jenkins can be configured to detect and respond to changes made to code or files held under Mercurial. If the code is changed, then the server can automatically spawn a new build-and-test job. This means that the software is rebuilt and tested every time the code is changed. Since the server can be remote from your own machine, it means you can continue working while the tests are under way.

Create a Mercurial repository
-----------------------------

Create a Mercurial repository based on the Python examples in `$HOME/build_and_test_examples/python`:

Create a Mercurial configuration file, `~/.hgrc` with content:

```
[ui]
username = Your name <your@email.address>
```

Run:

```
$ cp -r build_and_test_examples/python python-mercurial
$ cd python-mercurial
$ rm -f nosetests.xml *.pyc */*.pyc .gitignore 
$ hg init
$ hg add .
$ hg commit -m "Initial import" .
```

Install the Mercurial plug-in
-----------------------------

To use Mercurial  requires installing a Jenkins plug-in:

* On the Jenkins front page, click Manage Jenkins.
* Click Manage Plugins.
* Click the Available tab.
* In the Filter field, enter `mercurial plugin`.
* Select the Install box next to Mercurial Plugin in the table
* Click Install without restart.

Create a job that checks out the repository and runs tests
----------------------------------------------------------

* On the Jenkins front page, click New Item.
* Enter a name in the Item name field e.g. `Mercurial job`.
* Select Freestyle software project.
* Click OK.
* On the configuration page, under Source Code Management, select Mercurial.
* Enter:
 * Repository URL: `file://$HOME/python-mercurial`, replacing `$HOME` with the full path to your home directory e.g. `/home/user`.
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

Configure a job to poll Mercurial
---------------------------

We can configure Jenkins to poll the repository for changes. This can be enabled by selecting the Poll SCM option under the Build Triggers heading on the project's configuration page. This takes a "schedule" that is the same as Build periodically (see [Configure a job to run periodically](./Periodic.md)). Jobs are only triggered if updates or changes to the repository have been made since the last job run.

One problem with polling is that it is very expensive. It would be better for Mercurial to tell Jenkins when changes have been made and so trigger Jenkins to rerun the job. Jenkins allows us to do this.

Configure Mercurial to notify Jenkins of changes
------------------------------------------

We can configure Mercurial with a script that, when changes are made to Subversion, pings a Jenkins URL that, in turn, triggers a Jenkins job:

* Go to the configuration page for the project.
* Scroll down to Build Triggers.
* Select Poll SCM.
* Check that the Schedule form is empty.
* Click Save.
* Mercurial has an `hgrc` file which a `hooks` section which contains commands that are invoked when changes to to the repository are committed or are pushed. Create an `hgrc` file, or edit it if one exists, in your Mercurial repository's `.hg` directory, `$HOME/python-mercurial/.hg`):

```
[hooks]
commit.jenkins = wget -q http://localhost:8080/mercurial/notifyCommit?url=file:/
/$HOME/python-mercurial > /tmp/hg.log 2>&1
incoming.jenkins = wget -q http://localhost:8080/mercurial/notifyCommit?url=file
://$HOME/python-mercurial > /tmp/hg.log 2>&1
```

* If you are using a different host or port name then replace `localhost` or `8080` with these.

To check the notifications work:

* Clone your Mercurial repository:

```
$ hg clone file://$HOME/python-mercurial my-python-mercurial-clone
$ cd my-python-mercurial-clone
```

* Edit `test/test_fibonacci.py` and add a new test:

```  
def test_fibonacci10(self):
    """ Test fibonacci(10). """
    self.assertEqual(55, fibonacci(10))

```
* Commit and push the change:

```
$ hg commit -m "Added test_fibonacci10" test/test_fibonacci.py
$ hg push
```

* In Jenkins, you should see a job being spawned and the new test being run.
* When the job completes, click on the job's link in the Build History table.
* There should be a section called Changes, with information from Mercurial.
* Click on Test Result and you should see that the new test was run.
