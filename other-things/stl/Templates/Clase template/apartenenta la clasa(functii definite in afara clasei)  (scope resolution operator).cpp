#include <iostream>

using namespace std;

/// :: scope resolution operator

///clasa non-template
class A{
    public:
    void F();         ///Declaratia functiei F()
};
void A::F()        ///Definitia functiei F()
{
    cout<<"clasa non-template\n";
}

///clasa template

template <class U>
class A1{
    public:
    void F1();    ///Declaratie
};
template<typename U>
void A1<U>::F1()   ///Definitie
{
    cout<<"clasa template\n";
}
int main()
{
    A a;
    a.F();

    A1<char> a1;
    a1.F1();
    return 0;
}
