CC = g++
DEBUG = -g
CFLAGS =  $(DEBUG) -std=c++0x
PROGS = glist
MAKEFLAGS = -k

all: $(PROGS)

shopping_list:
	$(CC) $(CFLAGS) item.cpp dym.cpp main.cpp -o shopping_list
clean:
	rm -f *.o shopping_list