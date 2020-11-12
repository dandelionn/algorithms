#include <iostream>
#include <map>
using namespace std;

int main()
{
    multimap<int, char> m;
    multimap<int, char>::iterator it;

    m.insert(make_pair(3,'a'));
    m.insert(make_pair(3,'x'));
    m.insert(make_pair(2,'c'));
    m.insert(make_pair(1,'b'));

    ///Returneaza numarul de perechi cu cheile 2 si 3
    cout<<m.count(2)<<' '<<m.count(3)<<'\n';

    ///Returneaza pozitia primului element cu cheia 3
    it=m.find(3);
    cout<<it->first<<' '<<it->second<<'\n';

    cout<<"lower_bound(1)->second: "
        <<m.lower_bound(1)->second<<'\n'
         <<"upper_bound(2)->second: "
        <<m.upper_bound(2)->second<<'\n'
          <<"equal_range(3): ";

    it=m.equal_range(3).first;
    do
    {
        cout<<it->first<<' '<<it->second<<' ';
        it++;
    }
    while(it!=m.equal_range(3).second);

    return 0;
}
