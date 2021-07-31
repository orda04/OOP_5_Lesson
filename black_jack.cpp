#include "black_jack.h"

void Card::Flip()
{
    m_IsFaseUp=!(m_IsFaseUp);
}

int Card::GetValue() const
{
    int value =0;
    if(m_IsFaseUp)
    {
        value=m_rank;

        if(value>10)
          {
             value=10;
          }
     }
    return value;
}

//--------------------------------------------------
Hand::Hand()
{
    m_Cards.reserve(7);
}
Hand::~Hand()
{
    Clear();
}
void Hand::Add(Card *pCard)
{
    m_Cards.push_back(pCard);
}
void Hand::Clear()
{
 vector<Card*>::iterator iter=m_Cards.begin();
 for(iter =m_Cards.begin();iter!=m_Cards.end();++iter)
    {
     delete *iter;
     *iter=0;
    }
 m_Cards.clear();
}
int Hand::GetTotal() const
{
    if(m_Cards.empty())
    {
        return 0;
    }
    if(m_Cards[0].GetValue()==0)
    {
        return 0;
    }
    int total = 0;
    vector<Card*>::const_iterator iter;
    for(iter=m_Cards.begin();iter!=m_Cards.end();++iter)
    {
        total+=(*iter)->GetValue();
    }
    if(containsAce&&total<=11)
    {
        total+=10;
    }
    return total;
}


