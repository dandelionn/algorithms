#include <fstream>
#include <vector>
using namespace std;

ifstream f("culori3.in");
ofstream g("culori3.out");

vector<int> v[6];
vector<int>::iterator it;
int Q[10001],n,i,x,k,nr;


int main()
{
    f>>n;
    v[1].push_back(2);
    v[2].push_back(1);
    v[2].push_back(3);
    v[3].push_back(2);
    v[3].push_back(4);
    v[4].push_back(3);
    v[4].push_back(5);
    v[5].push_back(4);
    for(i=1;i<=5;i++)
        Q[i]=i;
    k=5;nr=0;x=1;
    while(x<n)
        {x++;
        i=nr+1;
        nr=k;
        while(i<=nr)
             {
             for(it=v[Q[i]].begin();it!=v[Q[i]].end();++it)
                Q[++k]=*it;
            i++;}
        }
    g<<k-nr;
    f.close();g.close();
}
