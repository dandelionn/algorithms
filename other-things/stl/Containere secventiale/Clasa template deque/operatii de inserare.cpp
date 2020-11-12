#include <deque>
#include <iostream>
using namespace std;

int main()
{
    deque<char> Q;
    char a[]="EST";

    cout<<*Q.insert(Q.end(),'A')<<'\n';
    Q.insert(Q.begin(),3,'E');
    Q.insert(Q.begin()+1,a,a+3);

    for(int i=0;i<Q.size(); ++i)
        cout<<Q[i]<<' ';
    return 0;
}
