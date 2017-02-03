#ifndef ANT_H
#define ANT_H
enum EDIRECT{
	UP,
	DOWN,
	LEFT,
	RIGHT
};
class Ant{
	int rowIndex;
	int columnIndex;
	EDIRECT direct;
	char sign;
public:
	Ant(int rIndex = 0, int cIndex = 0, EDIRECT direc = LEFT);
	void setRowIndex(int rowIndex);
	int getRowIndex() const;
	void setColumnIndex(int columnIndex);
	int getColumnIndex() const;
	void setSign(char sign);
	char getSign() const;
	void setDirect(EDIRECT direct);
	EDIRECT getDirect() const;
};
#endif