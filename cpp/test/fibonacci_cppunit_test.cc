
// Copyright 2014 The University of Edinburgh.
//
// Licensed under the Apache License, Version 2.0 (the "License"); 
// you may not use this file except in compliance with the License. 
// You may obtain a copy of the License at
//
//  http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software 
// distributed under the License is distributed on an "AS IS" BASIS, 
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or
// implied. See the License for the specific language governing
// permissions and limitations under the License.

#include <cppunit/extensions/HelperMacros.h>
#include "fibonacci.h"

/**
 * Test class for Fibonacci.
 */
class FibonacciTest:public CppUnit::TestFixture 
{

  CPPUNIT_TEST_SUITE(FibonacciTest);
  CPPUNIT_TEST(testFibonacci1);
  CPPUNIT_TEST(testFibonacci2);
  CPPUNIT_TEST(testFibonacci3);
  CPPUNIT_TEST(testFibonacci30);
  CPPUNIT_TEST_SUITE_END();

  public:

  /* Initialise test suite - no-op. */
  void setUp() 
  {
    // No-op.
  }

  /* Clean up test suite - no-op. */
  void tearDown() {
    // No-op.
  }

  /* Test fibonacci(1). */
  void testFibonacci1() {
    int result = fibonacci(1);
    CPPUNIT_ASSERT_EQUAL(1, result);
  }

  /* Test fibonacci(2). */
  void testFibonacci2() {
    int result = fibonacci(2);
    CPPUNIT_ASSERT_EQUAL(1, result);
  }

  /* Test fibonacci(3). */
  void testFibonacci3() {
    int result = fibonacci(3);
    CPPUNIT_ASSERT_EQUAL(2, result);
  }

  /* Test fibonacci(30). */
  void testFibonacci30() {
    int result = fibonacci(30);
    CPPUNIT_ASSERT_EQUAL(832040, result);
  }
};

CPPUNIT_TEST_SUITE_REGISTRATION(FibonacciTest);
