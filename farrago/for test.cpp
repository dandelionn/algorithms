#include <iostream>
#include <string.h>
using namespace std;
char a[201],*p,b[]="AaEeIiOoUu",*q;
int nr;
int main()
{
    cin.get(a,201);cin.get();
    q=a;
    p=strchr(q,' ');
    p=a;
    if(strchr(b,*q)&&strchr(b,*(p+strlen(a)-1)))
       {
           p+=strlen(a);
           for(;q<p;q++)
              cout<<*q;
           nr++;
       }
    if(!nr)
      cout<<"NU EXISTA";
}
