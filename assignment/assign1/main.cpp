/******************************************************
** Program: Langton's ant
** Author: Chang Li
** Date: 10/05/2016
** Description: This program is a simulator to Langton's ant
** Input: choice, row, column, steps, rIndex, cIndex, facing
** Output: Menu(), run()
******************************************************/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <fstream>
#include "Graph.h"
#include "Ant.h"
using namespace std;

/* Check the user's inputs are legal input or not */
bool validateRowColumn(int row, int column, int minRow, int maxRow, int minColumn, int maxColumn){
	return (row <= minRow || row > maxRow || column <= minColumn || column > maxColumn);
}


/*initialize the row and column, set up the ant's location and  */
void run(){
	int row, column;
	int steps;
	int rIndex, cIndex;
	EDIRECT eDirect;
	char current;
	while (true){
		cout << "Please enter the number of rows and columns:(the maxmum of both are 1000,the minmum of both are 1)" << endl;
		cin >> row >> column;
		if (!validateRowColumn(row, column, 0, 1000, 0, 1000))
			break;
		cout << "Invalid input." << endl;
	}
	Graph graph1(row, column);

	while (true){
		cout << "Please enter the steps(larger than 0, suggest serveral hundreds or 10k):" << endl;
		cin >> steps;
		if (steps >= 0)
			break;
	}
	while (true)
	{
		bool flag = false;
		cout << "1.random location:" << endl;
		cout << "2.specify location:" << endl;
		int choice = 0;
		cin >> choice;
		switch (choice){
		case 1:						//random location
			srand(time(0));
			rIndex = abs(rand() % row);
			cIndex = abs(rand() % column);
			eDirect = EDIRECT(abs(rand() % 4));
			flag = true;
			break;
		case 2:						//pick up location
			int facing;
			cout << "Please input the location, 'x y direction', direction can be wirtten as integer from 0 to 3. (direction: 0: UP;1: DOWN;2: LEFT;3: RIGHT) " << endl;
			cin >> rIndex >> cIndex >> facing;
			if (validateRowColumn(rIndex, cIndex, 0, row, 0, column)){
				cout << "Invalid input." << endl;
				break;
			}
				
			if (facing >= 0 && facing < 4){
				eDirect = EDIRECT(facing);
				flag = true;
			}
			break;
		default:
			break;
		}
		if (flag)break;
	}
	Ant ant(rIndex, cIndex, eDirect);

	current = graph1.getGraph(ant.getRowIndex(), ant.getColumnIndex());
	graph1.getGraph(ant.getRowIndex(), ant.getColumnIndex()) = ant.getSign();
	for (int i = 1; i <= steps; ++i)
	{
//		system("clear");//clear the screen
		cout << "step " << i << ":" << endl;
		graph1.printGraph();
		if (current == Graph::COLOR[BLACK]){
// in the Black block
			cout << "Background colour:" << "black" << endl;
			switch (ant.getDirect()){
			case UP:
				ant.setDirect(LEFT);
				cout << "Ant's facing:" << "left"<< endl;
				break;
			case DOWN:
				ant.setDirect(RIGHT);
				cout << "Ant's facing:" << "right" << endl;
				break;
			case LEFT:
				ant.setDirect(DOWN);
				cout << "Ant's facing:" << "down" << endl;
				break;
			case RIGHT:
				ant.setDirect(UP);
				cout << "Ant's facing:" << "up" << endl;
				break;
			}
			graph1.getGraph(ant.getRowIndex(), ant.getColumnIndex()) = Graph::COLOR[WHITE];
		}
		else{
// in the White block			
			switch (ant.getDirect()){
			case UP:
				ant.setDirect(RIGHT);
				cout << "Ant's facing:" << "right" << endl;
				break;
			case DOWN:
				ant.setDirect(LEFT);
				cout << "Ant's facing:" << "left" << endl;
				break;
			case LEFT:
				ant.setDirect(UP);
				cout << "Ant's facing:" << "up" << endl;
				break;
			case RIGHT:
				ant.setDirect(DOWN);
				cout << "Ant's facing:" << "down" << endl;
				break;
			}
			cout << "Background colour:" << "white" << endl;
			graph1.getGraph(ant.getRowIndex(), ant.getColumnIndex()) = Graph::COLOR[BLACK];
		}
//Move. and move back if hit the boundary.
		switch (ant.getDirect()){
		case UP:
			if (ant.getRowIndex() - 1 >= 0)
				ant.setRowIndex(ant.getRowIndex() - 1);
			else if (ant.getRowIndex() + 1 < graph1.getRow())
				ant.setRowIndex(ant.getRowIndex() + 1);
			break;
		case DOWN:
			if (ant.getRowIndex() + 1 < graph1.getRow())
				ant.setRowIndex(ant.getRowIndex() + 1);
			else if (ant.getRowIndex() - 1 >= 0)
				ant.setRowIndex(ant.getRowIndex() - 1);
			break;
		case LEFT:
			if (ant.getColumnIndex() - 1 >= 0)
				ant.setColumnIndex(ant.getColumnIndex() - 1);
			else if (ant.getColumnIndex() + 1 < graph1.getColumn())
				ant.setColumnIndex(ant.getColumnIndex() + 1);
			break;
		case RIGHT:
			if (ant.getColumnIndex() + 1 < graph1.getColumn())
				ant.setColumnIndex(ant.getColumnIndex() + 1);
			else if (ant.getColumnIndex() - 1 >= 0)
				ant.setColumnIndex(ant.getColumnIndex() - 1);
			break;
		}
		current = graph1.getGraph(ant.getRowIndex(), ant.getColumnIndex());
		graph1.getGraph(ant.getRowIndex(), ant.getColumnIndex()) = ant.getSign();
	}
}

/*Initialize the user Menu*/
void Menu(){
	bool flag = true;
	while (flag){
		int choice;
		cout << "Welcome to Langton's ant" << endl;
		cout << "1.Start to Langton's ant" << endl;
		cout << "2.Exit the program." << endl;
		cin >> choice;
		if(cin.fail()){
   			break;
   		}
		switch (choice){
		case 1:
			system("clear");	//clear the screen
			run();
			break;
		case 2:
			flag = false;
			break;
		default:
			break;
		}
	}
}

int main()
{
	Menu();
	return 0;
}