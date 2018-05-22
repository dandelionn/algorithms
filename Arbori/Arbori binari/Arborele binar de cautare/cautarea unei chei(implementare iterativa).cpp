#include <iostream>
#include <fstream>

using namespace std;

ifstream f("arbore.txt");
struct nod{int nr,frecv; nod *s,*d;}*r;

void creare(nod *&r,int n)
{
    if(r!=NULL)
       if(n<r->nr)
          creare(r->s,n);
       else
           if(n>r->nr)
               creare(r->d,n);
           else
               r->frecv++;
    else
       {r=new nod;
       r->nr=n;
       r->frecv=1;
       r->s=NULL;
       r->d=NULL;}
}
nod *cauta(nod *r,int k)
{
    while(r!=NULL && r->nr!=k)
        if(r->nr>k)
           r=r->s;
        else
           r=r->d;
    return r;
}
int main()
{
    int n;
    r=NULL;
    f>>n;
    while(n!=0)
         {
             creare(r,n);
             f>>n;
         }
    int k;
    cout<<"cheia cautata: ";cin>>k;
    if(cauta(r,k)!=NULL)
       cout<<" exista ";
    else
       cout<<" nu exista ";
}
