#include <fstream>
#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;

ifstream f("livada.in");
ofstream g("livada.out");

struct pom{int x,y;}a[10001],v[10001];
int i,j,n,a1,o1,ok=0,vizitat[10001],nr=1,indice,cadran=0;
float r1,r2,panta,ap=100000.0,aria=0.0,det;

int main()
{
    f>>n;
    for(i=1;i<=n;i++)
        f>>a[i].x;
    for(i=1;i<=n;i++)
        f>>a[i].y;
    for(i=1;i<=n;i++)
        cout<<a[i].x<<' '<<a[i].y<<'\n';
    cout<<'\n';
    for(i=1;i<=n;i++)
        if((sqrt((a[i].x*a[i].x+a[i].y*a[i].y))<ap))
            {
                a1=a[i].x;
                o1=a[i].y;
                ap=sqrt((a[i].x*a[i].x+a[i].y*a[i].y));
            }
    v[1].x=a1;v[1].y=o1;
    cout<<v[1].x<<' '<<v[1].y<<"\n\n";
    for(i=1;i<=n;i++)
        vizitat[i]=0;
    while(ok!=1&&cadran<=4)
         {indice=0;
         r1=100000;
         r2=-100000;
         cout<<'\n';
         if(cadran==1)
               {cout<<"cadran 1 :   "<<'\n';
               for(i=1;i<=n;i++)
                        if(  !vizitat[i] && (a[i].x!=v[nr].x||a[i].y!=v[nr].y)&&(a[i].x>=v[nr].x && a[i].y<=v[nr].y))
                            {if((a[i].x-v[nr].x)==0)
                                panta=100000.0;
                            else
                                if((a[i].y-v[nr].y)==0)
                                    panta=0;
                                 else
                                    panta=((float)(a[i].y-v[nr].y))/(float)((a[i].x-v[nr].x));
                            cout<<"panta "<<panta<<' ';
                            if(panta<0)
                                panta=panta*(-1);
                            cout<<"abspanta "<<panta<<' '<<" coordonate "<<a[i].x<<' '<<a[i].y<<'\n';
                            if(panta>=r2)
                                {indice=i;
                                r2=panta;
                                cout<<"valid_abspanta "<<panta<<' '<<" coordonate "<<a[i].x<<' '<<a[i].y<<'\n';}
                            }}
          if(cadran==2)
               {cout<<"cadran 2 :   "<<'\n';
               for(i=1;i<=n;i++)
                        if(  !vizitat[i]  && (a[i].x!=v[nr].x||a[i].y!=v[nr].y)&&(a[i].x>=v[nr].x&&a[i].y>=v[nr].y))
                            {if((a[i].x-v[nr].x)==0)
                                panta=100000.0;
                            else
                                if((a[i].y-v[nr].y)==0)
                                    panta=0;
                            else
                                panta=((float)(a[i].y-v[nr].y))/(float)((a[i].x-v[nr].x));
                            cout<<"panta "<<panta<<' ';
                            if(panta<0)
                                panta=panta*(-1);
                            cout<<"abspanta "<<panta<<' '<<" coordonate "<<a[i].x<<' '<<a[i].y<<'\n';
                            if(panta<=r1)
                                {indice=i;
                                r1=panta;
                                cout<<"valid_abspanta "<<panta<<' '<<" coordonate "<<a[i].x<<' '<<a[i].y<<'\n';}
                            }}
          if(cadran==3)
               {cout<<"cadran 3 :   "<<'\n';
               for(i=1;i<=n;i++)
                        if(  !vizitat[i] && (a[i].x!=v[nr].x||a[i].y!=v[nr].y) && (a[i].x<=v[nr].x&&a[i].y>=v[nr].y))
                            {if((a[i].x-v[nr].x)==0)
                                panta=100000.0;
                            else
                                if((a[i].y-v[nr].y)==0)
                                    panta=0;
                            else
                                panta=((float)(a[i].y-v[nr].y))/(float)((a[i].x-v[nr].x));
                            cout<<"panta "<<panta<<' ';
                            if(panta<0)
                                panta=panta*(-1);
                            cout<<"abspanta "<<panta<<' '<<" coordonate "<<a[i].x<<' '<<a[i].y<<'\n';
                            if(panta>=r2)
                                {indice=i;
                                r2=panta;
                                cout<<"valid_abspanta "<<panta<<' '<<" coordonate "<<a[i].x<<' '<<a[i].y<<'\n';}
                            }}
         if(cadran==4)
               {cout<<"cadran 4 :   "<<'\n';
               for(i=1;i<=n;i++)
                        if(  !vizitat[i] && (a[i].x!=v[nr].x||a[i].y!=v[nr].y) && a[i].x<=v[nr].x&&a[i].y<=v[nr].y)
                            {if((a[i].x-v[nr].x)==0)
                                panta=100000.0;
                            else
                                if((a[i].y-v[nr].y)==0)
                                    panta=0;
                            else
                                panta=((float)(a[i].y-v[nr].y))/(float)((a[i].x-v[nr].x));
                            cout<<"panta "<<panta<<' ';
                            if(panta<0)
                                panta=panta*(-1);
                            cout<<"abspanta "<<panta<<' '<<" coordonate "<<a[i].x<<' '<<a[i].y<<'\n';
                            if(panta<=r1)
                                {indice=i;
                                r1=panta;
                                cout<<"valid_abspanta "<<panta<<' '<<" coordonate "<<a[i].x<<' '<<a[i].y<<'\n';}
                            }}
         if(indice!=0)
            {g<<indice<<'\n';
            vizitat[indice]=1;
            cout<<a[indice].x<<' '<<a[indice].y<<' '<<'\n';
            if(a[indice].x==a1&&a[indice].y==o1)
               {ok=1;
               cout<<"ok==1";}
            else
               v[++nr]=a[indice];}
         else
            cadran++;}
     for(i=1;i<=nr;i++)
         g<<v[i].x<<' '<<v[i].y<<'\n';
     for(i=3;i<=nr;i++)
         {det=v[1].x*v[i-1].y+v[1].y*v[i].x+v[i-1].x*v[i].y-v[i].x*v[i-1].y-v[1].x*v[i].y-v[1].y*v[i-1].x;
         if(det<0)
            det=det*(-1);
         aria+=det/2.0;}
     g<<setiosflags(ios::fixed)<<setprecision(2)<<aria<<'\n';
     f.close();
     g.close();
     return 0;
}
