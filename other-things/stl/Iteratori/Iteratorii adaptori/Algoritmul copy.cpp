#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    int a[]={1, 2, 3, 4 ,5};
    vector<int> v(10);   ///v=[0, 0, 0, 0, 0, 0, 0, 0, 0, 0]

    ///Copiaza elementele 1, 2, 3, 4, 5 in v[0], v[1],...v[4]
    copy(a,a+5,v.begin());

    ///Scrie :1 2 3 4 5 0 0 0 0 0
    for(int i=0;i<v.size();i++)
        cout<<v[i]<<" ";

    return 0;
}


