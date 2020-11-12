#include <fstream>
using namespace std;
ifstream f("matd3.in");
ofstream g("matd3.out");
int a[5],n,m,y,k,as,ev,v[100][100],nr=0;
void init()
{
    a[k]=0;
}
int succesor()
{
    if(a[k]<y)
       {a[k]++;
       return 1;}
    else
       return 0;
}
int valid()
{
    int i;
    if(k>2)
       {if(k==4)
          {if(a[1]>n||a[3]>n||a[2]>m||a[4]>m)
              return 0;
          if(a[1]==a[3]&&a[2]==a[4])
              return 0;}
       for(i=3;i<=k;i++)
           if(a[i-2]>a[i])
              return 0;}
    return 1;
}
int solutie()
{
    return k==4;
}
void tipar()
{
    int i,j,s=0;
    for(i=a[1];i<=a[3];i++)
       for(j=a[2];j<=a[4];j++)
            s+=v[i][j];
    if(s%3==0)
       nr++;
}
void back()
{
    k=1;
    init();
    while(k>0)
       {
           as=1;ev=0;
           while(as && !ev)
                {as=succesor();
                if(as)
                   ev=valid();}
           if(as)
              if(solutie())
                 tipar();
              else
                 {k++;
                 init();}
           else
              k--;
       }
}
int main()
{
    int i,j;
    f>>n;
    f>>m;
    for(i=1;i<=n;i++)
       for(j=1;j<=m;j++)
           {f>>v[i][j];
           if(v[i][j]%3==0)
              nr++;}
    if(m>n)
       y=m;
    else
       y=n;
    back();
    g<<nr;
    f.close();
    g.close();
}
