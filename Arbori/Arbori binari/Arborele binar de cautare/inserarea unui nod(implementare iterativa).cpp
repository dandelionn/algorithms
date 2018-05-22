#include <iostream>
#include <fstream>

using namespace std;
struct nod{int nr,frecv;nod *s,*d;}*r;
ifstream f("arbore.txt");

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
       {
           r=new nod;
           r->nr=n;
           r->frecv=1;
           r->s=NULL;
           r->d=NULL;
       }
}
void inserare(nod *r,int k)
{
    int x=1;
    nod *c;
    while(r!=NULL&&x==1)
       if(r->nr==k)
           {r->frecv++;x=0;}
       else
           if(k<r->nr)
             {c=r; r=r->s;}
           else
             {c=r; r=r->d;}
    if(x)
       {
           r=new nod;
           r->nr=k;
           r->frecv=1;
           r->s=NULL;
           r->d=NULL;
           if(c->nr>k)
              c->s=r;
           else
              c->d=r;
       }
}
void DRS(nod *r)
{
    if(r!=NULL)
        {DRS(r->d);
        cout<<r->nr<<' ';
        DRS(r->s);}
}
int main()
{
    int n;
    f>>n;
    r=NULL;
    while(n!=0)
        {
            creare(r,n);
            f>>n;cout<<n;
        }
    int k;
    cout<<"cheia adaugata: ";cin>>k;
    inserare(r,k);
    DRS(r);
    f.close();
}
