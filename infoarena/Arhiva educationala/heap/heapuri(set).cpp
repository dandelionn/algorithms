#include <fstream>
#include <set>
using namespace std;
ifstream f("heapuri.in");
ofstream g("heapuri.out");

set<int> H;
int ord[200001],ct,i,n,k=0,x;


int main()
{
    f>>n;
    for(i=1;i<=n;i++)
        {f>>ct;
        if(ct==1)
           {f>>x;
           H.insert(x);
           ord[++k]=x;}
        else
            if(ct==2)
              {f>>x;
               H.erase(ord[x]);}
            else
                g<<*H.begin()<<'\n';}
    f.close();
    g.close();
}
