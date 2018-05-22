#include <iostream>
#include <fstream>
using namespace std;
ifstream f("date.txt");
int n,sol[20],dopt=0,i,j,viz[20]={0},solopt[20],a[20][20]={0};
void comis(int k,int o,int l)
{
    int y;
    viz[o]=1;
    sol[k]=o;
    if(k<n+1)
       {
           for(y=1;y<=n;y++)
              if((a[o][y]!=0&&viz[y]==0&&l+a[o][y]<dopt)||(k==n&&y==1&&l+a[o][y]<dopt))
                 comis(k+1,y,l+a[o][y]);
       }
    else
       if(sol[k]==1)
           {dopt=l;
           for(y=1;y<=n+1;y++)
              {
                  solopt[y]=sol[y];
                  viz[y]=0;
              }}
}
int main()
{
    f>>n;
    for(i=1;i<=n-1;i++)
        for(j=i+1;j<=n;j++)
            {f>>a[i][j];
            a[j][i]=a[i][j];
            dopt+=a[i][j];}
    comis(1,1,0);
    cout<<"lungimea minima= "<<dopt<<'\n';
    for(i=1;i<=n+1;i++)
       cout<<solopt[i]<<' ';
}
