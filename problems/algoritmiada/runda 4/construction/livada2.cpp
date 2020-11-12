#include <fstream>
#include <math.h>

using namespace std;

ifstream f("livada.in");
ofstream g("livada.out");

struct pom{int x,y;}a[10001],v[10001];
int i,j,n,a1,o1,ok=0,vizitat[10001],nr=1,indice,indicator;
float r1,r2,panta,ap=100000;

int main()
{
    f>>n;
    for(i=1;i<=n;i++)
        f>>a[i].x;
    for(i=1;i<=n;i++)
        f>>a[i].y;
    for(i=1;i<=n;i++)
        if((sqrt((a[i].x*a[i].x+a[i].y*a[i].y))<ap))
            {
                a1=a[i].x;
                o1=a[i].y;
                ap=sqrt((a[i].x*a[i].x+a[i].y*a[i].y));
            }
    v[1].x=a1;v[1].y=o1;
    for(i=1;i<=n;i++)
        vizitat[i]=0;
    while(ok!=1)
         {indicator=0;
         r1=100000;
         r2=-100000;
         for(i=1;i<=n;i++)
            if(  !vizitat[i] && ( ( a[i].x!=v[nr].x) || (a[i].y!=v[nr].y) ) )
               {if((a[i].y-v[nr].y)==0||(a[i].x-v[nr].x)==0)
                  panta=0;
               else
                  panta=(float)((a[i].x-v[nr].x)/(a[i].y-v[nr].y));

               if(panta<0)
                  panta=panta*(-1);

               if(((indicator==4)||(indicator==0)) && (a[i].x>=v[nr].x && a[i].y<=v[nr].y) )
                   {if(panta>=r2)
                        {indice=i;
                        r2=panta;
                        indicator=4;}}
               else
                   if(((indicator==1)||(indicator==0)) &&(a[i].x>=v[nr].x&&a[i].y>=v[nr].y))
                      {if(panta<=r1)
                       {indice=i;
                        r1=panta;
                        indicator=1;}}
                   else
                       if(((indicator==2)||(indicator==0)) &&(a[i].x<=v[nr].x&&a[i].y>=v[nr].y))
                          {if(panta>=r2)
                              {indice=i;
                              r2=panta;
                              indicator=2;}}
                       else
                            if(((indicator==3)||(indicator==0)) &&(a[i].x<=v[nr].x&&a[i].y<=v[nr].y))
                                 {if(panta<=r1)
                                     {indice=i;
                                     r1=panta;
                                     indicator=3;}}}
         vizitat[indice]=1;
         if(a[indice].x==a1||a[indice].y==o1)
            ok=1;
         else
            v[++nr]=a[indice];}
     for(i=1;i<=n;i++)
         g<<v[i].x<<' '<<v[i].y<<'\n';
     for(i=1;i<=nr;i++)

     f.close();
     g.close();
     return 0;
}
