#include <fstream>
#include <math.h>
#include <iomanip>

using namespace std;

ifstream f("livada.in");
ofstream g("livada.out");

struct pom{int x,y;}a[10001],v[10001];
int i,j,n,a1,o1,ok=0,vizitat[10001],nr=1,indice,cadran=0;
double r1,r2,panta,ap=100000.0,aria=0.00,det=0.00;

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
    while(ok!=1&&cadran<=4)
         {indice=0;
         r1=100000;
         r2=-100000;
         if(cadran==1)
               for(i=1;i<=n;i++)
                        if(  !vizitat[i] && (a[i].x!=v[nr].x||a[i].y!=v[nr].y)&&(a[i].x>=v[nr].x && a[i].y<=v[nr].y))
                            {if((a[i].x-v[nr].x)==0)
                                panta=100000.0;
                            else
                                if((a[i].y-v[nr].y)==0)
                                    panta=0;
                                 else
                                    panta=((float)(a[i].y-v[nr].y))/(float)((a[i].x-v[nr].x));
                            if(panta<0)
                                panta=panta*(-1);
                            if(panta>=r2)
                                {indice=i;
                                r2=panta;}}
          if(cadran==2)
               for(i=1;i<=n;i++)
                        if(  !vizitat[i]  && (a[i].x!=v[nr].x||a[i].y!=v[nr].y)&&(a[i].x>=v[nr].x&&a[i].y>=v[nr].y))
                            {if((a[i].x-v[nr].x)==0)
                                panta=100000.0;
                            else
                                if((a[i].y-v[nr].y)==0)
                                    panta=0;
                            else
                                panta=((float)(a[i].y-v[nr].y))/(float)((a[i].x-v[nr].x));
                            if(panta<0)
                                panta=panta*(-1);
                            if(panta<=r1)
                                {indice=i;
                                r1=panta;}}
          if(cadran==3)
               for(i=1;i<=n;i++)
                        if(  !vizitat[i] && (a[i].x!=v[nr].x||a[i].y!=v[nr].y) && (a[i].x<=v[nr].x&&a[i].y>=v[nr].y))
                            {if((a[i].x-v[nr].x)==0)
                                panta=100000.0;
                            else
                                if((a[i].y-v[nr].y)==0)
                                    panta=0;
                            else
                                panta=((float)(a[i].y-v[nr].y))/(float)((a[i].x-v[nr].x));
                            if(panta<0)
                                panta=panta*(-1);
                            if(panta>=r2)
                                {indice=i;
                                r2=panta;}}
         if(cadran==4)
               for(i=1;i<=n;i++)
                        if(  !vizitat[i] && (a[i].x!=v[nr].x||a[i].y!=v[nr].y) && a[i].x<=v[nr].x&&a[i].y<=v[nr].y)
                            {if((a[i].x-v[nr].x)==0)
                                panta=100000.0;
                            else
                                if((a[i].y-v[nr].y)==0)
                                    panta=0;
                            else
                                panta=((float)(a[i].y-v[nr].y))/(float)((a[i].x-v[nr].x));
                            if(panta<0)
                                panta=panta*(-1);
                            if(panta<=r1)
                                {indice=i;
                                r1=panta;}}
         if(indice!=0)
            {vizitat[indice]=1;
            if(a[indice].x==a1&&a[indice].y==o1)
               ok=1;
            else
               v[++nr]=a[indice];}
         else
            cadran++;}
     for(i=3;i<=nr;i++)
         {det=v[1].x*v[i-1].y+v[1].y*v[i].x+v[i-1].x*v[i].y-v[i].x*v[i-1].y-v[1].x*v[i].y-v[1].y*v[i-1].x;
         if(det<0)
            det=det*(-1);
         aria+=det/2.0;}
     g<<setiosflags(ios::fixed)<<setprecision(2)<<aria;
     f.close();
     g.close();
     return 0;
}
