#include <fstream>
using namespace std;
ifstream f("permutari.in");
ofstream g("permutari.out");
int a[10],ev,as,k,n;
void init()
{
    a[k]=0;
}
int succesor()
{
    if(a[k]<n)
       {a[k]++;
       return 1;}
    else
       return 0;
}
int valid()
{
    for(int i=1;i<k;i++)
       if(a[i]==a[k])
          return 0;
    return 1;
}
int solutie()
{
    return k==n;
}
void tipar()
{
    for(int i=1;i<=n;i++)
        g<<a[i]<<' ';
    g<<'\n';
}
void back()
{
    k=1;
    init();
    while(k>0)
        {
            as=1;ev=0;
            while(as && !ev)
                 {
                     as=succesor();
                     if(as)
                        ev=valid();
                 }
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
    f>>n;
    back();
    f.close();
    g.close();
}
