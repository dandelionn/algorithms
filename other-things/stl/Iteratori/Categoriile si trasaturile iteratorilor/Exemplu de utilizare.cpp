///Exemplu de utilizare a structurii iterator<traits>
#include <iostream>
#include <vector>
#include <iterator>
using namespace std;

template<class Iter>
void Schimba(Iter it1,Iter it2)
{
    typename iterator_traits<Iter>::value_type aux;
    aux=*it1;
    *it1=*it2;
    *it2=aux;
}

template<class Iter>
void Scrie(Iter it1,Iter it2)
{
    for(Iter it=it1; it!=it2; ++it)
        cout<<*it;
    cout<<'\n';
}

int main()
{
    char a[]="ABCDEF";
    vector<char> v(a,a+6);
    Scrie(v.begin(),v.end());
    Schimba(v.begin(),v.begin()+3);
    Scrie(v.begin(),v.end());

    return 0;
}
