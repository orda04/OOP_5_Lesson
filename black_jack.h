#ifndef BLACK_JACK_H
#define BLACK_JACK_H
#include <iostream>
#include <string>
#include<vector>


using namespace std;


class Card// карта
{
   public:
     enum suit
     {CLUBS,
         DIAMONDS,
               HEARTS,
                  SPADES };
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

    Card(rank_1 rank=ACE,suit suit=SPADES,bool ifu=true): m_rank(rank),m_suit(suit),m_IsFaseUp(ifu)
      {
      }

     int GetValue()const;
     void Flip();  //

private:
  bool m_IsFaseUp;
   suit m_suit;
   rank_1 m_rank;  //тип назван через 1 потому как  в  QT есть конфликт с этим словом //rank m_rank;

};
class Hand  // коллекция карт на руках
{
public:
 vector <Card> m_Cards;
 Hand();
 virtual ~Hand();
 void Add(Card* pCard);
 void Clear();
 int GetTotal() const;

protected:
 //vector <Card> m_Cards;
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
 //House m_House;
 vector<Player> m_players;
public:
 void Play();
};

#endif // BLACK_JACK_H
