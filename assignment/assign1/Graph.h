#ifndef GRAPH_H
#define GRAPH_H
#include <cstdlib>
#include <ctime>
#include <iostream>
enum color{
	BLACK,
	WHITE
};

/*let nullptr(C++11) is workable on the flip server*/
const class nullptr_t
{
public:
    template<class T>
    inline operator T*() const
        { return 0; }

    template<class C, class T>
    inline operator T C::*() const
        { return 0; }
 
private:
    void operator&() const;
} nullptr = {};
/****************************************************/


class Graph{
private:
	char **graph;
	int row;
	int column;
	void initGraph(){
		srand(time(0));
		graph = new char*[row];
		for (int i = 0; i < row; ++i){
			graph[i] = new char[column];
		}
		for (int i = 0; i < row; ++i){
			for (int j = 0; j < column; ++j){
				int randnum = rand() % 2;
				graph[i][j] = COLOR[randnum];
			}
		}
	}
	void destroyGraph(){
		for (int i = row - 1; i >= 0; --i){
			delete[] graph[i];
			graph[i] = nullptr;
		}

		delete[] graph;
		graph = nullptr;
	}

public:

	static const char COLOR[2];
	Graph(int row, int column){
		this->row = row;
		this->column = column;
		initGraph();
	}
	~Graph(){
		destroyGraph();
	}
	int getRow() const{
		return row;
	}
	int getColumn() const{
		return column;
	}
	void printGraph() const{
		for (int i = 0; i < row; ++i){
			for (int j = 0; j < column; ++j){
				std::cout << graph[i][j];
			}
			std::cout << std::endl;
		}
	}
	char &getGraph(int rIndex, int cIndex){
		return graph[rIndex][cIndex];
	}

};
//COLOR[0]:BLACK COLOR[1]:WHITE
const char Graph::COLOR[2] = { '#', ' ' };

#endif