#!/bin/bash

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

fibonacci_number=0

# Calculate the Fibonacci number of the given integer.
# If $1 <= 0 then 0 is assumed.
# After execution fibonacci_number holds the result.
fibonacci() {
  n=$1
  if [ $n -le 0 ]; then 
    fibonacci_number=0
  elif [ $n -eq 1 ]; then
    fibonacci_number=1
  else
    a=0
    b=1
    count=2
    fibonacci_number=$a
    while [ $count -le $n ]; do 
      fibonacci_number=$[$a+$b]
      a=$b
      b=$fibonacci_number
      count=$[$count + 1]
    done
  fi
}

print_usage() {
  echo "Usage: ./fibonacci.sh N"
  echo "  where N >= 0"
}

if [ -z "$1" ]; then
  print_usage
  exit 1
elif [ $1 -lt 0 ]; then
  print_usage
  exit 2
else
  fibonacci $1
  echo "fibonacci $1 = $fibonacci_number"
fi
