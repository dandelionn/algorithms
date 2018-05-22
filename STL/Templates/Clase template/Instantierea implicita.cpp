#include <iostream>

template <typename T> class A{T n;};

template <typename T> class X;   ///Declaratie
                                 ///X<T> este tip incomplet
int main()
{
    A<int> a;   ///Instantiere implicita A<int>
              ///(se declara un obiect)
    A<char>* p;  ///Nu se instantiaza clasa A<char>
                ///(se declara un pointer)

    X<int>* q;   ///Corect.Instantierea X<int> nu este necesara
    ///X<double> d;  ///Eroare.Pretinde instantiere implicita,
                  ///dar definitia sablonului lipseste
    return 0;

}
