#include <iostream>
using namespace std;
int i=1,a[20],n;
void afisare()
{int j=1;
    while(j<=i)
       {cout<<a[j];
       j++;}
    cout<<'\n';
}
int main()
{
    cout<<"n=";cin>>n;
    while(i>0)
         {
             a[i]++;
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
}
