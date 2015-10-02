R and testthat
==============

Prerequisites
-------------

**R**:

To check if R is installed already:

```
$ R --version
R version 3.2.2 (2015-08-14) -- "Fire Safety"
```

If not, then see [R](https://cran.r-project.org/).

**testthat test framework**:

To download and install see [testthat](https://cran.r-project.org/web/packages/testthat/index.html). To quickly check if testthat is installed already, and, if not, to install it, run:

```
$ install.packages("testthat")
```

If you get

```
Warning message:
package testthat is not available (for R version 3.2.2) 
```

then manually download and install testthat and its dependencies:

```
$ wget https://cran.r-project.org/src/contrib/testthat_0.10.0.tar.gz
$ wget https://cran.r-project.org/src/contrib/digest_0.6.8.tar.gz
$ wget https://cran.r-project.org/src/contrib/crayon_1.3.1.tar.gz
$ wget https://cran.r-project.org/src/contrib/memoise_0.2.1.tar.gz
$ R CMD INSTALL memoise_0.2.1.tar.gz
$ R CMD INSTALL crayon_1.3.1.tar.gz
$ R CMD INSTALL digest_0.6.8.tar.gz
$ R CMD INSTALL testthat_0.10.0.tar.gz 
```

Usage
-----

Install:

```
$ cd ..
$ R CMD check R
$ R CMD INSTALL R 
```

To install tests too:

```
$ R CMD INSTALL --install-tests R 
```

Run:

```
$ cd R/
$ Rscript exec/fibonacci_client.R 30
fib( 30 ) =  832040 
```

Run tests:

```
$ cd tests/
$ Rscript testthat.R
Loading required package: methods
Loading required package: ssi.r.sample
Fibonacci tests : .....

DONE 
```

Run tests within R:

```
$ R
> library(testthat)
> library(ssi.r.sample)
> test_file("tests/testthat/test_fibonacci.R")
Fibonacci tests : .....

DONE 
```

Run package tests, if tests have been installed:

```
$ R
> library(testthat)
> test_package("ssi.r.sample")
Fibonacci tests : ....

DONE
```
