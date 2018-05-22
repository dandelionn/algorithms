#include <iostream>

class D{/*...*/};       ///Clasa non-template
template<class T=D> class B{/*...*/};    ///Clasa template

template<class T=int> class C{/*...*/};///Clasa template

template<template<class> class X=B> class A{/*...*/};

int main()
{
    A<C> a1; ///Corect. X==C, C<T>==C<int>
    A<>  a2; ///Corect. X==B, B<T>==B<D>
    ///A<D> a3; ///Eroare. D nu este sablon de clasa
    return 0;
}
