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

CXX=c++
LDFLAGS=-lcunit

CPPUNITLDFLAGS=-lcppunit
GOOGLELDFLAGS=-lgtest -lgtest_main

SRCDIR=src
TESTDIR=test
INC=-I$(SRCDIR) -I$(TESTDIR) -I$(HOME)/include

HEADER=src/fibonacci.h
CPPUNITTESTS=fibonacci_cppunit_test.o
GOOGLETESTS=fibonacci_google_test.o

fibonacci: fibonacci_program.o $(HEADER)
	$(CXX) -o $@ $^ $(INC)

fibonacci-cppunittests: $(HEADER) $(CPPUNITTESTS) cppunit_test_driver.o
	$(CXX) -o $@ $^ $(INC) $(CPPUNITLDFLAGS)

fibonacci-googletests: $(HEADER) $(GOOGLETESTS)
	$(CXX) -o $@ $^ $(INC) $(GOOGLELDFLAGS)

%.o : $(SRCDIR)/%.cc $(HEADER)
	$(CXX) -c $< -o $@ $(INC)
%.o : $(TESTDIR)/%.cc $(HEADER)
	$(CXX) -c $< -o $@ $(INC)

.PHONY : test
test : fibonacci-cppunittests
	./$<

.PHONY : googletest
googletest : fibonacci-googletests
	./$< --gtest_output="xml:TestResults.xml"

.PHONY : all
all : fibonacci test googletest

.PHONY : clean
clean :
	rm -f fibonacci
	rm -f fibonacci-cppunittests
	rm -f fibonacci-googletests
	rm -f TestResults.xml
	rm -f *.o
	rm -f *~
	rm -f src/*~
	rm -f test/*~
