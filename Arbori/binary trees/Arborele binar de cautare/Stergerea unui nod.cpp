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
void sterge_nod(nod *&r,nod *&c)
{
    nod *p;
    if(r->d!=NULL)
       sterge_nod(r->d,c);
    else
       {
           c->nr=r->nr;
           p=r->s;
           delete r;
           r=p;
       }
}
void stergere(nod *&r,int k)
{
    nod *c;
    if(r->nr==k)
           if(r->s==NULL&&r->d==NULL)
               {delete r;
               r=NULL;}
           else
               if(r->s==NULL)
                   {c=r->d;
                   delete r;
                   r=c;}
               else
                   if(r->d==NULL)
                      {c=r->s;
                      delete r;
                      r=c;}
                   else
                       sterge_nod(r->s,r);
    else
       if(k<r->nr)
          stergere(r->s,k);
       else
           if(k>r->nr)
              stergere(r->d,k);
           else
              cout<<"cheia nu a fost gasita :|";
}
void SRD(nod *r)
{
    if(r!=NULL)
       {SRD(r->s);
       cout<<r->nr<<' ';
       SRD(r->d);}
}
int main()
{
    int n;
    r=NULL;
    f>>n;
    cout<<"Numar: "<<n<<'\n';
    while(n!=0)
         {
             creare(r,n);
             f>>n;
             cout<<"Numar: "<<n<<'\n';
         }
    int k;
    cout<<"Nodul care trebuie sters: ";cin>>k;
    stergere(r,k);
    SRD(r);
    f.close();
}
