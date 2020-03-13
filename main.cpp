#include <bits/stdc++.h>
using namespace std;
string SUITS[4] = {"CLUB","DIAMOND","HEART","SPADE"};//type of suits in the deck of cards
string TYPE[13] = {"2","3","4","5","6","7","8","9","10","J","Q","K","A"};//types of faces in the deck of cards
//makes a card
class Card
 {
	public :
		string suit;
		string number;
		Card(){};
		Card(string s, string num);

};
vector<Card> deckOfCards;
vector<Card>p1;
vector<Card>p2;
//assign the values in the card
Card::Card(string s,string num) {
    suit=s;
    number=num;
}


//This class will hold all 52 card
class Deck : public Card{
    public:
	Deck();
	void show();
	void shuffle();
	//~Deck();
};

class Game: public Deck
{
    public:
    Game();
    void start();
};

//Constructor will produce a new deck of cards and arrange them in sequence
Deck::Deck() {
	for(int i = 0 ; i < 4 ; ++i)
		for(int j = 0 ; j < 13 ; ++j)
			deckOfCards.emplace_back(Card(SUITS[i],TYPE[j]));
}

/*
//to check the deck of cards
void Deck::show() {

	auto it = deckOfCards.begin();
	while (it != deckOfCards.end()) {
		cout<<it->suit<<" ";
		cout<<it->number<<endl;

		it = next(it);
	}
	cout<<endl;

}*/

//shuffle function
void Deck::shuffle()
 {
	srand(time(NULL));
	random_shuffle(deckOfCards.begin(),deckOfCards.end());
}
//using constructor for distributing cards into two players
Game:: Game()
{

    for(int i=0;i<deckOfCards.size();i++)
    {
        if(i%2==0)
            p1.push_back(deckOfCards[i]);
        else
             p2.push_back(deckOfCards[i]);
    }


}
//to find the index of suit
int sfindindex(string s)
{
    for(int i=0;i<4;i++)
    {
        if(SUITS[i]==s)
            return i;
    }
}
//to find the index of number
int  nfindindex(string s)
{
    for(int i=0;i<13;i++)
    {
        if(TYPE[i]==s)
            return i;
    }
}
//for starting the game
void Game::start()
{int k=1;
    while(1)
    {
        Card a;
        Card b;
        a.suit=p1.begin()->suit;
        cout<<a.suit<<" ";
        a.number=p1.begin()->number;
        cout<<a.number<<" ";
        b.suit=p2.begin()->suit;
        cout<<b.suit<<" ";
        b.number=p2.begin()->number;
        cout<<b.number<<endl;
        p1.erase(p1.begin());
        p2.erase(p2.begin());
        int p1s=sfindindex(a.suit);
        int p2s=sfindindex(b.suit);
        int p1f=nfindindex(a.number);
        int p2f=nfindindex(b.number);

    if(p1s==p2s)//if both the players have suits are same
        {
            if(p1f>p2f)
            {
                p1.push_back(a);
                p1.push_back(b);

            }
           else
            {
                p2.push_back(b);
                p2.push_back(a);
            }

        }
    else//if both players have different type of suit
        {
            if(p1f==p2f)
            {
                if(p1s>p2s)
                {
                p1.push_back(a);
                p1.push_back(b);
                }
                else
                {
                p2.push_back(b);
                p2.push_back(a);
                }
            }
            else
            {
                if(p1f>p2f)
            {
                p1.push_back(a);
                p1.push_back(b);
            }
                else
            {
                p2.push_back(b);
                p2.push_back(a);
            }

            }
        }
        cout<<"Player 1 Deck size = "<<p1.size()<<endl;
        cout<<"Player 2 Deck size = "<<p2.size()<<endl;

        if(p1.size()==52)
            {
            k=1;
            break;
            }
        else if(p2.size()==52)
            {
            k=2;
            break;
            }
    }
    if(k==1)
        cout<<"Player 1 Won"<<endl;
    else if(k==2)
        cout<<"Player 2 Won"<<endl;

}



int main() {
	Game g;
	g.start();
}
