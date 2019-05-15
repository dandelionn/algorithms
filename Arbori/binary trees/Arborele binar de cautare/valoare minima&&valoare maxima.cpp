#include <iostream>
#include <fstream>

using namespace std;

ifstream f("arbore.txt");
struct nod{int nr,frecv;nod *s,*d;}*r;

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
int min(nod *r)
{
    if(r->s!=NULL)
       return min(r->s);
    else
       return r->nr;
}
int max(nod *r)
{
    if(r->d!=NULL)
       return max(r->d);
    else
       return r->nr;
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
    cout<<"valoare minima= "<<min(r)<<'\n';
    cout<<"valoare maxima= "<<max(r);
}
