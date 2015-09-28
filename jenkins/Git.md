Configure a job to run when updates are committed to Git
========================================================

Jenkins can be configured to detect and respond to changes made to code or files held under Git. If the code is changed, then the server can automatically spawn a new build-and-test job. This means that the software is rebuilt and tested every time the code is changed. Since the server can be remote from your own machine, it means you can continue working while the tests are under way.

Create a Git repository
-----------------------

If you don't have one already, create a Git repository based on our Python examples in `$HOME/build_and_test_examples/python`:

```
$ mkdir git
$ cd git
$ cp -r $HOME/build_and_test_examples/python .
$ git init
$ git add python
$ git commit -m "Initial import"
$ rm -rf python
$ git config --bool core.bare true
```

Install the Git plug-in
-----------------------

To use Git requires installing a Jenkins plug-in:

* On the Jenkins front-page, click Manage Jenkins.
* Click Manage Plugins.
* Click the Available tab.
* In the Filter field, enter `git plugin`.
* Select the Install box next to Git Plugin (and not GitHub Plugin) in the table.
* Click Install without restart.

Create a job that checks out the repository and runs a job
----------------------------------------------------------

Now, let's create a job to check out the repository and run `nosetests`:

* On the Jenkins front-page, click New Item.
* Enter a name in the Item name field e.g. `Python Git job`.
* Select Build a free-style software project.
* Click OK.
* A configuration page will appear.
* Under Source Code Management, select Git.
* Enter:
 * Repository URL: `file:///home/user/git`. 
 * This is the URL you'd use in a `git clone` command
* Scroll down the page to under the Build heading, click Add build step and select Execute shell.
* Enter:

```
cd python
nosetests --with-xunit
```

* Click Save.
* Under the Post-build Actions heading, click Add post-build action.
* Select Publish JUnit test result report.
* In the Test report XMLs field, enter the location of the test report XML file e.g. `python/nosetests.xml`.
* Click Save.
* Click Build Now.
* When the job completes, click on the job's link in the Build History table.
* Now click on Console Output and you should see the commands that check the repository out.

Though we are using a local repository here Jenkins can be used with remote repositories whether these be hosted on your own servers or in a hosting environment such as SourceForge, GoogleCode, GitHub or BitBucket. 

Likewise, Jenkins provides a lot of control over what is checked out from the repository e.g. modules, directories, branches or tags, and usernames/passwords or other credentials used to authenticate with the repository etc

Configure a job to poll Git
---------------------------

Now we could configure the job to run periodically e.g. every 5 minutes. The checked out repository would be updated and the code rebuilt and run. 

Another option is to poll the repository which can be enabled by selecting the Poll SCM option under the Build Triggers heading on the project's configuration page. This takes a "schedule" that is the same as Build periodically (see [Configure a job to run periodically](./Periodic.md)). Jobs are only triggered if updates or changes to the repository have been made since the last job run.

One problem with polling is that it is very expensive. Ideally we want Git to tell Jenkins when changes have been made and so trigger Jenkins to rerun the job. Jenkins allows us to do this.

Configure Git to notify Jenkins of changes
------------------------------------------

We can configure Git with a script that, when Git changes, pings a Jenkins URL that, in turn, triggers a specific Jenkins job or all jobs that depend upon the repository.

* In the project configuration, select the Poll SCM option under Build Triggers. 
* Ensure that the associated Schedule form is empty.

Git has a `hooks` directory which can hold a `post-commit` and a `post-receive` file, which contains commands that are invoked when changes to to the repository are committed or are pushed. You can update this to invoke a script when anything changes as follows:

* Create a `post-commit` file, or edit it if one exists, in your Git repository's `hooks/` directory (e.g. `$HOME/git/.git/hooks`), and add:

```
#!/bin/bash
wget http://localhost:8080/git/notifyCommit?url=file://$HOME/git > /dev/null
exit 0
```

* Set this to be executable:

```
$ chmod +x $HOME/git/.git/hooks/post-commit
```

* Now, repeat the above to create, or edit, a `post-receive` file.

Check notifications work
------------------------

* Check out your Python code:

```
$ git clone file://$HOME/git git-checkout
$ cd git-checkout/python
```

* Edit `src/fibonacci.py` and change it to return `-1` always.
* Commit the change:

```
$ git commit -m "Introduced a bug" src/fibonacci.py
$ git push 
```

* In Jenkins, you should see a job being spawned which will fail, as the tests will now fail.
* Now fix the bug you introduced and, again, commit the change.
* Again, you should see a job being spawned that, this time, will pass.
