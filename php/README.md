PHP and PHPUnit
===============

Prerequisites
-------------

**PHP**:

To check if `php` is installed already:

```
$ php --version
PHP 5.5.9-1ubuntu4.9 (cli) (built: Apr 17 2015 11:44:57) 
```

If not, then see [PHP Hypertext Preprocessor](http://php.net/).

**PHPUnit test framework**:

To check if PHPUnit is installed already:

```
$ phpunit --version
PHPUnit 4.8.9 by Sebastian Bergmann and contributors.
```

To download and install see [PHPUnit](https://phpunit.de/)'s [Getting started](https://phpunit.de/getting-started.html). The following provides a quick summary of the key steps to download and install PHPUnit in your home directory:

```
$ wget https://phar.phpunit.de/phpunit.phar
$ chmod +x phpunit.phar
$ mkdir $HOME/bin
$ mv phpunit.phar $HOME/bin/phpunit
$ phpunit --version
PHPUnit 4.8.9 by Sebastian Bergmann and contributors.
```

Usage
-----

Run:

```
$ php src/FibonacciProgram.php 20
832040
```

Run tests and view XML xUnit-style test report:

```
$ phpunit --log-junit TestResults.xml --bootstrap src/autoload.php test/FibonacciTest.php
$ cat TestResults.xml
```
