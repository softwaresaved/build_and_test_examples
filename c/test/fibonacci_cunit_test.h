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

#ifndef FIBONACCI_CUNIT_TEST_H
#define FIBONACCI_CUNIT_TEST_H

#include "CUnit/Automated.h"
#include "CUnit/Basic.h"
#include "fibonacci.h"

/*
 * Initialise test suite.
 * @return zero on success, non-zero otherwise.
 */
int initialise_suite(void);

/* 
 * Clean up test suite.
 * @return zero on success, non-zero otherwise.
 */
int cleanup_suite(void);

/* 
 * Test fibonacci(1).
 */
void test_fibonacci_1(void);

/* 
 * Test fibonacci(2).
 */
void test_fibonacci_2(void);

/* 
 * Test fibonacci(3).
 */
void test_fibonacci_3(void);

/* 
 * Test fibonacci(30).
 */
void test_fibonacci_30(void);

#endif
