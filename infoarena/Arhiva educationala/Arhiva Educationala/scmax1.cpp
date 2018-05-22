#include <fstream>
#include <vector>

using namespace std;

ifstream f("scmax.in");
ofstream g("scmax.out");

int const Nmax=100001;
long int  L,n,i,j,found,bestL;
struct elem{long int val,adr;}a[Nmax];
vector<vector<int> > v(100001);
vector<int>::iterator it;

int main()
{
    f>>n;
    for(i=1;i<=n;i++)
       f>>a[i].val;
    a[n].adr=0;
    L=1;bestL=1;
    v[L].push_back(n);
    for(i=n-1;i>=1;i--)
           {
               if(L<bestL)
                   L=bestL;
               found=0;
               while(L>0&&!found)
                      {for(it=v[L].begin();it!=v[L].end()&&!found;++it)
                              if(a[*it].val>a[i].val)
                                 {
                                     a[i].adr=*it;
                                     if(L==bestL)
                                           bestL++;
                                     found=1;
                                     v[L+1].push_back(i);
                                 }
                       L--;}
               L++;
               if(L==1&&!found)
                   {
                          a[i].adr=0;
                          v[L].push_back(i);
                    }
           }
    for(i=v[bestL].front();a[i].adr!=0;i=a[i].adr)
             g<<a[i].val<<' ';
    g<<a[i].val;

    f.close();g.close();
}
