#include <iostream>
#include <string>
#include <map>
using namespace std;

template <class Container>
void Scrie(Container c)
{
    typename Container::iterator it;
    for(it=c.begin();it!=c.end();++it)
        cout<<it->first<<' '<<it->second<<'\n';
    ///sau cout<<(*it).first<<' '<<(*it).second<<'\n';
    cout<<'\n';
}

int main()
{
    typedef int varsta;
    typedef string nume;

    map<nume, varsta> m;

    cout<<"Inserari in map:\n";

    ///Insereaza o pereche folosind constructorul clasei pair.
    m.insert(pair<nume, varsta>("Nelu",17));

    ///Insereaza o pereche folosind functia make_pair()
    m.insert(make_pair("Adi",18));
    m.insert(make_pair("Adi",19));  ///Inserarea esueaza
                                    ///(cheie identica)
    m.insert(make_pair("Ioana",19));
    Scrie(m);

    cout<<"Inserari in multimap:\n";
    multimap<nume, varsta> mm;
    mm.insert(m.begin(),m.end());
    Scrie(mm);

    ///Insereaza un element la o pozitie specificata
    mm.insert(mm.end(),make_pair("Ioana",20));
    Scrie(mm);

    return 0;
}
