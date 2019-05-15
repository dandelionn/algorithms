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
void inserare(nod *&r,int k)
{
    if(r==NULL)
       {
           r=new nod;
           r->nr=k;
           r->frecv=1;
           r->s=NULL;
           r->d=NULL;
       }
    else
        if(r->nr==k)
           r->frecv++;
        else
           if(k<r->nr)
             inserare(r->s,k);
           else
             inserare(r->d,k);
}
int main()
{
    int n;
    f>>n;
    r=NULL;
    while(n!=0)
        {
            creare(r,n);
            f>>n;
        }
    int k;
    cout<<"cheia adaugata: ";cin>>k;
    inserare(r,k);
    f.close();
}
