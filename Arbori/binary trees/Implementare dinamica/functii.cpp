#include <iostream>
#include <fstream>

using namespace std;

ifstream f("arbore.txt");

struct nod{int nr;nod *s,*d;}*r1,*r2;
nod* creare()
{
    int n;nod *r;
    f>>n;
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
//inaltimea arborelui binar
int max(int x,int y)
{
    if(x>y)
       return x;
    else
       return y;
}
int h(nod *r)
{
    if(r==NULL)
       return 0;
    else
       return 1+max(h(r->s),h(r->d));
}
//Numarul de frunze ale arborelui binar
int nr_frunze(nod *r)
{
    if(r==NULL)
       return 0;
    else
       if(r->s==NULL&&r->d==NULL)
          return 1;
       else
          return nr_frunze(r->s)+nr_frunze(r->d);
}
//Copierea unui arbore binar
nod * comb(int n,nod *s,nod* d)
{
    nod *c;
    c=new nod;
    c->nr=n;
    c->s=s;
    c->d=d;
    return c;
}
nod  *copie(nod *c)
{
    if(c==NULL)
       return NULL;
    else
       return comb(c->nr,copie(c->s),copie(c->d));
}
//Compararea a doi arbori binari
int egal(nod * r1,nod* r2)
{
    if(r1==NULL)
       return r2==NULL;
    else
       if(r2==NULL)
          return 0;
       else
          return r1->nr==r2->nr&&egal(r1->s,r2->s)&&egal(r1->d,r2->d);
}
//Afisarea etichetelor de pe un nivel precizat
void nivel(nod *r,int i,int k)
{
    if(r!=NULL)
       {if(i==k)
          cout<<r->nr<<' ';
       else
            {nivel(r->s,i+1,k);
            nivel(r->d,i+1,k);}}
}
//verificarea existentei unui nod cu eticheta precizata
int caut(nod *r,int k)
{
    if(r==NULL)
       return 0;
    else
        if(r->nr==k)
           return 1;
        else
            return caut(r->s,k)||caut(r->d,k);
}
int main()
{
    r1=creare();
    cout<<"Radacina= "<<r1->nr<<'\n';
    cout<<"Inaltimea arborelui este "<<h(r1)-1<<'\n';
    cout<<"Numarul de frunze este "<<nr_frunze(r1)<<'\n';
    r2=copie(r1);
    if(egal(r1,r2))
       cout<<"arborii r1 si r2 sunt egali"<<'\n';
    else
       cout<<"arborii r1 si r2 nu sunt egali"<<'\n';
    int k;
    cout<<"etichetele nodurilor de pe nivelul ";cin>>k;cout<<" sunt: ";nivel(r1,0,k);
    cout<<'\n'<<"nodul cautat este: ";cin>>k;
    if(caut(r1,k))
       cout<<"nodul "<<k<<" exista in arborele r1";
    else
       cout<<"nodul "<<k<<" nu exista in arborele r1";
}
