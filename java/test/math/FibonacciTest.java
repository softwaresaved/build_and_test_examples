package math;

// Copyright 2014 The University of Edinburgh.
//
// Licensed under the Apache License, Version 2.0 (the "License"); 
// you may not use this file except in compliance with the License. 
// You may obtain a copy of the License at
//
//   http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software 
// distributed under the License is distributed on an "AS IS" BASIS, 
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or
// implied. See the License for the specific language governing
// permissions and limitations under the License.

import org.junit.After;
import org.junit.Before;
import org.junit.Test;
import static org.junit.Assert.*;

import math.Fibonacci;

/**
 * Test class for Fibonacci class.
 */ 
public class FibonacciTest
{
    /** Initialise test suite - no-op. */
    @Before
    public void setUp()
    {
    }

    /** Clean up test suite - no-op. */
    @After
    public void tearDown()
    {
    }
   
    /** Test fib(1). */
    @Test
    public void testFib1()
    {
        assertEquals(1, Fibonacci.fib(1));
    }

    /** Test fib(2). */
    @Test
    public void testFib2()
    {
        assertEquals(1, Fibonacci.fib(2));
    }

    /** Test fib(3). */
    @Test
    public void testFib3()
    {
        assertEquals(2, Fibonacci.fib(3));
    }

    /** Test fib(30). */
    @Test
    public void testFib30()
    {
        assertEquals(832040, Fibonacci.fib(30));
    }

    /** Test fib(-1). */
    @Test
    public void testFibMinusOne()
    {
        boolean caught = false;
        try
        {
            Fibonacci.fib(-1);
        }
        catch (IllegalArgumentException e)
        {
            caught = true;
        }
        assertTrue(caught);
    }
}
