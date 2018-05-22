#include <fstream>
#include <vector>
#include <iostream>
using namespace std;

ifstream f("graf.in");
ofstream g("graf.out");

vector<int> v[7501];
vector<int>::iterator it;
int n,m,x,y,i,a,b,viz[7501]={0},Q[7501],k;


int main()
{
    f>>n>>m>>x>>y;
    for(i=1;i<=m;i++)
        {f>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);}

    Q[1]=x;i=0;viz[x]=1;k=1;
    while(i<=n)
    {
            i++;
            for(it=v[Q[i]].begin(); it!=v[Q[i]].end(); ++it)
                if(!viz[*it])
                    {Q[++k]=*it;
                    viz[*it]=viz[Q[i]]+1;}
    }
    for(i=1;i<=n;i++)
        cout<<Q[i]<<' ';
    cout<<'\n';
    for(i=1;i<=n;i++)
        cout<<viz[i]-1<<' ';
    f.close();g.close();
}
