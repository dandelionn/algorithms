#include <iostream>
using namespace std;

template <class T>
T suma(T a,T b)
{
    return a+b;
}
int main()
{
    ///Deducerea argumentului template (AT)
    suma(125, 50);  //AT se deduce ca fiind int
    suma(1.,129.);  //AT se deduce ca fiind double
    suma('R','T');  //AT se deduce ca fiind char
    ///suma(10,20.); //eroare

    ///Specificarea explicita a argumentului template(AT)
    suma<int>(20,8.);   //AT este int
    suma<double>(7,5.); //AT este double
    suma<char>(18,'Y');  //AT este char
    return 0;
}
