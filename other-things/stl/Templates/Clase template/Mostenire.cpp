#include <iostream>

class A{/*...*/};  ///A-clasa de baza
class B:public A{/*...*/};   ///B-clasa derivata

///Clasa sablon mosteneste o clasa non-template:

class A1{/*...*/};

template <typename T>
class B1: public A1{
    T d;
    //...
};
int main()
{
    B1<int> ob; ///Corect. T==int
}
