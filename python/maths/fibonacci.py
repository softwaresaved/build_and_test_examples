"""
Fibonacci numbers function.
"""

# Copyright 2014 The University of Edinburgh.
#
# Licensed under the Apache License, Version 2.0 (the "License"); 
# you may not use this file except in compliance with the License. 
# You may obtain a copy of the License at
#
#   http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software 
# distributed under the License is distributed on an "AS IS" BASIS, 
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or
# implied. See the License for the specific language governing
# permissions and limitations under the License.

import sys

def fibonacci(n):
  """
  Calculate the Fibonacci number of the given integer.
  @param n If n <= 0 then 0 is assumed.
  @return fibonacci number.
  """
  if n <= 0:
    return 0
  elif n == 1:
    return 1
  else:
    return fibonacci(n - 1) + fibonacci(n - 2)

def print_usage():
  """ Print usage information. """
  print("Usage: python fibonacci.py N")
  print("  where N >= 0")

if __name__ == '__main__':
  if (len(sys.argv) < 2):
    print_usage()
    exit(1)
  n = int(sys.argv[1])  
  if (n < 0):
    print_usage()
    exit(2)
  fib = fibonacci(n)
  print("fibonacci(%d) = %d" % (n, fib))
