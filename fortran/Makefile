# Copyright 2014-2015 The University of Edinburgh.
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

SRCDIR=src
TESTDIR=test
FRUITDIR=fruit

OBJS=fibonacci.o
TESTS=fruit_helpers.o fibonacci_test.o fruit_test_driver.o
FRUITS=fruit_util.o fruit.o

fibonacci : $(OBJS) fibonacci_program.o
	$(FORTRAN) $(FLAGS) $^ -o $@

fibonacci-tests : $(FRUITS) $(OBJS) $(TESTS)
	$(FORTRAN) $(FLAGS) $^ -o $@

%.o : $(SRCDIR)/%.f90
	$(FORTRAN) $(FLAGS) -c $< -o $@
%.o : $(TESTDIR)/%.f90
	$(FORTRAN) $(FLAGS) -c $< -o $@
%.o : $(TESTDIR)/%.F90
	$(FORTRAN) $(FLAGS) -c $< -o $@
%.o : $(FRUITDIR)/%.f90
	$(FORTRAN) $(FLAGS) -c $< -o $@

.PHONY : test
test : fibonacci-tests
	./$<

.PHONY : all
all : fibonacci test

.PHONY : clean
clean :
	rm -f fibonacci
	rm -f fibonacci-tests
	rm -f result*.xml
	rm -f *.mod 
	rm -f *.o
	rm -f *~
	rm -f src/*~
	rm -f test/*~
