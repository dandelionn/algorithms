#include <iostream>
#include <string.h>
using namespace std;
char c1,c2,text[250],textfinal[250],*p;
int main()
{
    cin.get(text,250);
    cin.get();
    cin>>c1>>c2;
    cout<<text<<'\n';
    strcpy(textfinal,text);
    p=strchr(textfinal,c1);
    while(p)
         {
             textfinal[p-textfinal]=c2;
             p=strchr(++p,c1);
         }
    p=strchr(textfinal,c2);
    cout<<textfinal<<'\n';
    while(p)
         {
             textfinal[p-textfinal]=c1;
             p=strchr(++p,c2);
         }
    cout<<textfinal;
}
