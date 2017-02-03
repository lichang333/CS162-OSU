CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -Wall
CXXFLAGS += -pedantic-errors
CXXFLAGS += -g


SRC1 = stack_like.cpp
SRC2 = queue_like.cpp
SRC3 = main.cpp
SRCS = ${SRC1} ${SRC2} ${SRC3}


HEADER1 = stack_like.hpp
HEADER2 = queue_like.hpp
HEADERS = ${HEADER1} ${HEADER2}


PROG1 = main
PROGS = ${PROG1}



all:
	${CXX} ${CXXFLAGS} ${SRCS} -o ${PROG1}

clean: 
	rm -f ${PROGS} *.o *~

