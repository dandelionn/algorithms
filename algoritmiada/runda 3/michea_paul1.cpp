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
    end=strlen(n);
    for(i=1;i<=k;i++)
        f>>a[i];
    for(i=1;i<=k;i++)
        f>>b[i];
    for(i=1;i<=k;i++)
        E[i]=a[i];
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
            {E[nr]+=b[j]*(E[y]%9901);
            if(y==2*k)
              y=1;
            else
              y++;}
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
