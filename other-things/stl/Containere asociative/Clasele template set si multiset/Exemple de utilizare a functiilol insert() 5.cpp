#include <iostream>
#include <set>
using namespace std;

int main()
{
    string a[]={"Radu","Ana","Nelu","Ana"};

    multiset<string> ms;
    ms.insert(a,a+4);

    multiset<string>::iterator i;
    for(i=ms.begin();i!=ms.end();++i)
       cout<<*i<<' ';

    cout<<'\n';

    set<string> s;
    s.insert(ms.begin(),ms.end());

    set<string>::iterator it;
    for(it=s.begin();it!=s.end();++it)
       cout<<*it<<' ';

    return 0;
}
