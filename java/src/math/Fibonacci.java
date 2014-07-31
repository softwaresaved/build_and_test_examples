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

/**
 * Fibonacci numbers class.
 */ 
public class Fibonacci 
{
    /**
     * Calculate the Fibonacci number of the given integer.
     *
     * @param n
     * @return Fibonacci number.
     * @throws IllegalArgumentException if n is < 0.
     */
    public static int fib(int n) 
    {
        if (n < 0)
        {
            throw new IllegalArgumentException("n must be >= 0");
        }
	else if (n < 2)
	{
	    return n;
	}
	else 
	{
	    return fib(n - 1) + fib(n - 2);
	}
    }

    /** Print usage information. */
    public static void print_usage()
    {
        System.out.println("Usage: java math.Fibonacci N");
        System.out.println("  where N >= 0");
    }

    public static void main(String[] args) 
    {
        if (args.length < 1)
        {
            print_usage();
            System.exit(1);
        }
        int n = Integer.parseInt(args[0]);
        if (n < 0)
        {
            print_usage();
            System.exit(2);
        }
        int fibonacci = Fibonacci.fib(n);
        System.out.print("fib(" + n + ") = " + fibonacci + "\n");
    }
}
