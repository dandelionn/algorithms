#include <iostream>
#include <algorithm>
#include <functional>
#include <iterator>
using namespace std;

template <class T>
bool Pred(T a,T b)   ///Predicat binar
{
    return a<b;
}
int main()
{
    int a[]={20,10,30,10,40};
    sort(a,a+5,not2(ptr_fun(Pred<int>)));
    copy(a,a+5,ostream_iterator<int>(cout," "));

    return 0;
}
