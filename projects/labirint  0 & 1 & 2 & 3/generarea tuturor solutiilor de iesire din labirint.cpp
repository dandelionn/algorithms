#include <fstream>
using namespace std;
ifstream f("tacs.in");
ofstream g("tacs.out");
struct traseu{int i,j;}c[20];
int as,a[100],ev,k,b[100][100],n,m,pozi,pozj,q=1,ok;
void init()
{
    a[k]=-1;
}
int margine()
{

    return ((c[q].i==n||c[q].i==0||c[q].j==m||c[q].j==0)&&(c[q].i<=n&&c[q].j<=m)&&!ok);
}
void contraseu()
{
    ok=0;
    for(int i=1;i<=q;i++)
       {if(a[i]==0)
         {c[i].i=c[i-1].i+1;
         c[i].j=c[i-1].j;}
       else
          if(a[i]==1)
             {c[i].j=c[i-1].j+1;
             c[i].i=c[i-1].i;}
          else
             if(a[i]==2)
               {c[i].j=c[i-1].j-1;
               c[i].i=c[i-1].i;}
             else
                if(a[i]==3)
                   {c[i].i=c[i-1].i-1;
                   c[i].j=c[i-1].j;}
       if(c[i].i<1||c[i].j<1||c[i].i>n||c[i].j>m)
          ok=1;}
}
int tetraseu()
{
    for(int i=1;i<=k;i++)
       {if(i>=2)
           if((a[i-1]==3&&a[i]==0)||(a[i-1]==0&&a[i]==3)||(a[i-1]==1&&a[i]==2)||(a[i-1]==2&&a[i]==1))
              return 0;
       if(b[c[i].i][c[i].j]!=0)
          return 0;}
    return 1;
}
void dua()
{
    int ok=1;
    for(int i=1;i<=q;i++)
       if(a[i]==0)
         ok=0;
    if(ok&&q<=m+n-1)
       {k=1;
       init();
       q++;}
}
int succesor()
{
    if(a[k]<3)
      {a[k]+=1;
      return 1;}
    else
      return 0;
}
int valid()
{
      return 1;
}
int solutie()
{
    return k==q;
}
void tipar()
{
    contraseu();
    if(margine())
       if(tetraseu())
         {for(int i=1;i<=q;i++)
             {if(a[i]==0)
                g<<"jos"<<' ';
             else
                if(a[i]==1)
                   g<<"dr"<<' ';
                else
                   if(a[i]==2)
                      g<<"st"<<' ';
                   else
                      if(a[i]==3)
                         g<<"sus"<<' ';}
         g<<'\n';}
    dua();
}
void bt()
{
    k=1;
    init();
    while(k>0)
        {
            as=1;ev=0;
            while(as &&!ev )
                 {as=succesor();
                 if(as)
                   ev=valid();}
            if(as)
              {
                  if(solutie())
                    tipar();
                  else
                    {k++;
                    init();}
              }
            else
               k--;
        }
}
int main()
{
    f>>pozi;
    f>>pozj;
    c[0].i=pozi;
    c[0].j=pozj;
    f>>n;
    f>>m;
    int j,i;
    for(i=1;i<=n;i++)
       for(j=1;j<=m;j++)
          f>>b[i][j];
    bt();
    f.close();
    g.close();
}
