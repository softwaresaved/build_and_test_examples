Python and nosetests
====================

Prerequisites
-------------

**Python 2.7+ or Python 3**:

To check if Python is installed already:

```
$ python --version
Python 2.7.1+
```

If not, then see [Downloading Python](http://wiki.python.org/moin/BeginnersGuide/Download). The [Anaconda](http://continuum.io/anacondace.html) scientific Python installer which has a comprehensive Python tool stack.

**nose test framework**:

To check if nose is installed already:

```
$ nosetests --version
nosetests version 1.2.1
$ nosetests
----------------------------------------------------------------------
Ran 0 tests in 0.006s

OK
```

If not, then see [nose](http://nose.readthedocs.org). For XML test reports, nosetests 1.0+ is needed.

Usage
-----

Run:

```
$ python src/fibonacci.py 30
fibonacci(30) = 832040
```

Run tests and view XML xUnit-style test report:

```
$ nosetests --with-xunit
$ cat nosetests.xml
```
