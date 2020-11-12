#include <iostream>

template<template<typename T> class A>  ///Corect, class este permis
void F(A<char> a)
{
    std::cout<<"template template\n";
}

template<template<typename T1> struct A1>  ///Ilegal, struct nu e permis
void F(A1<int> a1)
{
    std::cout<<"template template\n";
}

template<template<typename T2> union A2>  ///Ilegal, union nu e permis
void F(A2<double> a2)
{
    std::cout<<"template template\n";
}

int main()
{
}
