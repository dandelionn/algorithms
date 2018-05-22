#include <fstream>

using namespace std;
ifstream f("disjoint.in");
ofstream g("disjoint.out");

int i,n,m,x,y,c,s[100001],rang[100001];

int root(int i)
{
    if(i!=s[i])
        return s[i]=root(s[i]);
    else
         return i;
}

void unite(int x, int y)
{
    x=root(x); y=root(y);
    if(rang[x]<rang[y])
        s[x]=y;
    else
        if(rang[x]>rang[y])
             s[y]=x;
        else
            {
                s[y]=x;
                rang[x]++;
            }
}

int main()
{
    f>>n>>m;
    for(i=1;i<=n;i++)
        {
            s[i]=i;
            rang[i]=0;
        }
    for(i=1;i<=m;i++)
         {
             f>>c>>x>>y;
             if(c==1)
                 unite(x,y);
             else
                 if(root(x)==root(y))
                     g<<"DA\n";
                 else
                     g<<"NU\n";
         }
}
