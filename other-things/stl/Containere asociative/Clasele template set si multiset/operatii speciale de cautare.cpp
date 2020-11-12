#include <iostream>
#include <set>
using namespace std;

int main()
{
    multiset<char> ms;
    multiset<char>::iterator it;
    ms.insert('a');
    ms.insert('b');
    ms.insert('b');
    ms.insert('f');

    cout<<ms.count('a')<<' '<<ms.count('b')<<'\n';
    cout<<*ms.find('f')<<'\n';
    cout
    <<"*lower_bound('b'):"<<*ms.lower_bound('b')<<'\n'
    <<"*upper_bound('b'):"<<*ms.upper_bound('b')<<'\n'
    <<"*equal_range('b'):";
    for(it=ms.equal_range('b').first;  ;++it)
    {
        cout<<*it<<' ';
        if(it==ms.equal_range('b').second)  break;
    }
    return 0;
}
