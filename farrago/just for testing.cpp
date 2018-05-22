#include <fstream>
using namespace std;
ifstream f("tacs.in");
ofstream g("tacs.out");
int i=1,a[20],b[100][100],n,m,pozi,pozj;
void afisare()
{
    int x=0,y=0,ok=0,j; x=pozi;y=pozj;
    for(j=1;j<=i;j++)
        if(a[j]==1)
           {x+=1;
           if(b[x][y]!=0)
              ok++;}
        else
           {y+=1;
           if(b[x][y]!=0)
              ok++;}
    if(!ok)
        {for(j=1;j<=i;j++)
           {
               if(a[j]==1)
                  g<<"jos ";
               else
                  g<<"dreapta ";
           }
         g<<'\n';}
}
int main()
{
    f>>pozi;
    f>>pozj;
    f>>n;
    f>>m;
    for(int x=1;x<=n;x++)
       for(int j=1;j<=m;j++)
          f>>b[x][j];
    n=n*m-1;
    while(i>0)
         {
             a[i]++;
             afisare();
             i++;
             if(i==n)
                   while(a[i]!=2)
                        {
                            a[i]++;
                            afisare();
                        }
             while(a[i]==2)
                  {
                      a[i]=0;
                      i--;
                  }
         }
    f.close();
    g.close();
}
