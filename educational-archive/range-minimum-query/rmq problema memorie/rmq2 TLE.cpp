#include <fstream>
#include <math.h>

using namespace std;

ifstream f("rmq.in");
ofstream g("rmq.out");


int i,j,p,v[100001],n,m,M[10001],el_min,x,y;
int min(int x,int y)
{
    int el_min=100000;
    while(x<=y)
        if(x-1%p==0 && x-1+p<=y)
           {if(M[x/p+1]<el_min)
               el_min=M[x/p+1];
           x+=p;}
        else
           {if(v[x]<el_min)
                el_min=v[x];
           x++;}
     return el_min;
}

int main()
{
   f>>n>>m;
   for(i=1;i<=n;i++)
       f>>v[i];
   p=sqrt(n);
   el_min=100000;
   for(i=1;i<=n;i++)
       {if(v[i]<el_min)
             el_min=v[i];
        if(i%p==0)
           {M[i/p]=el_min;
           el_min=100000;}}
     for(i=1;i<=m;i++)
        {f>>x>>y;
        g<<min(x,y)<<'\n';}

     f.close();g.close();
}
