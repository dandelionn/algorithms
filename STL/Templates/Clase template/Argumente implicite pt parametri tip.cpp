#include <iostream>

class A{/*...*/};

template<typename T=A>
class B{T t;};

///Exemplu in care argumentele implicite sunt instante ale sablonului:
template<typename T1> class A1{/*...*/};
template<typename T1=A1<char> > class B1{/*...*/};
template<typename T1=A1<double> > class C1{/*...*/};

int main()
{
    B<int> ab1;  ///Instantiaza B<int>
    B<>    ab2;  ///Instantiaza B<A>
    ///B    ab3;   ///Eroare

    B1<int> b1;     ///Instantiaza clasa B1<int>
    B1<>    b2;    ///Instantiaza clasa B1<A1<char> >
    ///B1      b3;    ///Eroare

    B1<C1<char*> > b4;   ///Instantiaza clasa B1<C1<char*> >
    B1<C1<> >   b5;     ///Instantiaza clasa B1<C1<A1<double> > >

    ///B<C1>    b6;     ///Eroare
    return 0;
}
