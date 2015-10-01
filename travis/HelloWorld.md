"Hello World" with Travis CI
============================

Here, we will set up a first Travis CI job, based around a simple "hello world" example, to get you up and running with Travis CI.

Sign in to GitHub
-----------------

If you do not already have an account, then visit [GitHub](https://github.com) and create a free account.

If you already have an account, then visit [GitHub](https://github.com) and sign in.

In the following text, replace `USERNAME` with your GitHub user name.

Fork this repository on GitHub
------------------------------

* Visit https://github.com/softwaresaved/build_and_test_examples.
* Click Fork.
* If asked "Where should we fork this repository?", select your account.

Sign in to Travis CI
--------------------

Once you have an account on GitHub, you can use this to sign in to Travis CI:

* Visit [Travis CI](https://travis-ci.org).
* Click on Sign in with GitHub.

Enable your repository on Travis CI
-----------------------------------

Now, tell Travis CI to check for changes in your repository:

* Click on your name on the top-right of the Travis CI page.
* This page shows a list of your GitHub repositories that Travis CI knows about.
* If you cannot see `USERNAME/build_and_test_examples`, then click the Sync button.
* Once you can see `USERNAME/build_and_test_examples`, then click on the repository switch (the X button) so that Travis CI knows to check that repository for changes.

Clone your fork locally
-----------------------

* Within a command-line shell, clone your fork:

```
$ git clone https://github.com/USERNAME/build_and_test_examples
$ cd build_and_test_examples
```

Create a "hello world" `.travis.yml` job file
---------------------------------------------

Travis CI looks for a file called `.travis.yml` in a Git repository. This file tells Travis CI how to build and test your software. In addition, this file can be used to specify any dependencies you need installed before building or testing your software. So, let's try a simple example:

* Create a short Python script, `hello.py` in your repository, with the content:

```
print("Hello world from Travis CI")
```

* Create `.travis.yml`, with the content:

```
language: python

python:
  - "2.7"

script: 
  - python hello.py
```

* This says we want Travis CI to set up a Python 2.7 environment, then run our `hello.py` script.
* Add and commit these files to your repository and push the changes to GitHub:

```
$ git add hello.py .travis.yml
$ git commit -m "Python hello world script and Travis CI job file" .
$ git push origin master
```

Explore the Travis CI job information
-------------------------------------

Travis CI provides a page summarising the most recent jobs run for your repositories:

* Visit https://travis-ci.org/USERNAME.
* You should see a job called `build_and_test_examples` - jobs are named after the corresponding repositories.
* The job should be coloured green and with a tick mark meaning the build succeeded.
* Click on this job.

For each repository it knows about, Travis CI provides a page summarising information about the jobs that have been run for that repository, including information on the current build and the build history:

* The summary page has a URL of the form `https://travis-ci.org/USERNAME/JOB` e.g. https://travis-ci.org/trungdong/prov.
* An icon shows the current status of the build. This has a URL of form `https://travis-ci.org/USERNAME/JOB.svg` e.g. https://travis-ci.org/trungdong/prov.svg. The status image is often embedded into other web pages, for example, README files in GitHub (for example, see https://github.com/trungdong/prov/blob/master/README.rst).
* By default, information on the Current build is shown, including the log created by Travis CI as it ran this job.
* The important part of our first `.travis.yml` file are the lines which ran our script:

```
$ python hello.py
Hello world from Travis CI

The command "python hello.py" exited with 0.

Done. Your build exited with 0.
```

* If any command were to exit with a non-zero result then Travis CI would consider the build to have failed, it would be coloured red and marked with a cross in the jobs summary page.
* Certain lines are hidden, usually those concerned with setting up the environment for the job. Hidden lines are denoted by an arrow to the left of the line number. Click on these arrows to see the hidden lines.
