#include <iostream>
#include <string.h>
using namespace std;
char a[256],b[256],c;
int k,i;
int main()
{
    cin.get(a,256);cin.get();
    for(i=0;i<strlen(a);i++)
       {
           c=a[i];
           if(a[i]>='a'&&a[i]<='z')
             if(!strchr(b,*(a+i)))
               {
                   b[k]=a[i];
                   cout<<b[k]<<' ';
                   k++;
               }
       }
}
