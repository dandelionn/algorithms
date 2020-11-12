#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> VI;
typedef VI::iterator IT;

void afiseaza(VI v)
{
    for(IT it=v.begin();it!=v.end();++it)
         cout<<*it<<' ';
    cout<<'\n';
}

int main()
{
    VI v1,v2;
    ///Se rezerva memorie pentru evitarea realocarii
    v1.reserve(11); ///capacitate 11
    v2.reserve(5);  ///capacitate 5

    for(int i=1;i<=5;i++)
    {
        v1.push_back(i);
        v2.push_back(10*i);
    }
    afiseaza(v1);
    afiseaza(v2);

    ///Insereaza inainte de "past-the-end",deci la sfarsitul
    ///containerului, 3 elemente de valoare 50
    v1.insert(v1.end(),3,50);

    afiseaza(v1);

    ///Insereaza inainte de al treilea element,
    ///intervalul [v2.begin()+2,v2.end())
    v1.insert(v1.begin()+2,v2.begin()+2,v2.end());

    afiseaza(v1);

    return 0;
}
