#include <iostream>
#include <string.h>
using namespace std;
char s[20],b[]="aeiou",*p;
int main()
{
    cin>>s;
    for(p=s;*p!='\0';p++)
       if(!strchr(b,*p))
         {strcpy(p,p+1);
         p--;}
    cout<<s;
}
