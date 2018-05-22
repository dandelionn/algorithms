#include <iostream>

using namespace std;

template<typename T> class Coada{
    int ultim,prim;
    T c[100];
    public:Coada():prim(0),ultim(0){}
       void adauga(T val)
       {ultim++;
       c[ultim]=val;}
       const char* elimina(){return c[++prim];}
       void afiseaza() const
       {
           cout<<c[ultim]<<' ';
       }
};

int main()
{
    Coada<const char*> a1;
    a1.adauga("text");
    a1.afiseaza();
    a1.adauga("carte");
    a1.afiseaza();
    cout<<'\n'<<a1.elimina()<<'\n';
    cout<<a1.elimina();
}
