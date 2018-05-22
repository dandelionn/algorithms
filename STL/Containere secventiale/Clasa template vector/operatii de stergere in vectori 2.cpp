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
    VI v;
    v.reserve(8);

    for(int i=1;i<=8;i++)
        v.push_back(i);
    afiseaza(v);

    IT it1(v.begin()+4);
    cout<<*it1<<'\n';

    ///Sterge intervalul [v.begin(),it1)
    IT it=v.erase(v.begin(),it1);
    cout<<*it<<'\n';

    ///it1 s-a invalidat. Indica in cel mai bun
    ///caz, un alt element din secventa
    cout<<*it1<<'\n';    ///Comportament nedefinit

    afiseaza(v);
    return 0;
}
