#include <iostream>

class X{/*...*/};            ///Clasa non-template
template <class T> class Y{/*...*/};  ///Clasa template

template<class T=X,int n=20,template <class N> class A=Y>
class B{/*...*/};                       ///Corect

template<class T,int n=20,template <class N> class A=Y>
class C{/*...*/};                       ///Corect

template<class T,int n,template <class N> class A=Y>
class D{/*...*/};                        ///Corect

///template<class T=X,int n,template <class N> class A=Y>
///class E{/*...*/};                        ///Eroare

int main()
{
    return 0;
}
