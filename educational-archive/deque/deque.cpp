#include <fstream>
#include <deque>

using namespace std;

ifstream f("deque.in");
ofstream g("deque.out");
#define pb(x) push_back(x)
#define pf(x) push_front(x)
#define popf() pop_front()
#define popb() pop_back()
#define INF 100000000
int i,el,n,k;
long long int s=0;
deque<int> d,poz;

int main()
{
    d.pb(INF);poz.pb(0);
    f>>n>>k;
    for(i=1;i<=n;i++)
       {f>>el;
       while(!d.empty()&&el<=d.back())
          {d.popb();
          poz.popb();}
       d.pb(el);
       poz.pb(i);
       if(i>=k)
          s+=d.front();
       if(i+1-poz.front()==k)
          {d.popf();
          poz.popf();
          if(d.empty())
             d.pb(INF);}}
    g<<s;
    f.close();g.close();
}
