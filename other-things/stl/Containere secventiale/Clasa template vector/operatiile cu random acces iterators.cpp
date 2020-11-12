#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

int main()
{
    int a[]={10,20,30,40};
    vector<int> v(a,a+4);  ///a si a+4 sunt iteratori
    assert(*v.begin()==10&&*--v.end()==40);

    vector<int>::iterator it1(v.begin());
    ///sau vector<int>::iterator it1=v.begin();

    assert(it1[3]==40);
    it1+=3;   ///Pas inainte peste 3 elemente

    assert(*it1==40);
    it1-=2;    ///Pas inapoi peste 2 elemente
    assert(*it1==20);

    ///it2 indica pozitia "past-the-end"
    vector<int>::iterator it2(v.end());
    it2--;
    assert(*it2==40);

    ///Aritmetica iteratorilor este similara cu aritmetica pointerilor
    assert(it2-2==it1&&2+it1==it2&&it1!=it2);

    return 0;
}
