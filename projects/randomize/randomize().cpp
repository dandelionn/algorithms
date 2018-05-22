#include <iostream>
#include <stdlib.h>

using namespace std;

int main()
{
    int m,i,z,max,poz;
    cout<<"m= ";cin>>m;
    max=rand()%122;poz=1;
    for(i=2;i<=m;i++)
       {
           z=rand()%122;
           if(z>max)
             {
                 max=z;poz=i;
             }
       }
    cout<<"maxim="<<max<<'\n';
    cout<<"pe pozitia="<<poz;
}
