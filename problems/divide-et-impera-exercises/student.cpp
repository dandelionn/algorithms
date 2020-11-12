#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;
ifstream f("student.in");
ofstream g("student.out");
struct elev{char nume[20],prenume[20];float medie1,medie2,ma;}a[100];
int n;
char z='Y',o[20],e[20];
void schimba(int &a,int &b)
{
    int aux=a;
    a=b;
    b=aux;
}
void schimb(elev &a,elev &b)
{
    elev aux=a;
    a=b;
    b=aux;
}
void divizeaza(int s,int d,int &m)
{
    int i=s,j=d,pi=0,pj=1;
    while(i<j)
       {
           if(strcmp(a[i].nume,a[j].nume)>0)
               {
                   schimb(a[i],a[j]);
                   schimba(pi,pj);
               }
           else
              if(strcmp(a[i].nume,a[j].nume)==0&&strcmp(a[i].prenume,a[j].prenume)>0)
                    {
                        schimb(a[i],a[j]);
                        schimba(pi,pj);
                    }
           i=i+pi;
           j=j-pj;
       }
    m=i;
}
void QuickSort(int s,int d)
{
    int m;
    if(s<d)
       {
           divizeaza(s,d,m);
           QuickSort(s,m-1);
           QuickSort(m+1,d);
       }
}
void divi(int s,int d,int &m)
{
    m=(s+d)/2;
}
void cauta(int s,int d)
{
    int m;
    if(d==s)
       {if((strcmp(a[s].nume,o)==0)&&(strcmp(a[s].prenume,e)==0))
          cout<<a[s].nume<<' '<<a[s].prenume<<' '<<a[s].medie1<<' '<<a[s].medie2<<' '<<a[s].ma<<'\n';}
    else
       {
           divi(s,d,m);
           cauta(s,m);
           cauta(m+1,d);
       }
}
int main()
{
    int i;
    f>>n;
    for(i=1;i<=n;i++)
       {
           f>>a[i].nume;
           f>>a[i].prenume;
           f>>a[i].medie1>>a[i].medie2;
           a[i].ma=(a[i].medie1+a[i].medie2)/2;
       }
    QuickSort(1,n);
    for(i=1;i<=n;i++)
        g<<a[i].nume<<' '<<a[i].prenume<<' '<<a[i].medie1<<' '<<a[i].medie2<<' '<<a[i].ma<<'\n';
    while(z=='Y')
        {cout<<"Doriti informatii despre un elev ?(Y/N)";
        cin>>z;
        if(z=='Y')
            {cout<<"Nume: ";cin>>o;
            cout<<"prenume: ";cin>>e;
          cauta(1,n);}}
}
