#include <fstream>

using namespace std;

ifstream f("aib.in");
ofstream g("aib.out");

int n,m,ct,a,b,sum,i,v[100001];

int binsum1(int st,int dr)
{
    if(st==dr)
       return v[st];
    else
       {int m=(st+dr)/2;
       return binsum1(st,m)+binsum1(m+1,dr);}
}

void binsum2(int st,int dr)
{
    if(sum<a)
       {if(st==dr)
          {sum+=v[st];
          b++;}
       else
           {int m=(st+dr)/2;
           binsum2(st,m);
           binsum2(m+1,dr);}}
}

int main()
{
    f>>n>>m;
    for(i=1;i<=n;i++)
        f>>v[i];
    for(i=1;i<=m;i++)
       {
           f>>ct;
           if(ct==0)
              {
                  f>>a>>b;
                  v[a]+=b;
              }
           else
              if(ct==1)
                 {f>>a>>b;
                 g<<binsum1(a,b)<<'\n';}
              else
                 if(ct==2)
                    {
                        f>>a;sum=0;b=0;
                        binsum2(1,n);
                        if(sum==a)
                           g<<b<<'\n';
                        else
                           g<<-1<<'\n';
                    }
       }
    f.close();g.close();
    return 0;
}

