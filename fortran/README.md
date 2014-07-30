FORTRAN, FRUIT and Make
=======================

Prerequisites
-------------

**gfortran**:

To check if it is installed already:

    $ gfortran -v
    gcc version 4.4.7 20120313 (Red Hat 4.4.7-3) (GCC) 

**FRUIT**:

This is provided.

* Files: `fruit/*`
* Version: 3.3.4, downloaded 02/06/14.
* License: BSD license, `FRUIT_LICENSE.txt`.
* Web site: http://sourceforge.net/projects/fortranxunit/.
* Used by: test code in `test/`.

Usage
-----

Compile:

    $ make fibonacci

Run:

    $ ./fibonacci 20

Compile tests:

    $ make tests

Run tests:

    $ ./tests

View results as XML:

    $ cat result.xml

Clean up:

    $ make clean
