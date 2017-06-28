Python and pytest
=================

Prerequisites
-------------

**Python 2.7+ or Python 3**:

To check if Python is installed already:

```
$ python --version
Python 2.7.1+
```

If not, then see [Downloading Python](http://wiki.python.org/moin/BeginnersGuide/Download). The [Anaconda](http://continuum.io/anacondace.html) scientific Python installer which has a comprehensive Python tool stack.

**pytest**:

To check if pytest is installed already:

```
$ py.test --version
This is pytest version 2.7.0, imported from /usr/lib/python2.7/site-packages/pytest.pyc
```

If not, then see [pytest](https://docs.pytest.org/en/latest/).

Usage
-----

Run:

```
$ python maths/fibonacci.py 30
fibonacci(30) = 832040
```

Run tests and view XML xUnit-style test report:

```
$ py.test --junit-xml=report.xml
============================= test session starts ==============================
platform linux2 -- Python 2.7.5 -- py-1.4.27 -- pytest-2.7.0
rootdir: /home/mjj/prog-skills/build_and_test_examples/python, inifile: 
plugins: cov
collected 5 items 

maths/tests/test_fibonacci.py .....

 generated xml file: /home/mjj/prog-skills/build_and_test_examples/python/report.xml 
=========================== 5 passed in 0.30 seconds ===========================
$ cat report.xml
```
