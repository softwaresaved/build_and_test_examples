Getting started with Travis CI
==============================

[Travis CI](https://travis-ci.org/) is a hosted [continuous integration](http://en.wikipedia.org/wiki/Continuous_Integration) service, which provides automated build-and-test services for projects hosted on [GitHub](https://github.com). The service is free for open source projects.

Travis CI detects and responds to changes made to code or files held within Git repositories on GitHub. If the code is changed, by a commit, then Travis CI automatically runs a build-and-test job for that repository. This means that the software is rebuilt and tested every time changes to the code are pushed to GitHub. Since Travis CI is remote from your own machine, it means you can continue working while the tests are under way. It also means you do not have to set up a machine for testing locally, which can be useful if you are don't have the funding, hardware or time to set this up yourself.

This is not intended to be a complete introduction to everything that Travis CI offers. Rather, it is hoped that it will serve to get you started, helping you through your first 20 minutes of using Travis CI, to give an idea as to its potential and usefulness.

The walkthrough can be performed using Linux or UNIX.

"Hello World" with Travis CI
----------------------------

Here, we will set up a first Travis CI job, based around a simple "hello world" example, to get you up and running with Travis CI:

* ["Hello World" with Travis CI](./HelloWorld.md)

Use Travis CI run build-and-test jobs for various languages
-----------------------------------------------------------

Travis CI can build and run code written in many languages, including C, C++, Fortran, Java, PHP and Python, either directly or via automated build tools like Make or ANT. It can also run unit tests, for example written in CUnit, CppUnit, googletest, JUnit, PHPUnit or nosetests, and report on the success or failure of tests. For example, Travis CI provides out-of-the-box support for:

* [Create a Travis CI job for popular programming languages](./Languages.md) including C, C++, Java, PHP and Python.

Publishing test results
-----------------------

Unlike Jenkins, Travis CI does not allow build artefacts to be explored directly, nor does it parse xUnit-compliant XML test results into a browsable form. However, Travis CI can automatically upload build artefacts to an [Amazon S3](https://aws.amazon.com/s3/) (Simple Storage Service) area. For details, see:

* Travis CI's [S3 Deployment](http://docs.travis-ci.com/user/deployment/s3/).
* Travis CI's [Uploading Artifacts on Travis CI](http://docs.travis-ci.com/user/uploading-artifacts/).
* Stack Overflow's [Access files stored on Amazon S3 through web browser](http://stackoverflow.com/questions/16784052/access-files-stored-on-amazon-s3-through-web-browser).

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

This has just touched upon the myriad configuration options, build steps, test steps, notification mechanisms and publishing options that Travis CI supports. For more information check out:

* [Travis CI for Complete Beginners](http://docs.travis-ci.com/user/for-beginners/).
* [Getting started](http://docs.travis-ci.com/user/getting-started/).
* [Travis CI user documentation](http://docs.travis-ci.com/).
* [Travis Client](https://github.com/travis-ci/travis.rb) - a Ruby-based command-line tool and library for command-line interaction with Travis CI.
