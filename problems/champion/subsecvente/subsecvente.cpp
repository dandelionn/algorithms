#include <fstream>
#include <string.h>

using namespace std;
ifstream f("subsecvente.in");
ofstream g("subsecvente.out");

#define NMAX 50001
int n;

int sirmax(char a[],char b[],char c[],char d[],int min)
{
    char s[NMAX];
    int l=0,max=0,j;
    for(j=0;j<min;j++)
        {s[l]=a[j];
        s[l+1]='\0';
        if(strstr(b,s)&&strstr(c,s)&&strstr(d,s))
           l++;
        else
           {if(l>max)
              max=l;
            strcpy(s,s+1);
            if(strchr(b,s[l-1])&&strchr(c,s[l-1])&&strchr(d,s[l-1]))
               while(!(strstr(b,s)&&strstr(c,s)&&strstr(d,s)))
                   {strcpy(s,s+1);
                   l--;}
            else
                {l=0;
                s[l]='\0';}
            }}
    return max;
}
int main()
{
    f>>n;
    int D[6],i=0;
    char a[NMAX],b[NMAX],c[NMAX],d[NMAX],de[NMAX];
    f>>a;
    D[++i]=strlen(a);
    f>>b;
    D[++i]=strlen(b);
    if(n>2)
       {f>>c;
       D[++i]=strlen(c);}
    if(n>3)
       {f>>d;
       D[++i]=strlen(d);}
    if(c[0]=='\0')
        {strcpy(c,a);D[++i]==D[1];
        strcpy(d,a);D[++i]==D[1];}
    else
        if(d[0]=='\0')
            {strcpy(d,a);D[++i]=D[1];}
     int min=D[1],indicator=1;
     for(i=2;i<=n;i++)
         if(D[i]<min)
            {min=D[i];
            indicator=i;}
     if(indicator==1)
        g<<sirmax(a,b,c,d,min);
     else
         if(indicator==2)
            g<<sirmax(b,a,c,d,min);
         else
            if(indicator==3)
               g<<sirmax(c,a,b,d,min);
            else
               g<<sirmax(d,a,b,c,min);
    f.close();
    g.close();
    return 0;
}
