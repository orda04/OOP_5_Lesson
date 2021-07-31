#include <iostream>
#include <string>
#include<vector>
#include"black_jack.h"

using namespace std;
/*
enum suit
{HEARTS=1,
    DIAMONDS=2,
          CLUBS=3,
             SPADES=4 };
enum rank_1
{ACE=1,
    DOUBLE=2,
       TRIPLE=3,
          FOUR=4,
             FIVE=5,
                SIX=6,
                  SEVEN=7,
                     EIGHT=8,
                        NINE=9,
                           TEN=10,
                              JACK=11,
                                 QUEEN=12,
                                    KING=13};

class Card// карта
{
    bool m_IsFaseUp;

     suit m_suit;
     rank_1 m_rank;  //тип назван через 1 потому как  в  QT есть конфликт с этим словом //rank m_rank;


   public:
    Card(suit sit,rank_1 rank,bool face=false): m_suit(sit),m_rank(rank),m_IsFaseUp(face)
      {
      }

     void Flip()  //
       {
        if(m_IsFaseUp)
        {
            m_IsFaseUp=false;
        }
        else
        {
            m_IsFaseUp=true;
        }
       }
    int GetValue()
    {
        return m_rank;
    }

};
class Hand  // коллекция карт на руках
{
 vector <Card> m_Cards;

public:
 void Add(Card* pCard);
 void Clear();
 int GetTotal();
};


class GenericPlayer:public Hand
{
 string m_name;
public:
 virtual bool IsHitting() const=0;
 bool IsBoosted() const;
 void Bust() const;
};
class Player:public GenericPlayer
{
public:
    virtual bool isHitting() const;
    void Win() const;
    void Lose() const;
    void Push() const;
};
class House:public GenericPlayer
{
  public:
    virtual bool isHitting() const;
    void FlipFirstCarf();
};
class Deck: public Hand
{
public:
    void Populate();
    void Shuffle();
    void Deal (Hand& aHand);
    void AdditionalCards(GenericPlayer aGenericPlayer);
};

class Game
{
 Deck m_Deck;
 House m_House;
 vector<Player> m_players;
public:
 void Play();
};
*/
int main()
{
  cout<<"\t\t Welcome to BlackJAck\n\n";

  int numPlayers=0;
  while(numPlayers<1||numPlayers>7)
  {
   cout<<"How many players(1-7): ";
   cin>>numPlayers;
  }
vector<string> names;
string name;
for(int i=0;i<numPlayers;++i)
{
 cout<<"Enter Player Name: ";
 cin>>name;
 names.push_back(name);
}
cout<<endl;
Game aGame(names);
char again='y';
while (again != 'n' && again != 'N')
    {
      aGame.Play();
      cout<<"\nDo You want to play again (Y/N):";
      cin>>again;
    }
    return 0;
}
