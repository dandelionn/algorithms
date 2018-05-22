#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> v(5);
    cout<<v.size()<<' ';
    v.resize(10,6);
    cout<<v.size()<<' ';
    v.resize(15);
    cout<<v.size()<<' ';
    v.resize(20,7);
    cout<<v.size()<<'\n';

    for(int i=0;i<v.size();i++)
        cout<<v[i]<<' ';
    cout<<'\n';

    v.resize(8);
    for(int i=0;i<v.size();i++)
         cout<<v[i]<<' ';
    cout<<'\n';
    v.resize(10);
    for(int i=0;i<v.size();i++)
         cout<<v[i]<<' ';
    return 0;
}
