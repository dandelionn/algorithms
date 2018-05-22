#include <iostream>
using namespace std;

template<class T>
void F(T a)
{
    cout<<a<<'\n';
}
/*template <class T1=int,int n=9>  ///Ilegal
void F(t1 t)
{
    cout<<t<<'\n';
}*/

template <class T1, class T2>
void F(T1 t1=20,T2 t2='y')
{
    cout<<t1<<' '<<t2<<'\n';
}
int main()
{
    F(20);///Argumentul de apel este 20
          ///Argumentul template este dedus ca fiind int
          ///din tipul constantei 20

    F<int,char>(); ///Arg. template : T1==int,T2==char
                  ///Arg. de apel: t1==20,t2=='y'
    F<int,char>(235); ///t1=235,t2=='y'
    F<int,char>(235,'j'); ///t1==235,t2='j'
    ///F();   ///Ilegal. Compilatorul nu deduce T1 si T2
    F(234,'j');
    return 0;
}
