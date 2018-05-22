#include <iostream>

//clasa non-template

class A;       ///Declara clasa A

class B{int n;};   ///Defineste clasa B

//clasa template

template <typename T>     ///Declara clasa template D<T>
class D;

template <typename T>    ///Defineste clasa template G<T>
class G{T n;};

template<class T1,class T2>   ///Defineste clasa template X<T1,T2>
class X{
T1 x;     ///x,y - date membre de tip generic
T2 y;
};

int main()
{
    return 0;
}
