#include <iostream>
#include <string.h>
using namespace std;
char a[201],*p,b[]="AaEeIiOoUu",*q;
int nr=0;
int main()
{
    cin.get(a,201);cin.get();
    q=a;
    p=strchr(q,' ');
    while(p)
       {
           if(strchr(b,*q)&&strchr(b,*(p-1)))
              nr++;
           p=strchr(q+1,' ');
       }
    p=a;
    if(strchr(b,*q)&&strchr(b,*(p+strlen(a)-1)))
           nr++;
    if(!nr)
      cout<<"NU EXISTA";
}
