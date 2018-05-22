#include <iostream>
#include <set>
using namespace std;

int main()
{
    string a[]={"Radu","Nelu","Ana"};
    set<string> s(a,a+3);
    set<string>::iterator it;

    it=s.insert(s.begin(),"Adi");
    cout<<*it;

    it=s.insert(s.begin(),"Ana");    ///Inserarea esueaza
    cout<<*it;

    for(it=s.begin(); it!=s.end();++it)
       cout<<*it<<' ';

    multiset<string> ms(s.begin(),s.end());
    multiset<string>::iterator i;

    i=ms.insert(ms.begin(),"Adi");
    cout<<*i;

    i=ms.insert(ms.begin(),"Ana");
    cout<<*i;

    for(i=ms.begin(); i!=ms.end(); ++i)
       cout<<*i<<' ';

    return 0;
}
