#include <iostream>
#include <map>
using namespace std;

int main()
{
    ///Criteriul de ordonare:descrescator dupa cheia de tip char
    typedef multimap<char,int,greater<char> > MMAP;
    MMAP m;
    cout<<m.count('A')<<'\n';

    m.insert(make_pair('A',40));
    m.insert(make_pair('A',10));
    m.insert(make_pair('A',20));
    cout<<m.count('A')<<'\n';
    m.insert(make_pair('B',30));
    m.insert(make_pair('C',20));

    ///Parcurge toate elementele multimap-ului
    for(MMAP::iterator it=m.begin();it!=m.end();++it)
       cout<<(*it).first<<"->"<<(*it).second<<'\n';

    int nr=m.erase('A');  ///Sterge toate elementele cu cheia 'A'

    cout<<"S-au sters "<<nr<<" elemente ";

    return 0;
}
