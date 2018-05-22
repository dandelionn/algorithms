#include <fstream>
#include <algorithm>

using namespace std;

ifstream f("cautbin.in");
ofstream g("cautbin.out");

int main()
{
    int z[100001],i,j,val,n,m,ind;
    f>>n;
    for(i=1;i<=n;i++)
        f>>z[i];
    f>>m;
    for(i=1;i<=m;i++)
        {
            f>>j>>val;
            if(j==0)
               {ind=upper_bound(z+1,z+n+1,val)-z-1;
               if(ind>0&&z[ind]==val)
                  g<<ind<<'\n';
               else
                  g<<-1<<'\n';}
            else
               if(j==1)
                  {ind=upper_bound(z+1,z+n+1,val)-z-1;
                  g<<ind<<'\n';}
               else
                    {ind=lower_bound(z+1,z+n+1,val)-z;
                    g<<ind<<'\n';}
        }
    f.close();
    g.close();
    return 0;
}
