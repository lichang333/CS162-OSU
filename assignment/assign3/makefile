CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -Wall
CXXFLAGS += -pedantic-errors
CXXFLAGS += -g
SRCS =  Barbarian.cpp BlueMen.cpp Creature.cpp HarryPotter.cpp RunFight.cpp
SRCS += Medusa.cpp Vampires.cpp test.cpp 

PROG1 = test
PROGS = ${PROG1}

all:
	${CXX} ${CXXFLAGS} ${SRCS} -o ${PROG1}

clean:
		rm -f *.o test
