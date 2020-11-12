#include <iostream>
#include <deque>
using namespace std;

int main()
{
    deque<char> dq;   ///Creeaza o coada vida
    dq.assign(4,'R');

    dq.push_front('S');  ///Adauga la inceput un element
    dq.push_back('D');   ///Adauga la sfarsit un element

    cout<<dq.front()<<' '<<dq.back()<<'\n';

    dq.pop_front();    ///Sterge primul element
    dq.pop_back();     ///Sterge ultimul element

    for(int i=0;i<dq.size();++i)
        cout<<dq[i]<<' ';
    cout<<'\n';

    dq.resize(6,'Y');

    for(int i=0;i<dq.size();++i)
        cout<<dq[i]<<' ';
    cout<<'\n';

    dq.resize(2,'T');

    for(int i=dq.size()-1; i>=0; --i)
        cout<<dq[i]<<' ';
    return 0;
}
