#include <iostream>
using namespace std;
void cut(int a[],int s,int &d,int n)
{
    if(s<d)
        {
        if(n%2==0)
            {
                a[s]=a[n/2+s];
                a[n/2+s]=0;
            }
        else
            {
                a[s]=a[n/2+s+1];
                a[n/2+s+1]=0;
            }
            d--;
            s++;
            cut(a,s,d,n);
        }
    else
       if(d==s)
          {
              a[s]=0;
              d--;
          }
}
void pliere(int a[],int &n)
{
    if(n>1)
    {
        cut(a,1,n,n);
        pliere(a,n);
    }
}
int main()
{
    int i,n,a[100];
    cout<<"n= ";
    cin>>n;
    for(i=1; i<=n; i++)
    {
        cout<<"a["<<i<<"]= ";
        cin>>a[i];
    }
    pliere(a,n);
    cout<<a[1];
}
