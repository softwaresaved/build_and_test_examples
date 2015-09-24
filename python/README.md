Python and nosetests
====================

Prerequisites
-------------

**Python 2.6.6+**:

To check if it is installed already:

```
$ python --version
Python 2.7.1+
```

If not, then see [Downloading Python](http://wiki.python.org/moin/BeginnersGuide/Download). The [Anaconda](http://continuum.io/anacondace.html) scientific Python installer which has a comprehensive Python tool stack.

**nosetests**:

To check if it is installed already:

```
$ nosetests --version
nosetests version 1.2.1
$ nosetests
----------------------------------------------------------------------
Ran 0 tests in 0.006s

OK
```
 
If not, then see [nose](http://nose.readthedocs.org).

For XML test reports, nosetests 1.0+ is needed.

Usage
-----

Run:

```
$ python src/fibonacci.py 20
```

Run tests:

```
$ nosetests --with-xunit
```

Run tests and view XML test report:

```
$ nosetests --with-xunit
$ cat nosetests.xml
```
