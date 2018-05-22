#include <set>
#include <iostream>
using namespace std;

int main()
{
    int a[]={45,10,23};
    set<int> s(a,a+3);

    if( s.key_comp()(23,10) )
        cout<<"true"<<'\n';

    if( s.value_comp()(23,10) )
        cout<<"true\n";

    return 0;
}
