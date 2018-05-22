#include <iostream>

template <class T> class Baza{/*...*/};

template <class T1,class T2>
class Derivat:public T2{   ///Derivat mosteneste in mod public clasa T2
    T1 t;
};
int main()
{
    Derivat<int,Baza<char> > a1;  ///Corect. T1==int
                                         /// T2==Baza<char>
    ///Derivat<int, char>     a2;  ///Eroare. char nu este un tip clasa

    return 0;
}
