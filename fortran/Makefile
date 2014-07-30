SRC=src/fibonacci.f90
TESTSRC=test/fruit_helpers.F90 test/fibonacci_test.f90 test/fruit_test_driver.F90
FRUIT_SRC=fruit/fruit_util.f90 fruit/fruit.f90

fibonacci : $(SRC) src/fibonacci_program.f90
	gfortran -O0 --std=f2003 $^ -o $@

tests : $(FRUIT_SRC) $(SRC) $(TESTSRC)
	gfortran -O0 --std=f2003 $^ -o $@

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
