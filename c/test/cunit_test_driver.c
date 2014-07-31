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
#include "fibonacci_cunit_test.h"

/*
 * Set up and run tests.
 *
 * @return CUE_SUCCESS if successful, else a CUnit error code if
 * any problems arise.
 */
int main()
{
    if (CUE_SUCCESS != CU_initialize_registry())
    {
        return CU_get_error();
    }

    CU_pSuite suite = 
        CU_add_suite("Fibonacci Suite", initialise_suite, cleanup_suite);
    if (NULL == suite) 
    {
        CU_cleanup_registry();
        return CU_get_error();
    }

    if ((NULL == CU_add_test(suite, "test_fibonacci_1", test_fibonacci_1)) ||
        (NULL == CU_add_test(suite, "test_fibonacci_2", test_fibonacci_2)) ||
        (NULL == CU_add_test(suite, "test_fibonacci_3", test_fibonacci_3)) ||
        (NULL == CU_add_test(suite, "test_fibonacci_30", test_fibonacci_30)))
    {
        CU_cleanup_registry();
        return CU_get_error();
    }

    // Run all tests using CUnit Basic interface which outputs
    // results to command-line.
    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();

    // Run all tests using CUnit Automated interface which outputs
    // results to a file, default name CUnitAutomated-Results.xml.
    // DTD CUnit-Run.dtd and and XSL stylesheet CUnit-Run.xsl in Share/
    // Uncomment this line to override default output file prefix.
    // CU_set_output_filename("Test");
    CU_list_tests_to_file();

    // Output listing of tests in suites to a file, default name
    // CUnitAutomated-Listing.xml
    // DTD CUnit-List.dtd and and XSL stylesheet CUnit-List.xsl in Share/
    CU_automated_run_tests();

    CU_cleanup_registry();
    return CU_get_error();
}
