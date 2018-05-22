#include <fstream>
using namespace std;
ifstream f("genab.in");
ofstream g("genab.out");
int a[21],k,as,ev,n;
char c[2];
void init()
{
    a[k]=0;
}
int succesor()
{
    if(a[k]<2)
       {a[k]++;
       return 1;}
    else
       return 0;
}
int valid()
{
    int i;
    for(i=1;i<k;i++)
        if(a[i]==a[i+1]&&a[i]==2)
            return 0;
    return 1;
}
int solutie()
{
    return k==n;
}
void afisare()
{
    int i;
    for(i=1;i<=n;i++)
        g<<c[a[i]];
    g<<'\n';
}
void bt()
{
    k=1;
    init();
    while(k>0)
         {
             as=1;ev=0;
             while( as && !ev )
                  {
                      as=succesor();
                      if(as)
                         ev=valid();
                  }
             if(as)
                if(solutie())
                   afisare();
                else
                   {
                       k++;
                       init();
                   }
             else
                 k--;
         }
}
int main()
{
    c[1]='a';
    c[2]='b';
    f>>n;
    bt();
    f.close();
    g.close();
}
