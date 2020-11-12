#include <iostream>
#include <set>
using namespace std;

typedef set<int>::iterator IT_S;
typedef multiset<int>::iterator IT_MS;

int main()
{
    set<int> s;
    s.insert(30);  ///Insereaza un element cu valoarea 30
    s.insert(10);  ///Insereaza un element cu valoarea 10
    s.insert(10);  ///Corect, dar operatia esueaza pentru ca
                   ///valoarea 10 exista deja in set
    s.insert(20);
    for(IT_S it=s.begin(); it!=s.end(); ++it)
        cout<<*it<<' ';
    cout<<'\n';

    multiset<int> ms;
    ms.insert(30);  ///Insereaza un element cu valoarea 30
    ms.insert(10);
    ms.insert(10);
    ms.insert(20);
    for(IT_MS i=ms.begin(); i!=ms.end(); ++i)
        cout<<*i<<' ';

    return 0;
}
