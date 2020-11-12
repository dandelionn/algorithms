#include <iostream>
#include <deque>
using namespace std;

int main()
{
    char a[]="ABCDEF";
    deque<char> Q(a,a+6);

    typedef deque<char>::iterator IT;

    IT it=Q.erase(Q.begin()+1);
    cout<<*it<<'\n';

    it=Q.erase(Q.begin()+1,Q.begin()+3);
    cout<<*it<<'\n';

    for(int i=0;i<Q.size();++i)
        cout<<Q[i]<<' ';
    return 0;
}
