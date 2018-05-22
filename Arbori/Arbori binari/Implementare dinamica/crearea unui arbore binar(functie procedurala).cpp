#include <iostream>

using namespace std;
struct nod{int nr;nod *s,*d;}*r;
void creare(nod *&r)
{
    int n;
    cout<<"Eticheta nod: ";cin>>n;
    if(n==0)
       r=NULL;
    else
       {r=new nod;
       r->nr=n;
       creare(r->s);
       creare(r->d);
       }
}
int main()
{
    creare(r);
    cout<<"radacina "<<r->nr;
}
