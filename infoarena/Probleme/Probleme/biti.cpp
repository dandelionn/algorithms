#include <iostream>
using namespace std;
int n,c[10]={0},sol[10];
void back(int k)
{
    int i;
    if(k<=n)
      for(i=0;i<=1;i++)
             {
                 sol[k]=i;
                 c[i]=1;
                 back(k+1);
                 c[i]=0;
             }
    else
       {for(i=1;i<=n;i++)
           cout<<sol[i]<<' ';
       cout<<'\n';}
}
int main()
{
    cin>>n;
    back(1);
}