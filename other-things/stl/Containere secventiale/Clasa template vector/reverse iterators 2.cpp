#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> v;
    for(int i=0;i<10;i++)
        v.push_back(i);

    ///Creeaza obiectele r1 si r2 de tip reverse_iterator
    ///din iteratorii v.end() si v.begin()
    vector<int>::reverse_iterator r1(v.end());
    vector<int>::reverse_iterator r2(v.begin());

    while( r1!=r2 )
        cout<<*r1++<<' ';

    return 0;
}
