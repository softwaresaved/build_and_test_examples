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
#include "fibonacci.h"

void print_usage()
{
    printf("Usage: python fibonacci.py N\n");
    printf("  where N >= 0\n");
}

int main(int argc, char **argv) 
{
    if (argc <= 1)
    {
        print_usage();
        return(1);
    }
    int n = atoi(argv[1]);
    if (n < 0)
    {
        print_usage();
        return(2);
    }
    int fib = fibonacci(n);
    printf("fibonacci(%d) = %d\n", n, fib);
    return(0);
}
