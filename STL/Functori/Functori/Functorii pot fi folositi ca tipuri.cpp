#include <iostream>
#include <set>
#include <string>
using namespace std;

struct Elev{
    string nume;
    int varsta;
};

///Clasa de funtori-stabileste criteriul de ordonare
struct Compar{
    bool operator() (Elev x,Elev y) const
    {return x.nume<y.nume;   } ///Ordonare dupa nume
};

int main()
{
    Elev e[]={{"Dana",18},{"Nelu",17},{"Adi",16}};
    set<Elev,Compar> s(e,e+3);

    set<Elev,Compar>::iterator it;
    for(it=s.begin();it!=s.end();++it)
        cout<<(*it).nume<<' '<<(*it).varsta<<'\n';

    return 0;
}
