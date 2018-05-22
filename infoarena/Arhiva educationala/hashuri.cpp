#include <fstream>
#include <vector>

using namespace std;

ifstream f("hashuri.in");
ofstream g("hashuri.out");

#define pb(x)  push_back(x)
#define mod 666013

vector<long int>::iterator it;
vector<long int> a[mod];

int n,i,tip,ok;
long int x;

int main()
{
    f>>n;
    for(i=1;i<=n;i++)
        {f>>tip>>x;
        if(tip==1)
          {if(a[x%mod].empty())
             a[x%mod].pb(x);
          else
             {ok=0;
             for(it=a[x%mod].begin();it!=a[x%mod].end();++it)
                 if(*it==x)
                    ok=1;
             if(!ok)
                a[x%mod].pb(x);}}
        else
           if(tip==2)
              {for(it=a[x%mod].begin();it!=a[x%mod].end();++it)
                 if(*it==x)
                    *it=-10000;}
           else
               {ok=0;
               for(it=a[x%mod].begin();it!=a[x%mod].end();++it)
                 if(*it==x)
                    ok=1;
               if(ok)
                  g<<1<<'\n';
               else
                  g<<0<<'\n';}}

     f.close();g.close();
}
