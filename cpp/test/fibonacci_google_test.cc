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

#include <stdio.h>
#include <string.h>

#include <gtest/gtest.h>

#include "fibonacci.h"

class FibonacciTest : public ::testing::Test 
{
  protected:

  /* Initialise test suite - no-op. */
  virtual void SetUp() 
  {
    // No-op.
  }

  /* Clean up test suite - no-op. */
  virtual void TearDown() {
    // No-op.
  }
};

TEST_F(FibonacciTest, fibonacci1)
{
  int result = fibonacci(1);
  ASSERT_EQ(1, result);
}

TEST_F(FibonacciTest, fibonacci2)
{
  int result = fibonacci(2);
  ASSERT_EQ(1, result);
}

TEST_F(FibonacciTest, fibonacci3)
{
  int result = fibonacci(3);
  ASSERT_EQ(2, result);
}

TEST_F(FibonacciTest, fibonacci30)
{
  int result = fibonacci(30);
  ASSERT_EQ(832040, result);
}
