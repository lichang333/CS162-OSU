CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -Wall
CXXFLAGS += -pedantic-errors
CXXFLAGS += -g

SRCS =  FibonacciNR.cpp FibonacciClass1.cpp Program.cpp

PROG1 = main
PROGS = ${PROG1}

all:
	${CXX} ${CXXFLAGS} ${SRCS} -o ${PROG1}

clean:
		rm -f *.o main
