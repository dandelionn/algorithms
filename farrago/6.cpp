#include <iostream>
#include <string.h>
using namespace std;
char a[151],*p,b[]="0123456789",c;
int nr,m,nr2;
int main()
{
    cin.get(a,151);cin.get();
    for(int i=0;i<10;i++)
       {nr=0;c=b[i];
       p=strchr(a,c);
       while(p)
          {
              nr++;
              p=strchr(++p,c);
          }
       if(nr>nr2)
         {m=i;nr2=nr;}}
if(m)
  cout<<m;
else
  cout<<"NU";
}
