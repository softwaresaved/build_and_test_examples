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

SRCDIR  = src
INCDIR  = src
TESTDIR = test

SRCS:=$(wildcard $(SRCDIR)/*.c)
OBJS:=$(SRCS:$(SRCDIR)/%.c=%.o)
TESTSRCS:=$(wildcard $(TESTDIR)/*.c)
TESTOBJS:=$(TESTSRCS:$(TESTDIR)/%.c=%.o) fibonacci.o

%.o : $(SRCDIR)/%.c
	$(CC) -c $^ -o $@ -I$(INCDIR)

%.o : $(TESTDIR)/%.c
	$(CC) -c $< -o $@ -I$(INCDIR)

fibonacci: $(OBJS)
	$(CC) -o $@ $^ -I$(INCDIR)

tests: $(TESTOBJS)
	$(CC) -o $@ $^ -I$(INCDIR) $(LDFLAGS)

report: test
	xsltproc -novalid cunit-to-junit.xsl CUnitAutomated-Results.xml > Test-Results.xml

.PHONY : all
all : fibonacci tests

.PHONY : clean
clean :
	rm -f fibonacci
	rm -f tests
	rm -f CUnit*.xml
	rm -f Test-Results.xml
	rm -f *.o
	rm -f *~
	rm -f src/*~
	rm -f test/*~
