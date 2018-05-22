#include <iostream>
#include <fstream>

using namespace std;

ifstream f("arbore.txt");
struct nod{int nr;nod *s,*d;}*r;

void creare(nod *&r,int n)
{
    if(r!=NULL)
       if(n<r->nr)
          creare(r->s,n);
       else
          if(n>r->nr)
             creare(r->d,n);
          else
             cout<<"Numarul exista"<<'\n';
    else
        {r=new nod;
        r->nr=n;
        r->s=NULL;
        r->d=NULL;}
}
int main()
{
    int n;
    r=NULL;
    f>>n;
    cout<<"Numar: "<<n<<'\n';
    while(n!=0)
       {creare(r,n);
       cout<<"Numar: ";f>>n;cout<<n<<'\n';}
    f.close();
}
