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

#include "fibonacci_cunit_test.h"

int initialise_suite(void)
{
   return 0;
}

int cleanup_suite(void)
{
    return 0;
}

void test_fibonacci_1(void)
{
    CU_ASSERT_EQUAL(fibonacci(1), 1);
}

void test_fibonacci_2(void)
{
    CU_ASSERT_EQUAL(fibonacci(2), 1);
}

void test_fibonacci_3(void)
{
    CU_ASSERT_EQUAL(fibonacci(3), 2);
}

void test_fibonacci_30(void)
{
    CU_ASSERT_EQUAL(fibonacci(30), 832040);
}
