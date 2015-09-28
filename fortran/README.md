FORTRAN, FRUIT and Make
=======================

Prerequisites
-------------

**gfortran**:

To check if gfortran is installed already:

```
$ gfortran -v
gcc version 4.4.7 20120313 (Red Hat 4.4.7-3) (GCC) 
```

**FRUIT - FORTRAN test framework**:

This is provided.

* Files: `fruit/*`
* Version: 3.3.4, downloaded 02/06/14.
* License: BSD license, `FRUIT_LICENSE.txt`.
* Web site: http://sourceforge.net/projects/fortranxunit/.
* Used by: test code in `test/`.

Usage
-----

Compile:

```
$ make fibonacci
```

Run:

```
$ ./fibonacci 20
```

Compile and run tests and view XML xUnit-style test report:

```
$ make test
$ cat result.xml
```

Clean up:

```
$ make clean
```
