#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

typedef vector<double> VD;

int main()
{
    double d[]={7.8,-7.,54.,1000.};
    VD v1(d,d+4);
    VD v2;

    v2=v1; ///Atribuire
    assert(v1==v2);

    v1[3]=56.;
    assert(v1<v2&&v1!=v2&&v1<=v2);

    v2.pop_back();
    assert(v1>v2&&v1>=v2);

    v1.swap(v2);  ///Interschimba v1 cu v2(functie membra)
    assert(v1<v2&&v1.size()==3&&v2.size()==4);

    swap(v1,v2); ///Interschimba v1 cu v2 (functie globala)
    assert(v1>v2);

    return 0;
}
