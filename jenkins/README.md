Getting started with Jenkins
============================

[Jenkins](http://jenkins-ci.org) is a popular, open source [continuous integration](http://en.wikipedia.org/wiki/Continuous_Integration) server. In these pages we provide an introduction to Jenkins and how it can be used to automate the building and testing of software. We also show how Jenkins build-and-test jobs can be triggered by changes to code held in popular source code repositories including Git, Mercurial, Subversion and CVS.

This is not intended to be a complete introduction to everything that Jenkins offers. Rather, it is hoped that it will serve to get you started, helping you through your first 20 minutes of using Jenkins, to give an idea as to its potential and usefulness.

The walkthrough can be performed using Linux or UNIX.

Install and deploy Jenkins
--------------------------

* [Installing Jenkins](./Install.md)

Use Jenkins to run build-and-test jobs for various languages
------------------------------------------------------------

Jenkins can build and run code written in many languages, including C, C++, Fortran, Java, PHP and Python code, either directly or via automated build tools like Make or ANT. It can also run unit tests, for example written for CUnit, CppUnit, googletest, FRUIT, JUnit, PHPUnit or pytest, and report on the success or failure of tests.

* [Create a Jenkins job for popular programming languages](./Languages.md) including C, C++, Fortran, Java, PHP and Python.

Use Jenkins to run jobs periodically
------------------------------------

Jenkins can be configured to run jobs periodically.

* [Configure a job to run periodically](./Periodic.md)

Use Jenkins to run build-and-test jobs when source code changes
---------------------------------------------------------------

Jenkins can be configured to detect and respond to changes made to code or files held under popular source code repositories, including Git, Mercurial, Subversion and CVS. If the code is changed, then the server can automatically spawn a new build-and-test job. This means that the software is rebuilt and tested every time the code is changed. Since the server can be remote from your own machine, it means you can continue working while the tests are under way.

* [Configure a job to run when updates are committed a source code repository](./VersionControl.md)

Use Jenkins to run experiments
------------------------------

Jenkins can not only trigger builds for very complex software but also trigger and provide a summary of the success or failure of experiment runs. Jenkins can run any shell script and report on the success or failure depending on whether the script exits with 0, for success, or non-zero, for failure. Jenkins imposes no restriction as to what this shell script does. 

Jenkins can provide a summary of the console output on the build results page. It also, on a project page, allows us, via the Workspace link, to browse the project's workspace. Typically this is the directory where the scripts are invoked. If output files are placed here by the scripts, then they can be viewed via Jenkins too.

For a simple example of using Jenkins to run a shell script, see:

* [Create a Jenkins shell script job](./Shell.md)

Importing Jenkins jobs
----------------------

The [examples/](./examples) directories contains examples of Jenkins job configuration files for each of the jobs written following the above instructions. These are plain-text XML files which can be imported into Jenkins. They assume `build_and_test_examples` is located in your `$HOME` directory.

The source code repository-related examples assume you have set up source code repositories, as described in the above pages.

To import any of these jobs into Jenkins:

```
$ cp -r jenkins/JOB_NAME $HOME/.jenkins/jobs/
```

For the following jobs, replace `/home/user` with the full path to your source code repository:

```
CVS job/config.xml
Git job/config.xml
Mercurial job/config.xml
SVN job/config.xml
```

On the Jenkins dashboard:

* Click Manage Jenkins.
* Click Reload configuration from disk.
* You should see JOB_NAME.
* Click green "run" icon.

Further information
-------------------

This has just touched upon the myriad configuration options, build steps, test steps, notification mechanisms and publishing options that Jenkins supports. 

For more information check out:

* Jenkins' [Meet Jenkins](https://wiki.jenkins-ci.org/display/JENKINS/Meet+Jenkins)
* Jenkins' [Use Jenkins](https://wiki.jenkins-ci.org/display/JENKINS/Use+Jenkins)
