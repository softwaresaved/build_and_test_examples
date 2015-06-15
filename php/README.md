PHP and PHPUnit
===============

Prerequisites
-------------

**PHP**:

To check if it is installed already:

    $ php --version
    PHP 5.5.9-1ubuntu4.9 (cli) (built: Apr 17 2015 11:44:57) 

If not, then see [PHP Hypertext Preprocessor](http://php.net/).

**PHPUnit**:

To check if it is installed already:

    $ phpunit --version
    PHPUnit 4.7.3 by Sebastian Bergmann and contributors.

If not, then see [PHPUnit](https://phpunit.de/)'s [Getting started](https://phpunit.de/getting-started.html).

Usage
-----

Run:

    $ php src/FibonacciProgram.php 20

Run tests:

    $ phpunit --bootstrap src/autoload.php test/FibonacciTest.php
    PHPUnit 4.7.3 by Sebastian Bergmann and contributors.
    
    .....
    
    Time: 491 ms, Memory: 11.50Mb
    
    OK (5 tests, 5 assertions)

Run tests and view JUnit-style XML test report:

    $ phpunit --log-junit tests.xml --bootstrap src/autoload.php test/FibonacciTest.php
    $ cat tests.xml
