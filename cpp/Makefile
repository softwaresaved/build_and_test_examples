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

CXX=c++
LDFLAGS=-lcunit

CPPUNITLDFLAGS=-lcppunit
GOOGLELDFLAGS=-lgtest -lgtest_main

SRCDIR=src
TESTDIR=test
INC=-I$(SRCDIR) -I$(TESTDIR) -I$(HOME)/include

CPPUNITTESTS=fibonacci_cppunit_test.o
GOOGLETESTS=fibonacci_google_test.o

%.o : $(SRCDIR)/%.cc
	$(CXX) -c $^ -o $@ $(INC)
%.o : $(TESTDIR)/%.cc
	$(CXX) -c $< -o $@ $(INC)

fibonacci: fibonacci_program.o
	$(CXX) -o $@ $^ $(INC)

cppunittests: $(CPPUNITTESTS) cppunit_test_driver.o
	$(CXX) -o $@ $^ $(INC) $(CPPUNITLDFLAGS)

googletests: $(GOOGLETESTS)
	$(CXX) -o $@ $^ $(INC) $(GOOGLELDFLAGS)

.PHONY : runcppunittests
runcppunittests : cppunittests
	./$<

.PHONY : rungoogletests
rungoogletests : googletests
	./$< --gtest_output="xml:TestResults.xml"

.PHONY : all
all : fibonacci cppunittests googletests

.PHONY : clean
clean :
	rm -f fibonacci
	rm -f cppunittests
	rm -f googletests
	rm -f TestResults.xml
	rm -f *.o
	rm -f *~
	rm -f src/*~
	rm -f test/*~
