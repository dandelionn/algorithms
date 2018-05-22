#include <iostream>
#include <vector>
using namespace std;

vector<int> v(5);   ///v[0], v[1], v[2], v[3], v[4]

vector<double> X; ///creaza un vector vid(are 0 elemente)

vector<char> v1(100);   ///Vector cu 100 de caractere
vector<char*> v2(10);   ///Vector de 10 pointeri la char
vector<float> v3(30);   ///vector cu 30 de elemente de tip float

struct A {};
vector<A> v4(50);    ///vector de 50 obiecte de tip A

int main()
{
    int n,t;
    vector<float> d1;    ///Secventa vida
    vector<char*> d2(7);    ///Secventa cu 7 elemente
    vector<int> d3(7, 4);    ///7 elemente de valoare 4

    ///MyAloc este alocator propriu
    //vector<int> d1=MyAloc;          ///Eroare
    //vector<int> d2=vector(MyAloc);   ///OK
    //vector<int> d3(MyAloc)           ///OK

    //vector<double> d4(7, 4, a1); ///7 elemente de valoare 4,alocate cu alocatorul a1
    //a1 este un alocator propriu

    vector<int>::iterator it1(d3.begin());
    vector<int>::iterator it2=(d3.end());
    vector<int>::iterator it;

    ///Copiaza elementele din intervalul [it1,it2).
    ///Elementele se aloca cu alocatorul a1


    //vector<int> d5(it1, it2, a1);
    ///Creeaza un vector cu valori din intervalul [it1, it2)
    vector<int> d6(it1, it2);

    for(it=d6.begin();it!=d6.end();++it)
        cout<<*it<<' ';
}
