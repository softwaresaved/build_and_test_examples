Configure a job to run when updates are committed to a source code repository
=============================================================================

Jenkins can be configured to detect and respond to changes made to code or files held under popular source code repositories, including Git, Mercurial, Subversion and CVS. If the code is changed, then the server can automatically spawn a new build-and-test job. This means that the software is rebuilt and tested every time the code is changed. Since the server can be remote from your own machine, it means you can continue working while the tests are under way.

Create a repository
-------------------

Create a repository based on the Python examples in `$HOME/build_and_test_examples/python`:

**Create a Git repository**

Run:

```
$ cp -r build_and_test_examples/python python-git
$ cd python-git
$ rm -rf report.xml maths/*.pyc maths/tests/*.pyc maths/tests/__pycache__ .gitignore 
$ git init
$ git config --global user.name "Your name"
$ git config --global user.email your@email.address
$ git add .
$ git commit -m "Initial import" .
```

Remove the current working files and set this repository to be a "bare" repository i.e. one with no current working copy:

```
$ rm -rf README.md maths
$ git config --bool core.bare true
```

**Create a Mercurial repository**

Create a Mercurial configuration file, `~/.hgrc` with content:

```
[ui]
username = Your name <your@email.address>
```

Run:

```
$ cp -r build_and_test_examples/python python-mercurial
$ cd python-mercurial
$ rm -rf report.xml maths/*.pyc maths/tests/*.pyc maths/tests/__pycache__ .gitignore 
$ hg init
$ hg add .
$ hg commit -m "Initial import" .
```

**Create a Subversion repository**

Run:

```
$ svnadmin create $HOME/SVNROOT
$ cp -r build_and_test_examples/python python
$ cd python/
$ rm -rf report.xml maths/*.pyc maths/tests/*.pyc maths/tests/__pycache__ .gitignore 
$ svn import file://$HOME/SVNROOT/python -m "Initial import"
```

**Create a CVS repository**

Run:

```
$ cvs -d $HOME/CVSROOT init
$ cp -r build_and_test_examples/python python
$ cd python/
$ rm -rf report.xml maths/*.pyc maths/tests/*.pyc maths/tests/__pycache__ .gitignore 
$ cvs -d $HOME/CVSROOT import -m "Initial import" python vendor-tag release-tag
```

Install plug-ins
----------------

Jenkins supports CVS and Subversion by default. To use Git and Mercurial requires additional plug-ins.

**Install the Git plug-in**

* On the Jenkins front page, click Manage Jenkins.
* Click Manage Plugins.
* Click the Available tab.
* In the Filter field, enter `git plugin`.
* Select the Install box next to Git Plugin (and not GitHub Plugin) in the table.
* Click Install without restart.

**Install the Mercurial plug-in**

* On the Jenkins front page, click Manage Jenkins.
* Click Manage Plugins.
* Click the Available tab.
* In the Filter field, enter `mercurial plugin`.
* Select the Install box next to Mercurial Plugin in the table
* Click Install without restart.

Create a Jenkins job
--------------------

* On the Jenkins front page, click New Item.
* Enter a name in the Item name field e.g. `Git job`, `Mercurial job`, `Subversion job`, `CVS job`.
* Select Freestyle software project.
* Click OK.

Check out the repository and runs tests
---------------------------------------

* On the configuration page, under Source Code Management, select your repository type e.g. Git, Mercurial, Subversion or CVS.
* For Git enter:
  - Repository URL: `file://$HOME/python-git`, replacing `$HOME` with the full path to your home directory e.g. `/home/user`.
* For Mercurial enter:
  - Repository URL: `file://$HOME/python-mercurial`, replacing `$HOME` with the full path to your home directory e.g. `/home/user`.
* For Subversion enter:
  - Repository URL: `file://$HOME/SVNROOT/python`, replacing `$HOME` with the full path to your home directory e.g. `/home/user`.
  - Local module directory (optional): `.`
* For CVS enter:
  - CVSROOT: `$HOME/CVSROOT`, replacing `$HOME` with the full path to your home directory e.g. `/home/user`.
  - Location: Head
  - Modules Remote Name: `python`
* Scroll down the page to under the Build heading.
* Click Add build step and select Execute shell.
* Enter the commands that run the tests using `py.test`:

```
py.test --junit-xml=report.xml
```

* Under the Post-build Actions heading, click Add post-build action.
* Select Publish JUnit test result report.
* In the Test report XMLs field enter the location of the test report XML file, `report.xml`.
* Click Save.
* Click Build Now.
* When the job completes, click on the job's link in the Build History table.
* Click on Console Output and you should see the commands that check the repository out.

Though we are using a local repository, Jenkins can be used with remote repositories whether these be hosted on your own servers or on a third-party service.

Jenkins provides a lot of control over what is checked out from the repository e.g. modules, directories, branches or tags, and usernames/passwords or other credentials used to authenticate with the repository etc.

Poll the repository
-------------------

We can configure Jenkins to poll the repository for changes. This can be enabled by selecting the Poll SCM option under the Build Triggers heading on the project's configuration page. This takes a "schedule" that is the same as Build periodically (see [Configure a job to run periodically](./Periodic.md)). Jobs are only triggered if updates or changes to the repository have been made since the last job run.

One problem with polling is that it is very expensive. It would be better for CVS to tell Jenkins when changes have been made and so trigger Jenkins to rerun the job. Jenkins allows us to do this.

Configure a repository to notify Jenkins of changes
---------------------------------------------------

We can configure a repository with a script that, when changes are made to the repository, pings a Jenkins URL that, in turn, triggers a Jenkins job. First, we need to tell Jenkins to be aware of changes from the repository:

* Go to the configuration page for the project.
* Scroll down to Build Triggers.
* Select Poll SCM.
* Check that the Schedule form is empty.
* Click Save.

**Configure Git**

Git has a `hooks` directory which holds a `post-commit` and `post-receive` files, which contains commands that are invoked when changes to to the repository are committed or are pushed. 

Create a `post-commit` file in your Git repository's `hooks` directory, `$HOME/python-git/.git/hooks`, or edit it if it already exists. Add:

```
#!/bin/bash
wget http://localhost:8080/git/notifyCommit?url=file://$HOME/python-git > /tmp.git.log 2>&1
exit 0
```

* If you are using a different host or port name then replace `localhost` or `8080` with these.
* See, for example, [post-commit](./examples/git-post-commit).
* Set the script to be executable:

```
$ chmod +x $HOME/python-git/.git/hooks/post-commit
```

Now, repeat the above to create a `post-receive` file, with the same contents.

* See, for example, [post-receive](./examples/git-post-receive)

**Configure Mercurial**

Mercurial has an `hgrc` file which a `hooks` section which contains commands that are invoked when changes to to the repository are committed or are pushed. 

Create an `hgrc` file in your Mercurial repository's `.hg` directory, `$HOME/python-mercurial/.hg`, or edit it if it already exists. Add:

```
[hooks]
commit.jenkins = wget -q http://localhost:8080/mercurial/notifyCommit?url=file:/
/$HOME/python-mercurial > /tmp/hg.log 2>&1
incoming.jenkins = wget -q http://localhost:8080/mercurial/notifyCommit?url=file
://$HOME/python-mercurial > /tmp/hg.log 2>&1
```

* If you are using a different host or port name then replace `localhost` or `8080` with these.
* See, for example, [hgrc](./examples/hgrc).

**Configure Subversion**

Subversion has a `hooks` directory which holds a `post-commit` file, which contains commands that are invoked when changes to to the repository are committed.

Create a `post-commit` file, in your Subversion repository's `hooks/` directory, `$HOME/SVNROOT/hooks`, or edit it if it already exists. Add:

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
 http://localhost:9090/subversion/${UUID}/notifyCommit?rev=$REV > /tmp/svn.log 2>&1
exit 0
```

* If you are using a different host or port name then replace `localhost` or `8080` with these.
* See, for example, [post-commit](./examples/svn-post-commit).
* Set the script to be executable:

```
$ chmod +x $HOME/SVNROOT/hooks/post-commit
```

**Configure CVS**

Create a script `$HOME/CVSROOT/CVSROOT/cvs-notify-jenkins.sh` to trigger the Jenkins job:

```
#!/bin/bash
wget "http://localhost:8080/job/CVS%20job/build?token=CVS-BUILD"
```

* If you are using a different host or port name then replace `localhost` or `8080` with these.
* Set this script to be executable:

```
$ chmod +x $HOME/CVSROOT/CVSROOT/cvs-notify-jenkins.sh
```
* See, for example, [cvs-notify-jenkins.sh](./examples/cvs-notify-jenkins.sh).

CVS has a `loginfo` file which contains commands that are invoked when changes to to the repository are committed.

Edit the `loginfo` file, in your Subversion repository's `CVSROOT` directory, `$HOME/SVNROOT/hooks`:

* Check out the CVS configuration files:

```
$ mkdir cvs-checkout
$ cd cvs-checkout/
$ cvs -d $HOME/CVSROOT co CVSROOT
$ cd CVSROOT
```
* Edit `loginfo` and add this line which will call the script to trigger a Jenkins job, whenever a change is commited to CVS:

```
ALL $CVSROOT/CVSROOT/cvs-notify-jenkins.sh
```

* Commit changes:

```
$ cvs commit -m "Added Jenkins notification on commit"
```

Check that a repository notifies Jenkins of changes
---------------------------------------------------

Check out the Python code:

* Using Git:

```
$ git clone file://$HOME/python-git my-python-git-clone
$ cd my-python-git-clone
```

* Using Mercurial:

```
$ hg clone file://$HOME/python-mercurial my-python-mercurial-clone
$ cd my-python-mercurial-clone
```

* Using Subversion:

```
$ mkdir $HOME/svn-checkout
$ cd $HOME/svn-checkout
$ svn co file://$HOME/$SVNROOT/python
$ cd python
```

* Using CVS:

```
$ mkdir $HOME/cvs-checkout
$ cd $HOME/cvs-checkout
$ cvs -d $HOME/CVSROOT co python
$ cd python
```

Edit `test/test_fibonacci.py` and add a new test:

```  
def test_fibonacci10(self):
    """ Test fibonacci(10). """
    self.assertEqual(55, fibonacci(10))
```

Commit the change:

* Using Git:

```
$ git commit -m "Added test_fibonacci10" test/test_fibonacci.py
$ git push origin master
```

* Using Mercurial:

```
$ hg commit -m "Added test_fibonacci10" test/test_fibonacci.py
$ hg push
```

* Using Subversion:

```
$ svn commit -m "Added test_fibonacci10" test/test_fibonacci.py
```

* Using CVS:

```
$ cvs commit -m "Added test_fibonacci10" test/test_fibonacci.py
```

In Jenkins, you should see a job being spawned and the new test being run. When the job completes:

* Click on the job's link in the Build History table. There should be a section called Changes, with information from the repository on the latest changes.
* Click on Test Result and you should see that the new test was run.
