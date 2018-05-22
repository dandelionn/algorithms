#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

ifstream f("extensionacci.in");
ofstream g("extensionacci.out");

char n[108],nc[108];
int a[101],b[101],E[108],k,cl,y,h,end,nr,i,j;

int main()
{
    f>>k>>n;
    cout<<k<<' '<<n;
    cout<<'\n';
    end=strlen(n);
    cout<<"end="<<end<<'\n';
    cout<<"n[0]="<<n[0]<<'\n'<<"sirul a  ";
    for(i=1;i<=k;i++)
        {f>>a[i];
        cout<<a[i]<<' ';}
    cout<<"\n\n"<<"sirul b  ";
    for(i=1;i<=k;i++)
        {f>>b[i];
        cout<<b[i]<<' ';}
    cout<<"\n\n"<<"sirul E  ";
    for(i=1;i<=k;i++)
        {E[i]=a[i];
        cout<<a[i]<<' ';}
    cout<<"\n\n";
    cl=k;
    for(i=0;i<end;i++)
        nc[i]='0';
    nc[end]='\0';
    end--;
    h=end;
    while(cl!=0)
        {nc[h]=cl%10+'0';
        cl/=10;
        h--;}
    cout<<"sirul nc  "<<nc<<"\n\n";
    h=end;
    y=1;
    nr=k+1;
    while(strcmp(nc,n)<0)
       {if(nc[end]-'0'<9)
          nc[end]=nc[end]+1;
       else
          {
          while(nc[h]-'0'==9)
                {nc[h]='0';
                h--;}
          nc[h]=nc[h]+1;
          h=end-1;
          nc[end]='0';}
       if(nr<=k)
          y=k+nr;
       else
          y=nr-k;
       E[nr]=0;
       for(j=1;j<=k;j++)
            {E[nr]+=(b[j]*(E[y]%9901))%9901;
            if(y==2*k)
              y=1;
            else
              y++;}
       g<<"E["<<nr<<"]= "<<E[nr]%9901<<' '<<" sirul nc  "<<nc<<"\n\n";
       if(nr==2*k)
           nr=1;
       else
           nr++;
       }
   if(nr==1)
     g<<E[2*k]%9901;
   else
     g<<E[nr-1]%9901;
   f.close();
   g.close();
   return 0;
}
