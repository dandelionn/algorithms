#include <iostream>
using namespace std;

int n,m,k,ev,as,a[100];
int parant()
{
    int i=1,nr=0;
    if(a[i]!=1||k%2==1)
      return 0;
    nr=0;
    i=1;
    while(i<=k)
        {

            if(a[i]==1)
              nr++;
            if(a[i]==2)
              {nr--;
              if(nr<0)
                return 0;}
            i++;
        }
    if(nr==0)
      return 1;
    else
      return 0;
}
int surjectiva()
{
    int i,j,x;
    for(j=1;j<=n;j++)
       {
           for(i=1,x=0;i<=m && !x;i++)
                if(a[i]==j)
                   x=1;
           if(!x)
              return 0;
       }
    return 1;
}
void init()
{
    a[k]=0;
}
int succesor()
{
    if(a[k]<n)
      {
          a[k]=a[k]+1;
          return 1;
      }
    else
      return 0;
}
int valid()
{
    if(k==m)
      if(!surjectiva())
         return 0;
    return 1;
}
int solutie()
{
    return k==m;
}
void tipar()
{
    int i;
    if(parant())
      {for(i=1;i<=k;i++)
          cout<<a[i]<<' ';
      cout<<'\n';}
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
               tipar();
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
    cout<<"elemente multimea A= ";cin>>m;
    cout<<"elemente multimea B= ";cin>>n;
    bt();
}
