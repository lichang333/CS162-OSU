CC = g++
DEBUG = -g
CFLAGS =  $(DEBUG) -std=c++0x
PROGS = dice
MAKEFLAGS = -k

all: $(PROGS)

dice:
	$(CC) $(CFLAGS) Dice.cpp LoadedDice.cpp  main.cpp Game.cpp -o dice
clean:
	rm -f *.o dice