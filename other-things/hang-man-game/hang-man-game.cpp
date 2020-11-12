#include <iostream>
#include <string.h>
#include <cstdlib>
using namespace std;
char b[21],a[21],c,*p;
int i,vieti=4,ok;
int main()
{
    cin.get(a,20);cin.get();
    system("CLS");
    b[0]=a[0];
    for(i=1;i<strlen(a);i++)
       b[i]='_';
    b[strlen(a)]='\0';
    cout<<"ai 4 vieti"<<'\n';
    for(i=0;i<strlen(b);i++)
        cout<<b[i]<<' ';
    cout<<'\n';
    while(ok!=1&&vieti!=0)
       {
       cout<<"litera=";
       cin>>c;
       system("CLS");
       p=strchr(a,c);
       if(p==NULL)
          {vieti--;
          cout<<"ai "<<vieti<<" vieti"<<'\n';
          for(i=0;i<strlen(b);i++)
              cout<<b[i]<<' ';
          cout<<'\n';}
       while(p)
          {b[p-a]=*p;
          p=strchr(p+1,c);
          if(!p)
             {cout<<"ai "<<vieti<<" vieti"<<'\n';
             for(i=0;i<strlen(b);i++)
                 cout<<b[i]<<' ';
             cout<<'\n';}}
       if(!strchr(b,'_'))
          {ok=1;
          cout<<"ai castigat!"<<'\n'<<'\n'<<'\n';;}}
    if(vieti==0)
       cout<<"ai pierdut!!!"<<' '<<"deoarece nu stii sa joci :))"<<'\n';
}
