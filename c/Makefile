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

CC=gcc -O3
LDFLAGS=-lcunit

SRCDIR= src
TESTDIR= test
INC=-I$(SRCDIR) -I$(TESTDIR) -I$(HOME)/include

OBJS=fibonacci.o
TESTS=fibonacci_cunit_test.o

%.o : $(SRCDIR)/%.c
	$(CC) -c $^ -o $@ $(INC)
%.o : $(TESTDIR)/%.c
	$(CC) -c $< -o $@ $(INC)

fibonacci: $(OBJS) fibonacci_program.o
	$(CC) -o $@ $^ $(INC)

tests: $(TESTS) $(OBJS) cunit_test_driver.o
	$(CC) -o $@ $^ $(INC) $(LDFLAGS)

report :
	xsltproc -novalid cunit-to-junit.xsl CUnitAutomated-Results.xml > TestResults.xml

.PHONY : runtests
runtests : tests
	./$<

.PHONY : all
all : fibonacci tests

.PHONY : clean
clean :
	rm -f fibonacci
	rm -f tests
	rm -f CUnit*.xml
	rm -f TestResults.xml
	rm -f *.o
	rm -f *~
	rm -f src/*~
	rm -f test/*~
