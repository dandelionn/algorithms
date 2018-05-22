#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

int main()
{
    vector<double> v1(6,3.4);   ///6 elemente cu valoarea 3.4
    assert(v1.size()==6&&v1.back()==3.4);

    vector<double> v2(v1);  ///Construieste v2 din v1 prin copiere
    assert(v2==v1);  ///Testeaza egalitatea a doua containere

    char a[]="Salut";

    ///Preia intervalul [a[0],a[5])  din a[]
    vector<char> v3(a,a+5);
    assert(v3[0]==a[0]&&v3[5]==a[5]);

    int b[]={2,-3,4,-5,6};
    vector<int> v4(b+1,b+3); ///Preia un interval din b[]
    assert(v4.front()==b[1]&&v4.back()==b[2]);

    return 0;
}
