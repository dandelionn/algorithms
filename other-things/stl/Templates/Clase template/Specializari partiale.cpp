#include <iostream>

template <class T1, class T2> class A{/*...*/};  ///Sablon primar

template <class T> class A<T,char>{/*...*/};   ///Specializare

template <class T> class A<float,T>{/*...*/};   ///Specializare

///Declaratia sablonului primar.Definitie incompleta
template<class T1,class T2> class D;

template<class T> class D<char,T>{/*...*/};  ///Specializare
                                             ///partiala
template<> class D<int, double>{/*...*/};    ///Specializare
                                             ///explicita

int main()
{                         ///Se instantiaza:
    A<char, char> a1;    ///-specializarea A<T,char>
    A<char,int> a2;      ///-specializarea A<T1,T2>
    A<float,int> a3;     ///-specializarea A<float,T>
    return 0;
}
