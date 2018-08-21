Build and Test Examples
=======================

Introduction
------------

This repository provides examples of a Fibonacci series function implemented in a range of languages. Build files for popular build tools for each language are also provided as are examples of unit tests written in popular unit test frameworks for each language. These examples are provided to help you get started with using automated build tools and unit test frameworks. They are also used to provide an introduction to the popular continuous integration servers, Jenkins and Travis CI.

Using this repository for teaching and learning
-----------------------------------------------

We are happy if course organisers and students wish to use this repository as a resource for their teaching and learning. However, we request that you **do not to submit Pull Requests to this repository** as when learning about Travis CI. If you wish to use it that way then please **Fork the repository into your own GitHub project or account**.

Languages, build tools and unit test frameworks
-----------------------------------------------

Examples using the following languages, build tools and unit test frameworks are provided. Click on README for information on how to build, run and test each example:

| Language | Build tool | Unit test framework | README |
| -------- | ---------- | ------------------- | ------ |
| Bash Shell | - | - | [README](./sh/README.md) |
| Python | - | pytest | [README](./python/README.md) |
| Java | ANT | JUnit | [README](./java/README.md) |
| C | Make | CUnit | [README](./c/README.md) |
| C++ | Make | CppUnit and googletest | [README](./cpp/README.md) |
| Fortran | Make | FRUIT | [README](./fortran/README.md) |
| PHP | - |  PHPUnit | [README](./php/README.md) |
| R | - |  testthat | [README](./R/README.md) |

Continuous integration
----------------------

Continuous integration can help you to build and test your software regularly. This, in turn, can help you to demonstrate that your software does what it claims to do, and that it does so correctly. It also helps you to rapidly release bug-fixes and up-to-date versions of your software. Continuous integration can also be used to automate experiments that are run using software. For an overview, see The Software Sustainability Institute's [How continuous integration can help you regularly test and release your software](http://software.ac.uk/how-continuous-integration-can-help-you-regularly-test-and-release-your-software).

**Jenkins**

[Jenkins](http://jenkins-ci.org) is a popular, open source continuous integration server, which you can deploy locally. For an introduction to Jenkins, using the Fibonacci series examples in a range of languages, see:

* [Getting started with Jenkins](./jenkins/README.md). The walkthrough assumes you have installed the software required to build and test the Fibonacci series examples (or, at least, that needed by the language you are interested in).

**Travis CI**

[Travis CI](https://travis-ci.org/) is a hosted continuous integration server, which provides automated build and test services for projects hosted on GitHub.  For an introduction to Travis CI, using the Fibonacci series examples, in a range of languages, see:

* [Getting started with Travis CI](./travis/README.md)

For an overview of hosted continuous integration, see The Software Sustainability Institute's [Hosted continuous integration](http://www.software.ac.uk/resources/guides/hosted-continuous-integration).

How to contribute
-----------------

If you have any comments, corrections or additions then please either raise an [issue](https://github.com/softwaresaved/build_and_test_examples/issues) or submit a pull request.

Copyright and licence
---------------------

Copyright (c) 2014-2018 The University of Edinburgh.

Code is licensed under the [Apache 2.0](http://www.apache.org/licenses/LICENSE-2.0.html) licence. The licence text is also in [LICENSE-2.0.txt](./LICENSE-2.0.txt).

Documents are licensed under the Creative Commons [Attribution-NonCommercial 2.5 UK: Scotland (CC BY-NC 2.5 SCOTLAND)](http://creativecommons.org/licenses/by-nc/2.5/scotland/).

This directory includes third-party software. Please see the `README.md` files in sub-directories for more information. 
