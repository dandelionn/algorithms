#include <iostream>

using namespace std;
struct nod{int nr;nod *s,*d;}*r;
nod* creare()
{
    int n;nod *r;
    cout<<"Eticheta nod: ";cin>>n;
    if(n==0)
       return NULL;
    else
       {
           r=new nod;
           r->nr=n;
           r->s=creare();
           r->d=creare();
           return r;
       }
}
int main()
{
    r=creare();
    cout<<"Radacina= "<<r->nr;
}
