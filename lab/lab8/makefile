CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -Wall
CXXFLAGS += -pedantic-errors
CXXFLAGS += -g
SRC1 = Queue.cpp
SRC2 = QueueIter.cpp
SRC3 = main.cpp
SRCS = ${SRC1} ${SRC2} ${SRC3}

HEADER1 = Queue.hpp
HEADER2 = QueueIter.hpp
HEADERS = ${HEADER1} ${HEADER2}

PROG1 = main
PROGS = ${PROG1}


all:
	${CXX} ${CXXFLAGS} ${SRCS} -o ${PROG1}

clean: 
	rm -f ${PROGS} *.o *~

