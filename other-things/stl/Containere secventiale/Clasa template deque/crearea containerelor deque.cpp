#include <iostream>
#include <cassert>
#include <vector>
#include <deque>
using namespace std;

typedef deque<int> QI;
typedef vector<int> VI;

int main()
{
    QI q1;
    assert(q1.size()==0&&q1.empty());

    QI q2(10);  ///Coada cu 10 elemente de valoare 0 fiecare
    assert(q2.size()==10&&q2.front()==0);

    QI q3(5,78);  ///Coada cu 5 elemente de valoare 78 fiecare
    assert(q3.size()==5&&q3.front()==78&&q3.back()==78);

    int a[]={100,200,300,400};
    VI v(a,a+4);

    QI q4(&v[0],&v[0]+4);
    assert(q4.front()==100&&q4.back()==400);

    ///Constructorul de copiere
    ///Construieste q5 si q6 din q4,respectiv q5
    QI q5(q4),q6=q5;
    assert(q4==q5&&q5==q6);

    q1=q6;    ///Atribuire
    q1.swap(q3);
    q6.clear();  ///Sterge toate elementele

    return 0;
}
