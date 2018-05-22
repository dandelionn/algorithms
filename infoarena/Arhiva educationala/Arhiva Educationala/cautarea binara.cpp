#include <iostream>
using namespace std;
int v[100],n,x;
int divide(int p,int u)
{
    if(p<=u)
       {int m=(p+u)/2;
        if(v[m]==x)
           return m;
        else
           {if(x<v[m])
               return divide(p,m);
           else
              return divide(m+1,u);}}
    else
       return 0;
}
int main()
{
    cin>>n;
    cout<<"x=";cin>>x;
    for(int i=1;i<=n;i++)
        cin>>v[i];
    cout<<divide(1,n);
}
