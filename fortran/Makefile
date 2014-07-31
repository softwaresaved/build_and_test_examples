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

FORTRAN=gfortran
FLAGS=-O0 --std=f2003

SRC=src/fibonacci.f90
TESTSRC=test/fruit_helpers.F90 test/fibonacci_test.f90 test/fruit_test_driver.F90
FRUIT_SRC=fruit/fruit_util.f90 fruit/fruit.f90

fibonacci : $(SRC) src/fibonacci_program.f90
	$(FORTRAN) $(FLAGS) $^ -o $@

tests : $(FRUIT_SRC) $(SRC) $(TESTSRC)
	$(FORTRAN) $(FLAGS) $^ -o $@

.PHONY : all
all : fibonacci tests

.PHONY : clean
clean :
	rm -f fibonacci
	rm -f tests
	rm -f result*.xml
	rm -f *.mod 
	rm -f *.o
	rm -f *~
	rm -f src/*~
	rm -f test/*~
