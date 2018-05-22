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
       while(r->s!=NULL)
           r=r->s;
    return r->nr;
}
int max(nod *r)
{
    if(r->d!=NULL)
       while(r->d!=NULL)
           r=r->d;
    return r->nr;
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
    cout<<"valoare minima= "<<min(r)<<'\n';
    cout<<"valoare maxima= "<<max(r)<<'\n';
    f.close();
}
