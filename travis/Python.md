Create a Travis CI Python job
=============================

Travis CI supports testing Python code under various versions of Python 2 and 3. It also pre-installs the following Python test libraries: `nose`, `pytest` and `mock`.

Updaye `.travis.yml` to run tests of Python Fibonnaci series code
-----------------------------------------------------------------

The [python](./python) directory contains a Python implementation of the Fibonacci series function and tests for this function. We can customise our `.travis.yml` job to run these tests under Python 2.7 and 3.4 as follows.

* Open `.travis.yml` in an editor.
* Change the `python` section to:

```
python:
  - "2.7"
  - "3.4"
```

* This tells Travis CI to run this job twice, once under Python 2.7 and once under Python 3.4.
* Change the `script` section to:

```
script: 
  - cd python
  - nosetests -v --nocapture
```

* This tells Travis CI to change into the `python` directory then to run all the tests it can find.
* `--nocapture` tells `nosetests` to display anything that is printed by the tests it runs.
* `-v` tells `nosetests` to print the names of the test functions as they run.
* Commit these changes your repository and push the changes to GitHub:

```
$ git commit -m "Updated .travis.yml to run Fibonacci tests in python/ under both Python 2.7 and 3.4" .travis.yml
$ git push origin master
```

* Visit https://travis-ci.org/USERNAME/build_and_test_examples.
* There will be two jobs for this job - one for Python 2.7 and one for Python 3.4.
* The Python 2.7 job should be coloured green with a tick, indicating it passed.
* The Python 3.4 job should be coloured red with a cross, indicating it failed.
* Click on the Python 2.7 job. 
* You should see that the tests run and all passed e.g.

```
Test fibonacci(0). ... ok
Test fibonacci(1). ... ok
Test fibonacci(2). ... ok
Test fibonacci(3). ... ok
Test fibonacci(30). ... ok
----------------------------------------------------------------------
Ran 5 tests in 0.693s
OK
```

* Now, go back and click on the Python 3.4 job:
* You should see that there was an error:

```
ERROR: Failure: SyntaxError (Missing parentheses in call to 'print' (fibonacci.py, line 36))
```

* This is because the Python code is not compatible with Python 3.4. Python 3.4 expects the arguments to its `print` command to be surrounded by parentheses.

Fix Python Fibonnaci series code to be Python 3-compliant
---------------------------------------------------------

* Open `python/src/fibonacci.py` in an editor.
* Add parentheses to the three `print` lines:

```
print("Usage: python fibonacci.py N")
print("  where N >= 0")
print("fibonacci(%d) = %d" % (n, fib))
```

* Commit these changes your repository and push the changes to GitHub.
* Look at your Travis CI job page.
* This time both the Python 2.7 and Python 3.4 tests should have passed.
* Click on the Python 3.4 job. 
* You should see that the tests run and all passed e.g.

```
Test fibonacci(0). ... ok
Test fibonacci(1). ... ok
Test fibonacci(2). ... ok
Test fibonacci(3). ... ok
Test fibonacci(30). ... ok
----------------------------------------------------------------------
Ran 5 tests in 0.717s
OK
```

Installing a package
--------------------

Suppose we want to generate a test coverage report - a report on the statements in our Fibonacci series implementation that were executed by our tests. `nosetests` supports a `--with-coverage` command-line option to generate this report, but this needs the Python `coverage` package to have been installed.

We can request that Travis CI install this package by adding a `before_install` section to `.travis.yml`:

* Add the following section after the `python` section:

```
before_install:
  - pip install coverage
```

* This installs the `coverage` package using Python's `pip` package installer. Note that `.travis.yml` also supports an `install` section, which contains steps that are executed after those in `before_install`. In this example, we could put our `pip` command in either section.
* Update the call to `nosetests` to generate a test coverage report:

```
  - nosetests -v --nocapture --with-coverage
```

* Commit these changes your repository and push the changes to GitHub.
* Travis CI should rerun the job, and in the logs you should see both the installation of `coverage` and a test coverage report:

```
$ pip install coverage
```

```
Name            Stmts   Miss  Cover   Missing
---------------------------------------------
python.py           0      0   100%   
python/src.py       0      0   100%   
fibonacci.py       20     11    45%   36-37, 40-48
---------------------------------------------
TOTAL              20     11    45%   
```

Further information
-------------------

For more information on Travis CI's support for Python, see [Building a Python Project](http://docs.travis-ci.com/user/languages/python/).
