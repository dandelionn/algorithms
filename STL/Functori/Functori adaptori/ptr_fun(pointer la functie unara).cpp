#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;

bool Pred(int nr)   ///Functie unara (predicat unar)
{ return nr>20; }

int main()
{
    int a[]={20,10,30,10,40};

    ///cauta primul element x>20
    cout<<*find_if(a,a+5,ptr_fun(Pred));
    cout<<*find_if(a,a+5,Pred);

    return 0;
}
