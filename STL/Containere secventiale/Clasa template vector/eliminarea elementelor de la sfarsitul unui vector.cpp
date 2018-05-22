#include <iostream>
#include <vector>
#include <cassert>   ///sau assert.h
using namespace std;

int main()
{
    vector<char> v;
    for(char c='A';c<='E';c++)
       v.push_back(c);
    assert(v.size()==5&&!v.empty());
    assert(v[4]=='E'&&v.back()=='E');
    assert(v[0]=='A'&&v.front()=='A');

    v.pop_back(); ///Sterge ultimul element din vector (v[4])
    assert(v.size()==4);

    v.clear(); ///Sterge toate elementele din vector
    assert(v.size()==0&&v.empty()==true);
    return 0;
}
