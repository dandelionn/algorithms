#include <iostream>
using namespace std;
void numar(int x,int &nrp)
{
    int d,nr=0,i=1;
    nrp=0;
    while(i<=x)
       {
           nr=0;
           d=2;
           while(d<=i/2)
               {
                   if(i%d==0)
                     nr++;
                   d++;
               }
           if(nr==0)
             nrp++;
           i++;
       }
}
int main()
{
    int a,b,nrp,c;
    cout<<"a=";cin>>a;
    cout<<"b=";cin>>b;
    if(a<b)
      {
          numar(a,c);
          numar(b,nrp);
          if(nrp>c)
            cout<<"DA";
          else
            cout<<"NU";
      }
    else
      {
          numar(b,c);
          numar(a,nrp);
          if(nrp>c)
            cout<<"DA";
          else
            cout<<"NU";
      }
}
