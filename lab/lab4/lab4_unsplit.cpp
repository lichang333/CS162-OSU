#include<iostream>
#include<string>
#include<ctime>
#include<cstdlib>

using namespace std;

void int_check(string &);

class card
{
private:
	string suit;
	int value;

public:
	card(){}

	void set(string str, int n)
	{
		suit = str;
		value = n;
	}

	string get_suit()
	{
		return suit;
	}

	int get_value()
	{
		return value;
	}

	~card()
	{
		//cout << "des in card." << endl;
	}

	void display()
	{
		cout << suit << "\t" << value << endl;
	}
};

class deck
{
private:
	card cards[52];
	int given_cards_num;

public:
	deck(){}

	void set_deck()
	{
		string c = "club", s = "spade", h = "heart", d = "diamond", str;
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

	card get_cards()
	{
		return cards[52];
	}

	~deck()
	{
		//cout << "des in deck." << endl;
	}

	void display()
	{
		for (int i = 0; i < 52; i++)
		{
			cards[i].display();
		}
	}

	void shuffle()
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

	void renew()
	{
		given_cards_num = 0;
		set_deck();
		shuffle();
		cout << "cards used up." << endl;
	}
};

class hand
{
private:
	card *hand_card;
	int cards_num;

public:
	hand(){}

	hand(const hand &other)
	{
		cards_num = other.cards_num;
		hand_card = other.hand_card;
	}

	void pass(card *cards, int located)
	{
		cards_num = 2;

		hand_card = new card[cards_num];

		for (int i = 0; i < cards_num; i++)
		{
			hand_card[i] = cards[located];
			located += 1;
		}
	}

	void d_hand_card()
	{
		delete[] hand_card;
	}

	void d_temp(card *temp)
	{
		delete[] temp;
	}

	void hit(card cards[], int located)
	{
		cards_num += 1;

		card *temp;
		temp = new card[cards_num];

		for (int i = 0; i < cards_num - 1; i++)
		{
			temp[i] = hand_card[i];
		}

		temp[cards_num - 1] = cards[located];
		//delete hand card
		d_hand_card();

		hand_card = new card[cards_num];
		hand_card = temp;

		d_temp(temp);
	}

	card *get_hand_card()
	{
		return hand_card;
	}

	int get_cards_num()
	{
		return cards_num;
	}

	void operator = (const hand &other)
	{
		cards_num = other.cards_num;
		hand_card = other.hand_card;
	}

	~hand(){}
};

class player
{
private:
	hand *pl_hand;
	int playing_total;
	int card_total;
	int bet;

public:
	player()
	{
		pl_hand = new hand[2];
	}
	//playing total
	void set_playing_total(int n)
	{
		playing_total = n;
	}

	int get_playing_total()
	{
		return playing_total;
	}
	//bet
	void set_bet(int n)
	{
		bet = n;
	}

	int get_bet()
	{
		return bet;
	}
	/*/card total (in class game)
	void set_card_total(int n)
	{
	card_total = 0;

	for (int i = 0; i < pl_hand[n].get_cards_num; i++)
	{
	card_total += pl_hand[n].get_cards_num[i];
	}


	}*/
	//set card total
	void set_card_total(int n)
	{
		card_total = n;
	}

	~player(){}
};

class dealer
{
private:
	hand *de_hand;
	int card_total;

public:
	dealer()
	{
		de_hand = new hand[2];
	}

	~dealer(){}

	void set_card_total(int n)
	{
		card_total = n;
	}

	void display()
	{

	}

	void final_display()
	{

	}
};

class game
{
private:
	deck cards;
	player *players;
	dealer game_dealer;
	int num_players;

public:
	game(){}

	void set_num_players()
	{
		string player_num;

		cout << "how many players: ";
		cin >> player_num;

		int_check(player_num);

		num_players = atoi(player_num.c_str());

		cout << num_players << endl;
	}

	void set_players()
	{
		players = new player[num_players];
	}

	player *get_players()
	{
		return players;
	}

	dealer get_dealer()
	{
		return game_dealer;
	}

	void set_cards(deck c)
	{
		cards = c;
	}

	deck get_cards()
	{
		return cards;
	}

	~game(){}

	void d_players()
	{
		delete[] players;
	}


};

//check if it is int.
void int_check(string &str)
{
	for (int i = 0; i < strlen(str.c_str()); i++)
	{
		if (str.at(i) < 48 || str.at(i) > 57)
		{
			cout << "need int." << endl << "input: ";
			cin >> str;
			i = -1;
		}
	}
}

int main()
{

	return 0;
}