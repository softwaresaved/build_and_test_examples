Getting started with Jenkins
============================

[Jenkins](http://jenkins-ci.org) is a [continuous integration](http://en.wikipedia.org/wiki/Continuous_Integration) server. In these pages we provide an introduction to Jenkins and how it can be used to automate the building and testing of software. We also show how Jenkins build-and-test jobs can be triggered by changes to code held in popular source code repositories including Git, Mercurial, Subversion and CVS.

Install and deploy Jenkins
--------------------------

* [Installing Jenkins](./Install.md)

Use Jenkins to trigger execution of a shell script
--------------------------------------------------

* [Create a Jenkins shell script job](./Shell.md)

Use Jenkins to trigger build-and-test in various languages
----------------------------------------------------------

* [Create a Jenkins Python job](./Python.md)
* [Create a Jenkins C job](./C.md)
* [Create a Jenkins C++ job](./Cpp.md)
* [Create a Jenkins FORTRAN job](./Fortran.md)
* [Create a Jenkins Java job](./Java.md)

Use Jenkins to run jobs periodically
------------------------------------

* [Configure a job to run periodically](./Periodic.md)

Use Jenkins to run build-and-test jobs when source code changes
---------------------------------------------------------------

Jenkins can be configured to detect and respond to changes made to code or files held under version control. If the code is changed, then the server can automatically spawn a new build-and-test job. This means that the software is rebuilt and tested every time the code is changed. Since the server can be remote from your own machine, it means you can continue working while the tests are under way.

* [Configure a job to run when updates are committed to Git](./Git.md)
* [Configure a job to run when updates are committed to Mercurial](./Hg.md)
* [Configure a job to run when updates are committed to Subversion](./SVN.md)
* [Configure a job to run when updates are committed to CVS](./CVS.md)

Use Jenkins to run experiments
------------------------------

Jenkins can not only trigger builds for very complex software but also trigger and provide a summary of the success or failure of experiment runs. As [Create a Jenkins shell script job](./Shell.md) shows, Jenkins can run any shell script and report on the success or failure depending on whether the script exits with 0, success, or non-zero, failure. There is no restriction as to what this shell script does.

Jenkins can provide a summary of the console output on the build results page. It also, on a project page, allows us, via the Workspace link, to browse the project's workspace. Typically this is the directory where the scripts are invoked. If output files are placed here by the scripts, then they can be viewed via Jenkins too.

Further information
-------------------

This has just touched upon the myriad configuration options, build steps, test steps, notification mechanisms and publishing options that Jenkins supports. 

For more information check out:

* Jenkins' [Meet Jenkins](https://wiki.jenkins-ci.org/display/JENKINS/Meet+Jenkins)
* Jenkins' [Use Jenkins](https://wiki.jenkins-ci.org/display/JENKINS/Use+Jenkins)
* The Software Sustainability Institute's [How continuous integration can help you regularly test and release your software](http://software.ac.uk/how-continuous-integration-can-help-you-regularly-test-and-release-your-software) guide.
* The Software Sustainability Institute's [Hosted continuous integration](http://www.software.ac.uk/resources/guides/hosted-continuous-integration) guide.
