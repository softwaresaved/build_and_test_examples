Getting started with Travis CI
==============================

[Travis CI](https://travis-ci.org/) is a hosted [continuous integration](http://en.wikipedia.org/wiki/Continuous_Integration) service, which provides automated build-and-test services for projects hosted on [GitHub](https://github.com). The service is free for open source projects.

Travis CI detects and responds to changes made to code or files held within Git repositories on GitHub. If the code is changed, by a commit, then Travis CI automatically runs a build-and-test job for that repository. This means that the software is rebuilt and tested every time changes to the code are pushed to GitHub. Since Travis CI is remote from your own machine, it means you can continue working while the tests are under way. It also means you do not have to set up a machine for testing locally, which can be useful if you are don't have the funding, hardware or time to set this up yourself.

In these pages we provide an introduction to Travis CI and how it can be used to automate the building and testing of software, triggered by changes commited to Git repositories hosted on GitHub.

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

Create a first `.travis.yml` job file
-------------------------------------

Travis CI looks for a file called `.travis.yml` in a Git repository. This file tells Travis CI how to build and test your software. In addition, this file can be used to specify any dependencies you need installed before building or testing your software. So, let's try a simple example:

* Create a short Python test script, `test_hello.py` in your repository, with the content:

```
def test_hello():
    print("Hello from Travis CI")
```

* Create `.travis.yml`, with the content:

```
language: python

python:
  - "2.6"

script: 
  - nosetests --nocapture test_hello.py
```

* This says we want Travis CI to set up a Python 2.6 environment then run our `test_hello.py` script using Python's `nosetests` test runner (`--nocapture` tells `nosetests` to display anything that is printed by the tests it runs, in this case our `Hello...` message).
* Add and commit these files to your repository and push the changes to GitHub:

```
$ git add test_hello.py .travis.yml
$ git commit -m "Python test script and Travis CI job file" .
$ git push origin master
```

Explore the Travis CI job information
-------------------------------------

Travis CI provides a page summarising the most recent test jobs run for your repositories:

* Visit https://travis-ci.org/USERNAME.
* You should see a job called `build_and_test_examples` which should be coloured green and with a tick mark meaning the test passed.
* Click on this job.

For each repository it knows about, Travis CI provides a page summarising information about the test jobs that have been run for that repository, including information on the current build and the build history:

* The summary page has a URL of the form `https://travis-ci.org/USERNAME/REPOSITORY` e.g. https://travis-ci.org/trungdong/prov.
* An icon shows the current status of the build. This has a URL of form `https://travis-ci.org/USERNAME/REPOSITORY.svg` e.g. https://travis-ci.org/trungdong/prov.svg. The status image is often embedded into other web pages, for example, README files in GitHub (for example, see https://github.com/trungdong/prov/blob/master/README.rst).
* By default, information on the Current build is shown, including the log created by Travis CI as it ran this job.
* The important part of our first `.travis.yml` file are the lines which ran our test:

```
$ nosetests --nocapture test_hello.py
Hello from Travis CI
.
----------------------------------------------------------------------
Ran 1 test in 0.003s
OK
The command "nosetests --nocapture test_hello.py" exited with 0.
Done. Your build exited with 0.
```

* If any command were to exit with a non-zero result (as `nosetests` does if a Python test failed) then Travis CI would consider the build to have failed, it would be coloured red and marked with a cross in the test jobs summary page.
* Certain lines are hidden, usually those concerned with setting up the environment for the job. Hidden lines are denoted by an arrow to the left of the line number. Click on this arrow to see the hidden lines.

Use Travis CI run build-and-test jobs for various languages
-----------------------------------------------------------

Choose a language for an introduction on how to set up a Travis CI job for that language:

* [Create a Travis CI Python job](./Python.md)
* [Create a Travis CI C job](./C.md)
* [Create a Travis CI C++ job](./Cpp.md)
* [Create a Travis CI Java job](./Java.md)
* [Create a Travis CI PHP job](./PHP.md)

Travis CI limitations
---------------------

Travis CI will terminate a job if:

* It takes longer than 120 minutes to run.
* It produces a log that exceeds 4MB.
* It produces no outputs for 10 minutes.
* It consumes more than 3GB memory.

See Travis CI's suggestions for [speeding up the build](http://docs.travis-ci.com/user/speeding-up-the-build/). The build matrix mentioned on that page can also help in reducing log sizes. Another way of reducing log sizes is to reduce the verbosity of test functions (e.g. ensuring they don't print to standard output or error) or to redirect their outputs to files.

Further information
-------------------

This has just touched upon the myriad configuration options, build steps, test steps, notification mechanisms and publishing options that Travis CI supports. 

For more information check out:

* [Travis CI for Complete Beginners](http://docs.travis-ci.com/user/for-beginners/)
* [Getting started](http://docs.travis-ci.com/user/getting-started/)
* [Travis CI user documentation](http://docs.travis-ci.com/)
* [Travis Client](https://github.com/travis-ci/travis.rb) - a Ruby-based command-line tool and library for command-line interaction with Travis CI.
