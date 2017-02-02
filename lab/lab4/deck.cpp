#include<iostream>
#include<string>
#include<ctime>
#include<cstdlib>
#include "deck.h"

using namespace std;

deck::deck(){}

void deck::set_deck()
{
	string c = "♣", s = "♠", h = "♥", d = "♦", str;
	int trace = 0;

	for (int i = 0; i < 4; i++)
	{
		switch (i)
		{
		case 0:
			str = c;
			break;
		case 1:
			str = s;
			break;
		case 2:
			str = h;
			break;
		case 3:
			str = d;
			break;
		}

		for (int j = 0; j < 13; j++)
		{
			cards[trace].set(str, j + 1);
			trace += 1;
		}
	}

	shuffle();
}

deck::~deck()
{
	//cout << "des in deck." << endl;
}

void deck::display()
{
	for (int i = 0; i < 52; i++)
	{
		cards[i].display();
	}
}

void deck::shuffle()
{
	given_cards_num = 0;

	if (given_cards_num == 0)
	{
		srand(time(NULL));
		card temp;
		temp.set("abc", 99);

		for (int i = 0; i < 999; i++)
		{
			int t = rand() % 52;
			temp = cards[0];
			cards[0] = cards[t];
			cards[t] = temp;
		}
	}
}

void deck::renew()
{
	given_cards_num = 0;
	set_deck();
	shuffle();
}
