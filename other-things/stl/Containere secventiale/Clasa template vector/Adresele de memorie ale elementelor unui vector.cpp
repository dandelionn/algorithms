#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

typedef vector<int> VI;

int main()
{
    int a[]={10,20,30,40,50};
    VI v(a,a+5);
    VI v1(&v[0],&v[0]+5);  ///Copiaza in v1 toate
                           ///cele 5 elemente ale lui v
    assert(v1==v);

    for(int i=0;i<=5;i++)
        assert(&v[i]==&v[0]+i);

    return 0;
}
