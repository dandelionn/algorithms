#include <iostream>
using namespace std;

template <typename T>

void F(T x)
{
    cout<<x<<'\n';
}
template <typename T1,typename T2,typename T3>
void f(T1 x,T2 y,T3 z)
{
    cout<<x<<' '<<y<<' '<<z<<'\n';
}
int main()
{
    F(5643);
    F('T');
    F(11.35);
    F("Old Kinderbook!");
    cout<<'\n';
    f(1.0,3,'Y');
    f("Old",'I','a');

    return 0;
}
