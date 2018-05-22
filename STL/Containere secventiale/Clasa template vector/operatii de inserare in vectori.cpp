#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

typedef vector<int>::iterator It;

int main()
{
    vector<int> v;
    v.reserve(7);
    v.push_back(2);
    v.push_back(1);
    v.push_back(0);
    v.push_back(7);
    v.push_back(3);
    v.push_back(9);

    It it1(v.begin()+1);
    It it2(v.begin()+5);
    assert(*it1==1 && *it2==9);

    ///Insereaza 8 inaintea pozitiei indicate de it1
    It it=v.insert(it1,8);

    ///it indica pozitia elementului inserat
    assert(*it==8);

    for(it=v.begin();it!=v.end();++it)
       cout<<*it<<' ';

    ///Asertiunea esueaza; it1 este invalidat
    //assert(*it1==1);

    ///Asertiunea esueaza; it2 este invalidat
    //assert(*it2==9);

    return 0;
}
