#include <fstream>
#include <iostream>
using namespace std;

ifstream f("scmax.in");
ofstream g("scmax.out");

int const Nmax=100000;

struct el{int v,int p}v[Nmax];
long int a[Nmax],poz[Nmax],L[Nmax],v[Nmax],n,i,j,nr=1;

void update(int x,int i)
{
    if(x>v[i])
        {swap(x,v[i]);
        if(v[i*2].v==0)
            v[i*2]=x;
        else
           if(v[i*2+1]==0)
              v[i*2+1]=x;
           else
             if(v[i*2]<v[i*2+1])
                update(x,i*2);
             else
                update(x,i*2+1);}
}
int main()
{
    f>>n;
    for(i=1;i<=n;i++)
       f>>a[i];
    f.close();

    update(a[n],1);
    poz[n]=0;
    L[n]=1;

    for(i=n-1;i>=1;i--)
        {
            L[i]=1;poz[i]=i;
            update(a[i],1);
            {L[i]=L[j]+1;
            poz[i]=j;}}
        }

    int maxim=-1,k;
    for(i=1;i<=n;i++)
       if(maxim<L[i])
         {maxim=L[i];
         k=i;}
    g<<L[k]<<'\n';

    for(i=1,j=k;i<=L[k];i++,j=poz[j])
       g<<a[j]<<' ';
    g.close();
}
