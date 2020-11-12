#include <iostream>

using namespace std;

template<class t1,class t2>   ///Sablonul general
void F(t1 a,t2 b)
{
    cout<<a<<' '<<b<<" sablon general\n";
}

template<class T> ///supraincarcare template
void F(T a)
{
    cout<<a<<" supraincarcare template\n";
}

template<>            ///Specializare explicita
void F(int a,char b)
{
    cout<<a<<" "<<b<<" Specializare\n";
}

void F(int a,char b)   ///Supraincarcare non-template
{
    cout<<a<<" "<<b<<" Supraincarcare non-template\n";
}

int main()
{
    F(34 ,2.3);
    F("wooolooolooo!");
    F(20,'R');   ///Apeleaza supraincarcarea non-template
    F<>(20,'R');   ///Apeleaza specializarea

    return 0;
}
