#include "Ant.h"

Ant::Ant(int rIndex, int cIndex, EDIRECT direc) :rowIndex(rIndex), columnIndex(cIndex), direct(direc), sign('*')
{

}

void Ant::setRowIndex(int rowIndex){
	this->rowIndex = rowIndex;
}

int Ant::getRowIndex() const {
	return rowIndex;
}

void Ant::setColumnIndex(int columnIndex){
	this->columnIndex = columnIndex;
}

int Ant::getColumnIndex() const {
	return columnIndex;
}

void Ant::setSign(char sign){
	this->sign = sign;
}

char Ant::getSign() const {
	return sign;
}

void Ant::setDirect(EDIRECT direct){
	this->direct = direct;
}

EDIRECT Ant::getDirect() const {
	return direct;
}