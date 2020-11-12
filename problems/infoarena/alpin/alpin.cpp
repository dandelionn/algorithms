#include <fstream>
#include <algorithm>
using namespace std;

ifstream f("alpin.in");
ofstream g("alpin.out");

struct tablou{int x,y;}el[1025],aux,drum[1025][1025];
int a[1025][1025],val[1025][1025],i,j,n,k;

bool cmp(tablou c , tablou b)
{
    return a[b.x][b.y]>a[c.x][c.y];
}

int main()
{
    f>>n;
    for(i=1,k=0;i<=n;i++)
        for(j=1;j<=n;j++)
            {f>>a[i][j];
            el[++k].x=i;
            el[k].y=j;}

   sort(el+1,el+k+1,cmp);

   for(i=1;i<=n*n;i++)
          {
          if(a[el[i].x][el[i].y] < a[el[i].x-1][el[i].y] && val[el[i].x-1][el[i].y]<val[el[i].x][el[i].y]+1)
             {val[el[i].x-1][el[i].y] = val[el[i].x][el[i].y]+1;
             drum[el[i].x-1][el[i].y].x =el[i].x;
             drum[el[i].x-1][el[i].y].y =el[i].y;}

          if(a[el[i].x][el[i].y]  < a[el[i].x][el[i].y+1] && val[el[i].x][el[i].y+1]<val[el[i].x][el[i].y]+1)
             {val[el[i].x][el[i].y+1] = val[el[i].x][el[i].y]+1;
             drum[el[i].x][el[i].y+1].x =el[i].x;
             drum[el[i].x][el[i].y+1].y =el[i].y;}

          if(a[el[i].x][el[i].y]  < a[el[i].x+1][el[i].y] && val[el[i].x+1][el[i].y]<val[el[i].x][el[i].y]+1)
             {val[el[i].x+1][el[i].y] = val[el[i].x][el[i].y]+1;
             drum[el[i].x+1][el[i].y].x =el[i].x;
             drum[el[i].x+1][el[i].y].y =el[i].y;}

          if(a[el[i].x][el[i].y]  < a[el[i].x][el[i].y-1] && val[el[i].x][el[i].y-1]<val[el[i].x][el[i].y]+1)
             {val[el[i].x][el[i].y-1] = val[el[i].x][el[i].y]+1;
             drum[el[i].x][el[i].y-1].x =el[i].x;
             drum[el[i].x][el[i].y-1].y =el[i].y;}
          }

   aux.x=1;aux.y=1;
   for(i=1;i<=n;i++)
      for(j=1;j<=n;j++)
         if(val[i][j]>val[aux.x][aux.y])
            {aux.x=i;aux.y=j;}
   g<<val[aux.x][aux.y]+1<<'\n';
   i=aux.x;j=aux.y;
   while(val[i][j]!=0)
        {i=drum[i][j].x;
        j=drum[i][j].y;
        g<<i<<' '<<j;}

   for(i=1;i<=n;i++)
      {for(j=1;j<=n;j++)
          g<<val[i][j]<<' ';
      g<<'\n';}


    f.close();
    g.close();
}
