#include <functional>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int a[] = {5, 2, 4, 9};

    ///Sterge primul element x din sir, pentru care 5 < x
    int *p=remove_if(a,a+4,binder1st<less<int> >(less<int>(),5));
                                       ///scrieti mai simplu bind1st(less<int>(),5).
    for(int* it=a; it!=p; ++it)
        cout<<*it<<' ';
}
