#include <deque>
#include <iostream>
using namespace std;

int main()
{
    deque<char> Q1(2,'I');
    deque<char> Q2;   ///Coada vida

    Q2=Q1;   ///Atribuire

    if(Q1==Q2)
       cout<<"Q1==Q2\n";
    Q2.push_back('Y');
    if(Q1==Q2)  cout<<"Q1==q2\n";
    if(Q1<Q2)  cout<<"Q1<Q2\n";
    if(Q1<=Q2) cout<<"Q1<=Q2\n";
    if(Q1!=Q2) cout<<"Q1!=Q2\n";

    if(Q2>Q1)  cout<<"Q2>Q1\n";
    if(Q2>=Q1) cout<<"Q2>=Q1\n";

    return 0;
}
