CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -Wall
CXXFLAGS += -pedantic-errors
CXXFLAGS += -g

SRC1 = valid_check.cpp
SRC2 = main.cpp
SRCS = ${SRC1} ${SRC2}

HEADER1 = valid_check.hpp 
HEADERS = ${HEADER1}

PROG1 = main
PROGS = ${PROG1}

all:
	${CXX} ${CXXFLAGS} ${SRCS} -o ${PROG1}

clean: 
	rm -f ${PROGS} *.o *~

