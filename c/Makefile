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
