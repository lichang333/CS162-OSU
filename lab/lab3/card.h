class card{
    private:
        int value; //1-13
        char *suit;
    public:
        card(char *, int);
        void print();

    //              
    //
};


//定义构造函数 constructor
Card::Card(char *suit, int value){
    suit = suit1;
    value = value1;
}

//destructor

//class Card 
{

private:
	char * suit;
	Card( Card const & other );                // disable copy construction
	Card& operator = ( Card const & other );   // disable assignment

public:
	Card( void ) : data( new suit[ 14 ] ) { std::strcpy( data, "...." ); } 
      ~Card( void ) { delete [] data; }
};