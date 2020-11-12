#include <fstream>
#include <math.h>

using namespace std;

ifstream f("aib.in");
ofstream g("aib.out");

int n,m,ct,b;
long int a,c[100001];

int nrzt(int x)           //nr zerouri teminale
{
    if(x%2==0)
       return 1+nrzt(x/2);
    return 0;
}

void build()
{
    int i,j,nr;
    for(i=1;i<=n;i++)
        {
            f>>c[i];
            nr=nrzt(i);
            j=i-1;
            while(nr!=0)
               {
                   c[i]+=c[j];
                   j-=pow(2,nrzt(j));
                   nr--;
               }
        }
}
void modify()
{
    f>>a>>b;
    c[a]+=b;
    while(a<=n)
        {
            a+=pow(2,nrzt(a));
            c[a]+=b;
        }
}
int sumaux(long int x)
{
    long int s=0;
    while(x!=0)
        {s+=c[x];
        x-=pow(2,nrzt(x));}
    return s;
}
void sum()
{
    f>>a>>b;
    long int s1,s2;
    s1=sumaux(a-1);s2=sumaux(b);
    g<<s2-s1<<'\n';
}
void frfirst(int p,int u,long int a)
{
      if(p<=u)
         {int m=(p+u)/2;
         long int y;
         y=sumaux(m);
         if(a==y)
             g<<m<<'\n';
         else
             if(a>y)
                frfirst(m+1,u,a);
             else
                frfirst(p,m-1,a);}
      else
           g<<-1<<'\n';
}

int main()
{
    f>>n>>m;
    c[0]=0;
    build();
    for(int i=1;i<=m;i++)
       {
           f>>ct;
           if(ct==0)
              modify();
           else
              if(ct==1)
                 sum();
              else
                 if(ct==2)
                    {f>>a;
                    frfirst(1,n,a);}
       }
    f.close();
    g.close();
    return 0;
}
