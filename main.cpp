#include <iostream>
#include <string>

using namespace std;

template <class T>
class Pair1
{
private:
    T a;
    T b;
public:

Pair1(const T& m_first,const T& m_second): a(m_first),b(m_second)
{
}
T&  first()
{
   return a;
}
const T&first()const
{
    return a;
}

T& second()
{
   return b;
}
const T&second()const
{
    return b;
}
};


template <class T, class S>
class Pair
{
  T a;
  S b;
public:

  Pair(const T& m_first,const S& m_second): a(m_first),b(m_second)
  {
  }
  T&  first()
  {
     return a;
  }
  const T&first()const
  {
      return a;
  }

  S& second()
  {
     return b;
  }
  const S&second()const
  {
      return b;
  }

};

template <class S>
class StringValuePair:public Pair<string,S>
{
public:
    StringValuePair(const string&key, const S& value):Pair<string,S>(key,value)
    {}
};
int main()
{
    Pair1<int> p1(6, 9);
    cout << "Pair1: " << p1.first() << ' ' << p1.second() << '\n';

    const Pair1<double> p2(3.4, 7.8);
    cout << "Pair1: " << p2.first() << ' ' << p2.second() << '\n';


    Pair<int, double> p3(6, 7.8);
    cout << "Pair: " << p3.first() << ' ' << p3.second() << '\n';

    const Pair<double, int> p4(3.4, 5);
    cout << "Pair: " << p4.first() << ' ' << p4.second() << '\n';


    StringValuePair<int> svp("Amazing", 7);
    std::cout << "Pair: " << svp.first() << ' ' << svp.second() << '\n';
    return 0;
}
