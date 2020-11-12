#include <iostream>
#include <vector>
using  namespace std;

typedef vector<int> VI;
typedef VI::iterator IT;

void afiseaza(VI v)
{
    for(IT it=v.begin(); it!=v.end(); ++it)
       cout<<*it<<' ';
    cout<<'\n';
}
int main()
{
    VI v;
    v.reserve(8);   ///Capacitate 8(evita realocarea)

    for(int i=1;i<=8;i++)
       v.push_back(i);
    afiseaza(v);

    IT it1(v.begin()+2);
    cout<<*it1<<'\n';

    IT it=v.erase(v.begin()+1);
    cout<<*it<<'\n';

    ///it1-invalidat. Indica in cel mai bun
    ///caz,pozitia urmatorului element dupa cel sters;
    cout<<*it1<<'\n';   ///Comportament nedefinit

    afiseaza(v);

    IT it2(v.begin()+1);
    IT it3(v.begin()+3);
    IT it4=v.erase(it2,it3);

    afiseaza(v);

    return 0;
}
