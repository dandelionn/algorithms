#include <iostream>
#include <functional>
#include <algorithm>
using namespace std;

int main()
{
    int *p, a[]={ 5 ,3 ,7, 8};

    ///cauta primul element x din sir,pentru care x>6
    p=find_if(a,a+4,binder2nd<greater<int> >(greater<int>(),6));
    cout<<*p<<" ";                                ///scrieti mai simplu bind2nd(greater<int>,6)

    return 0;
}
