# See the Makefile for myadd program
# for an example with a similar structure.

C = gcc
CXX = g++ -O0 -std=c++11
#INCLUDES =
#CFLAGS = -g -Wall $(INCLUDES)
#CXXFLAGS = -g -Wall $(INCLUDES)
#LDFLAGS = -g
#LDLIBS =

fluid: main.o fluid.o
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $(LDLIBS) main.o fluid.o -o fluid
main.o: main.cpp fluid.hpp
fluid.o: fluid.cpp fluid.hpp

.PHONY: clean
clean:
	rm -f *.o a.out core fluid 

.PHONY: all
all: clean fluid 
