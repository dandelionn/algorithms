#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> v;
    v.reserve(18);   ///Capacitatea devine cel putin 18
    for(int i=0;i<18;i++)
    {
        cout<<v.size()<<' '<<v.capacity()<<'\n';
        v.push_back(i);  ///Nu se mai produce realocarea
    }
    return 0;
}
