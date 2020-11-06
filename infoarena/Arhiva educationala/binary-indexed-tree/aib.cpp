#include <fstream>
using namespace std;

ifstream f("aib.in");
ofstream g("aib.out");

#define zeros(x) ((x^(x-1))&x)

int c[100001],m,n;

void build()
{
    int i,j,end;
    for(i=1;i<=n;i++)
        {f>>c[i];
        end=i-zeros(i)+1;
        for( j=i-1; j>=end; j-=zeros(j) )
             c[i]+=c[j];}
}
void add(int a,int b)
{
    for(;a<=n;a+=zeros(a))
        c[a]+=b;
}
int compute(int x)
{
    int sum=0;
    for(;x>0;x-=zeros(x))
       sum+=c[x];
    return sum;
}
int search(int p,int u,int val)
{
    if(p<=u)
      {int m=(p+u)/2,sum;
      sum=compute(m);
      if(sum==val)
         return m;
      else
         if(sum<val)
            search(m+1,u,val);
         else
            search(p,m-1,val);}
    else
        return -1;
}
int main()
{
    int a,b,ct,i;

    f>>n>>m;

    build();

    for(i=1;i<=m;i++)
       {f>>ct;
       if(ct==0)
          {f>>a>>b;
          add(a,b);}
       else
          if(ct==1)
             {f>>a>>b;
             g<<compute(b)-compute(a-1)<<'\n';}
          else
             if(ct==2)
               {f>>a;
               g<<search(1,n,a)<<'\n';}}

    g.close();
    f.close();
    return 0;
}
