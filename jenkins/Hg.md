Configure a job to run when updates are committed to Mercurial
==============================================================

Jenkins can be configured to detect and respond to changes made to code or files held under Mercurial. If the code is changed, then the server can automatically spawn a new build-and-test job. This means that the software is rebuilt and tested every time the code is changed. Since the server can be remote from your own machine, it means you can continue working while the tests are under way.

Create a Mercurial repository
-----------------------------

If you don't have one already, create a Mercurial repository based on our Python examples in `/home/user/build_and_test_examples/python`:

```
$ mkdir mercurial
$ cd mercurial
$ cp -r /home/user/build_and_test_examples/python .
$ hg init
$ hg add python
$ hg commit -m "Initial import"
```

Install the Mercurial plug-in
-----------------------------

To use Mercurial  requires installing a Jenkins plug-in:

* On the Jenkins front-page, click Manage Jenkins.
* Click Manage Plugins.
* Click the Available tab.
* In the Filter field, enter `mercurial plugin`.
* Select the Install box next to Mercurial Plugin in the table
* Click Install without restart.

Create a job that checks out the repository and runs a job
----------------------------------------------------------

Now, let's create a job to check out the repository and run `nosetests`:

* On the Jenkins front-page, click New Item.
* Enter a name in the Item name field e.g. `Python Mercurial job`.
* Select Build a free-style software project.
* Click OK.
* A configuration page will appear.
* Under Source Code Management, select Mercurial.
* Enter:
 * Repository URL: `file:///home/user/mercurial`. 
 * This is the URL you'd use in a `hg clone` command
* Scroll down the page to under the Build heading, click Add build step and select Execute shell.
* Enter:

```
cd python
nosetests --with-xunit
```

* Click Save.
* Under the Post-build Actions heading, click Add post-build action.
* Select Publish JUnit test result report.
* In the Test report XMLs field enter location of the test report XML document name e.g. `python/nosetests.xml`.
* Click Save.
* Click Build Now.
* When the job completes, click on the job's link in the Build History table.
* Now click on Console Output and you should see the commands that check the repository out.

Though we are using a local repository here Jenkins can be used with remote repositories whether these be hosted on your own servers or in a hosting environment such as SourceForge, GoogleCode, GitHub or BitBucket. 

Likewise, Jenkins provides a lot of control over what is checked out from the repository e.g. modules, directories, branches or tags, and usernames/passwords or other credentials used to authenticate with the repository etc

Configure a job to poll Mercurial
---------------------------------

Now we could configure the job to run periodically e.g. every 5 minutes. The checked out repository would be updated and the code rebuilt and run. 

Another option is to poll the repository which can be enabled by selecting the Poll SCM option under the Build Triggers heading on the project's configuration page. This takes a "schedule" that is the same as Build periodically (see [Configure a job to run periodically](./Periodic.md)). Jobs are only triggered if updates or changes to the repository have been made since the last job run.

One problem with polling is that it is very expensive. Ideally we want Mercurial to tell Jenkins when changes have been made and so trigger Jenkins to rerun the job. Jenkins allows us to do this.

Configure Mercurial to notify Jenkins of changes
------------------------------------------------

We can configure Mercurial with a script that, when Mercurial changes, pings a Jenkins URL that, in turn, triggers a specific Jenkins job or all jobs that depend upon the repository.

* In the project configuration, select the Poll SCM option under Build Triggers. 
* Ensure that the associated Schedule form is empty.

Mercurial has an `hgrc` file with a `hooks` section which contains commands that are invoked when changes to to the repository are committed. You can update this to invoke a script when anything changes as follows:

 * Create an `hgrc` file, or edit it if one exists, in your Mercurial repository's `.hg` directory (e.g. `/home/user/mercurial/.hg`), and add:

```
[hooks]
commit.jenkins = wget -q http://localhost:8080/mercurial/notifyCommit?url=file:///home/user/mercurial > /dev/null
incoming.jenkins = wget -q http://localhost:8080/mercurial/notifyCommit?url=file:///home/user/mercurial > /dev/null
```

Check notifications work
------------------------

* Check out your Python code:

```
$ hg clone file:///home/user/mercurial mercurial-checkout
$ cd mercurial-checkout/python
```

* Edit `src/fibonacci.py` and change it to return `-1` always.
* Commit the change:

```
$ hg commit -m "Introduced a bug" src/fibonacci.py
$ hg push 
```

* In Jenkins, you should see a job being spawned which will fail, as the tests will now fail.
* Now fix the bug you introduced and, again, commit the change.
* Again, you should see a job being spawned that, this time, will pass.
