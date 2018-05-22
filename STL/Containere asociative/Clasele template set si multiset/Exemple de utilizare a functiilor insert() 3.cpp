#include <iostream>
#include <set>
using namespace std;

int main()
{
    multiset<int> ms;
    multiset<int>::iterator it;

    it=ms.insert(2);
    cout<<*it<<' ';

    it=ms.insert(1);
    cout<<*it<<' ';

    it=ms.insert(2);
    cout<<*it<<'\n';

    for(it=ms.begin();it!=ms.end();++it)
       cout<<*it<<' ';

    return 0;
}
