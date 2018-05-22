#include <iostream>
using namespace std;
int a[100],s=0,n,as,ev,k,L,b[100],sum=0;
int surjectiva()
{
    int i,j,x;
    for(i=1;i<=n;i++)
       {
           for(j=1,x=0;j<=k && !x;j++)
                if(b[i]==b[a[j]])
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
      {a[k]++;
      return 1;}
    else
      {s-=b[a[k-1]];
      return 0;}
}
int valid()
{
      if(s+b[a[k]]<=L)
        {s+=b[a[k]];
        return 1;}
      else
        return 0;
}
int solutie()
{
    return L==s;
}
void tipar()
{
    int i;
    if(surjectiva())
        {for(i=1;i<=k;i++)
            cout<<b[a[i]]<<' ';
        cout<<'\n';}
    s-=b[a[k]];
}
void bt()
{
    k=1;
    init();
    while(k>0)
         {
             as=1;ev=0;
             while(as&&!ev)
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
    cout<<"n=";cin>>n;
    cout<<"L=";cin>>L;
    for(int i=1;i<=n;i++)
        cin>>b[i];
    bt();
}
