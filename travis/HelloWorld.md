"Hello World" with Travis CI
============================

Here, we will set up a first Travis CI job, based around a simple "hello world" example, to get you up and running with Travis CI.

Sign in to GitHub
-----------------

If you do not already have an account, then visit [GitHub](https://github.com) and create a free account.

If you already have an account, then visit [GitHub](https://github.com) and sign in.

In the following text, replace `USERNAME` with your GitHub user name.

Create a new repository on GitHub
---------------------------------

Visit https://github.com/USERNAME. 

Click **Repositories** tab.

Click **New**.

Enter Repository name: `travis-lab`

Click **Create repository**.

Clone your fork locally
-----------------------

Within a terminal window, clone your forked repository:

```
$ git clone https://USERNAME@github.com/USERNAME/travis-lab
Cloning into 'travis-lab'...
warning: You appear to have cloned an empty repository.
Checking connectivity... done.
$ cd travis-lab
```

The warning is expected. We'll now add some content.

Create a "hello world" program
------------------------------

Create a short Python script, `hello.py`, in your repository, with the content:

```
print("Hello world!")
````

Run it:

```
$ python hello.py
Hello world!
```

Add and commit this file to your repository and push the changes to GitHub:

```
$ git add hello.py
$ git commit -m "Added Python hello world script" .
$ git push origin master
```

Visit https://github.com/USERNAME/travis-lab and check that the repository now contains `hello.py`.

Sign in to Travis CI
--------------------

Once you have an account on GitHub, you can use this to sign in to Travis CI, so go to Travis CI, https://travis-ci.org/.

Click on Sign in with GitHub.

Enable your repository on Travis CI
-----------------------------------

Now, you need to tell Travis CI to check for changes in your repository, so click on your name on the top-right of the Travis CI page and select **Accounts**.

This will take you to a page, https://travis-ci.org/profile/USERNAME, which shows a list of your GitHub repositories that Travis CI knows about.

If you cannot see `USERNAME/travis-lab`, then click the **Sync account** button which tells Travis CI to check your current repositories on GitHub.

When you can see `USERNAME/travis-lab`, then click on the button next to it to instruct Travis CI to monitor that repository for changes. The X icon should change to a check/tick icon.

Create a `.travis.yml` job file
-------------------------------

Travis CI looks for a file called `.travis.yml` in a Git repository. This file tells Travis CI how to build and test your software. In addition, this file can be used to specify any dependencies you need installed before building or testing your software. So, let's add one.

Create `.travis.yml` with the content:

```
language: python

python:

  - "2.7"

script: 

  - python hello.py
```

This says we want Travis CI to set up a Python 2.7 environment, then run our hello.py script.

Add and commit this file to your repository and push the changes to GitHub:

```
$ git add .travis.yml
$ git commit -m "Added Travis CI job file" .
$ git push origin master
```

Visit https://github.com/USERNAME/travis-lab and check that the repository now contains `.travis.yml`.

Explore the Travis CI job information
-------------------------------------

Visit https://travis-ci.org/USERNAME. You should see a job called `travis-lab`. Jobs are named after the corresponding repositories.

Click on `travis-lab`.

This will take you to a page, https://travis-ci.org/USERNAME/travis-lab, which shows information about the run of your Travis CI job.

The job should be coloured green and with a check/tick icon which means that the job succeeded.

Information on your Git repository, including the commit ID and branch is also displayed i.e. the commit that triggered the job to run.

Under the **Current** tab you should see the Travis CI output from running your job. Most of the content is Travis CI-specific configuration, relating to how it configures its environment to build and test your code. Scroll to the bottom and you'll see what Travis CI does after it clones your repository:

```
$ git clone --depth=50 --branch=master https://github.com/USERNAME/travis-lab.git USERNAME/travis-lab
$ source ~/virtualenv/python2.7/bin/activate
$ python --version
Python 2.7.13
$ pip --version
pip 9.0.1 from /home/travis/virtualenv/python2.7.13/lib/python2.7/site-packages (python 2.7)
Could not locate requirements.txt. Override the install: key in your .travis.yml to install dependencies.
```

Certain lines are hidden, usually those concerned with setting up the environment for the job. Hidden lines are denoted by an arrow to the left of the line number. Click on these arrows to see the hidden lines.

At the very bottom, is the content of most interest, Travis CI's execution of our script:

```
$ python hello.py
Hello world!
The command "python hello.py" exited with 0.
Done. Your build exited with 0.
```

If a job completes with an exit code of 0 then the job is coloured green and with a check/tick icon, which means that the job succeeded.

If it completes with a non-zero exit code then the job is coloured red and with an X icon, which means that the job failed e.g. either the build failed or the tests failed.

Jobs still running are coloured yellow.

Add a `README.md` file with a build status icon
-----------------------------------------------

Each job has an associated status icon e.g. https://travis-ci.org/USERNAME/travis-lab.svg?branch=master. This can be embedded into a `README.md` file in a Git repository, so the current status of the build is always shown when viewing the Git repository via GitHub's web interface.

Create a `README.md` file e.g.:

```
# README for travis-lab

[![Build status](https://travis-ci.org/USERNAME/travis-lab.svg?master)](https://travis-ci.org/USERNAME)
```

This is MarkDown syntax and specifies a hyperlink to https://travis-ci.org/USERNAME that is rendered as an SVG image, whose source is at https://travis-ci.org/USERNAME/travis-lab.svg?master.  

Add `README.md` to your repository, commit it and push it.

As you have committed a change to your repository, this will trigger a new run of your job on Travis CI. On the page https://travis-ci.org/USERNAME/travis-lab, click **Build History**. You may see your build in progress.

Visit https://github.com/USERNAME/travis-lab and look for your icon in your `README.md` file. This feature exploits the fact that GitHub's web interface renders MarkDown-formatted files as HTML.

Explore a "real world" example
------------------------------

https://github.com/softwaresaved/recipy is a fork of recipy, https://github.com/recipy/recipy, a framework for logging provenance about the environments under which Python scripts for research are run. 

Look at its Travis CI icon at the bottom of its `README.md` file.

Look at its `.travis.yml` script at https://github.com/softwaresaved/recipy/blob/master/.travis.yml.  This is a more complex script:

* It runs under both Python 2.7 and 3.4 (`python` section).
* It does some Python version-specific configuration and installation and updates environment variables (`before_install` section).
* It installs many Python packages needed to run recipy's tests (`install` section).
* It runs the tests using py.test (`script` section). py.test is run in verbose mode (`-v`) and it is requested to show extra test information (`-r`) and to ouput to the terminal (`-s`).

Look at its Travis CI status information at https://travis-ci.org/softwaresaved/recipy, browse the output and see the download script. Note how specifying two language versions triggers two sub-jobs, one for Python 2.7 and one for Python 2.4. Note also how using the py.test flags ensures that information about individual test functions that are run is displayed within the script.

Change your code
----------------

Make changes to your `hello.py` Python script then commit your changes and push them to GitHub. Watch how Travis CI regularly triggers new jobs.

Create a Python file with some functions, and an associated test file with some unit tests. Update the `script` section of `.travis.yml` to run the tests using py.test.

