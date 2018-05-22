#include <iostream>
using namespace std;
void divizor(int a,int &d)
{
    int ok=0;
    d=a/2+1;
    while(d>=2&&ok==0)
         {
             d--;
             if(a%d==0)
               ok++;
         }
}
int main()
{
    int x,d;
    cout<<"x=";cin>>x;
    divizor(x,d);
    if(d==1)
      cout<<"DA";
    else
      cout<<"NU";
}
