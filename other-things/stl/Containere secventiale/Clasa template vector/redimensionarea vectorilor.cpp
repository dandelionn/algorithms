#include <vector>
#include <iostream>
using namespace std;

class A{
};

int main()
{
    vector<A> v;    ///Creeaza un vector vid(cu 0 elemente)
    cout<<v.size()<<'\n';  ///Afiseaza 0
    if(v.empty())
       cout<<"Vid"<<'\n';
    else
       cout<<"Nevid"<<'\n';

    int n;
    cin>>n;
    v.resize(n);   ///Redimensioneaza la n elemente
    if(v.empty())
       cout<<"Vid"<<'\n';
    else
       cout<<"Nevid"<<'\n';
       cout<<v.size(); ///Afiseaza n
       cout<<v.max_size();  ///Afiseaza dimensiunea
                          ///maxima posibila a unui vector
   return 0;
}
