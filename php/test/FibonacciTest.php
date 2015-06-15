<?php

/**
 * Fibonacci numbers test class.
 *
 * Copyright 2015 The University of Edinburgh.
 *
 * Licensed under the Apache License, Version 2.0 (the "License"); 
 * you may not use this file except in compliance with the License. 
 * You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software 
 * distributed under the License is distributed on an "AS IS" BASIS, 
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or
 * implied. See the License for the specific language governing
 * permissions and limitations under the License.
  */

namespace Maths;

/**
 * PHPUnit test class for \Maths\Fibonacci class.
 */
class FibonacciTest extends \PHPUnit_Framework_TestCase
{
    /**
     * Set up test fixture.
     */
    public function setUp()
    {
        parent::setUp();
    }

    /**
     * Tear down test fixture.
     */
    public function tearDown()
    {
        parent::tearDown();
    }

    /** Test Fibonacci::fib(0). */
    public function testFib0()
    {
        $this->assertEquals(0, Fibonacci::fib(0));
    }

    /** Test Fibonacci::fib(1). */
    public function testFib1()
    {
        $this->assertEquals(1, Fibonacci::fib(1));
    }

    /** Test Fibonacci::fib(2). */
    public function testFib2()
    {
        $this->assertEquals(1, Fibonacci::fib(2));
    }

    /** Test Fibonacci::fib(3). */
    public function testFib3()
    {
        $this->assertEquals(2, Fibonacci::fib(3));
    }

    /** Test Fibonacci::fib(30). */   
    public function testFib30()
    {
        $this->assertEquals(832040, Fibonacci::fib(30));
    }
}
