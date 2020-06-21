#!make -f

CXX=clang++-9 
CXXFLAGS=-std=c++2a

HEADERS=range.hpp accumulate.hpp filterfalse.hpp compress.hpp doctest.h
OBJECTS= 

run: demo
	./$^

demo: Demo.o $(OBJECTS)
	$(CXX) $(CXXFLAGS) $^ -o demo

test: TestCounter.o Test.o $(OBJECTS)
	$(CXX) $(CXXFLAGS) $^ -o test

testsnir:  TestCounter.o testsnir.o $(OBJECTS)
	$(CXX) $(CXXFLAGS) $^ -o testsnir

%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) --compile $< -o $@

clean:
	rm -f *.o demo test
