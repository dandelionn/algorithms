#include <fstream>
#include <string.h>
#include <stdlib.h>
using namespace std;

ifstream f("opmult.in");
ofstream g("opmult.out");

bool matrix[801][256],valid[801],ord[801];
char ordine[801],ch[2001];
int y,n,i,nr=0;

int check(char h)
{
    int x;
    if(h=='('||h==')')
       x=1;
    else
       x=0;
    return x;
}
void extrage(char a[],int n)
{
    int i,x1,x2,o,j,vs,vd;
    char c[10];
    for(i=0;i<=n;i++)
        if( a[i]=='u' || a[i]=='n' || a[i]=='-' )
           {ordine[++nr]=a[i];
           ord[nr]=1;}
        else
            if( a[i]== '(' || a[i]=='[' )
                 {x1=check(a[i]);

                 i++;
                 o=0;
                 while(a[i]!=',')
                      {c[o]=a[i];
                      o++;
                      i++;}
                 c[o]='\0';
                 vs=atoi(c);

                 i++;
                 o=0;
                 while( a[i]!=')' && a[i]!=']' )
                      {c[o]=a[i];
                      o++;
                      i++;}
                 c[o]='\0';
                 vd=atoi(c);

                 x2=check(a[i]);
                 vs+=x1;
                 vd-=x2;
                 for(j=vs;j<=vd;j++)
                     matrix[nr+1][j]=1;
                 valid[nr+1]=1;}
    ordine[nr+1]='\0';
}
void intersectie(int nr)
{
    int i,j,o,f1,f2,k;
    for(k=1;k<=nr-1;k++)
       if( ord[k] && ordine[k]=='n' )
           {i=k;
           j=k+1;
           ord[k]=0;
           while(!valid[i] && i>=1)
                 i--;
           if(i>=1) f1=1; else f1=0;

           while( !valid[j] && j<=nr)
                j++;
           if(j<=nr) f2=1; else f2=0;

           if(f1==0)
              {i=j+1;
              while(!valid[i] && i<=nr)
                 i++;}
           else
              if(f2==0)
                 {j=i-1;
                 while( !valid[j] && j>=1)
                     j--;}
           if(i>j)
              {o=i;
              i=j;
              j=o;}
           for(o=1;o<=256;o++)
               if(matrix[i][o]!=matrix[j][o])
                  matrix[i][o]=0;
           valid[j]=0;
       }
}

void reudif(int nr)
{
    int i,j,o,f1,f2,k;
    for(k=1;k<=nr-1;k++)
       if( ord[k] && ( ordine[k]=='u' || ordine[k]=='-' ))
           {i=k;
           j=k+1;
           ord[k]=0;
           while(!valid[i] && i>=1)
                 i--;
           if(i>=1) f1=1; else f1=0;

           while( !valid[j] && j<=nr)
                j++;
           if(j<=nr) f2=1; else f2=0;

           if(f1==0)
              {i=j+1;
              while(!valid[i] && i<=nr)
                 i++;}
           else
              if(f2==0)
                 {j=i-1;
                 while( !valid[j] && j>=1)
                     j--;}
           if(i>j)
              {o=i;
              i=j;
              j=o;}
           if(ordine[k]=='u')
                {for(o=1;o<=256;o++)
                    if( matrix[j][o]==1 && matrix[i][o]==0 )
                        matrix[i][o]=1;}
           else
                for(o=1;o<=256;o++)
                    if( matrix[i][o] && matrix[j][o] )
                        matrix[i][o]=0;
           valid[j]=0;}
}
void init(int n)
{
    int i,j;
    for(i=1;i<=n;i++)
       for(j=1;j<=255;j++)
           matrix[i][j]=0;
}
int cauta(int y,int nr)
{
    int i;
    for(i=1;i<=nr;i++)
        if( matrix[i][y] && valid[i] )
            return 1;
    return 0;
}
int main()
{
    int str;
    ordine[0]='0';
    f>>n;
    for(i=1;i<=n;i++)
       {

           nr=0;
           f>>y>>ch;
           str=strlen(ch);
           init((str/5)*2+str%5);
           extrage(ch,str);
           intersectie(nr+1);
           reudif(nr+1);

           if( cauta(y,nr+1) )
              g<<"DA"<<'\n';
           else
              g<<"NU"<<'\n';
       }
    f.close();
    g.close();
    return 0;
}
