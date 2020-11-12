#include <fstream>

using namespace std;

ifstream f("aib.in");
ofstream g("aib.out");

int n,m,v[100001];
void modific()
{
    int a,b,ok;
    f>>a>>b;
    v[a]+=b;
    if(a%4==0)
       a+=4;
    else
       while(a%4!=0)
            {a++;
            if(a%4!=0&&a%2==0)
               v[a]+=b;}
    while(a<=n)
        {v[a]+=b;
        a+=4;}
}
int cstrt(int x)
{
    int s=0,ok;
    while(x%4!=0)
         {if(x%2==0)
            {s+=v[x];
            ok=x;}
          if(ok!=x+1)
             s+=v[x];
          x--;}
    return s+v[x];
}
void sum()
{
    int a,b;
    f>>a>>b;
    a=a-1;
    g<<cstrt(b)-cstrt(a)<<'\n';
}
void frfirst()
{
    int a,i=4;
    f>>a;
    while(v[i]<a&&i<=n)
         i+=4;
    if(i>n)
       g<<-1<<'\n';
    else
       if(v[i]==a)
          g<<i<<'\n';
       else
          {i=i-4;
          if((v[i]+v[i+2]+v[i+3])==a)
            g<<i+3<<'\n';
          else
             if((v[i]+v[i+2])==a)
                g<<i+2<<'\n';
             else
                if((v[i]+v[i+1])==a)
                    g<<i+1<<'\n';
                else
                   if(v[i]==a)
                      g<<i<<'\n';
                   else
                      g<<-1<<'\n';}
}
int main()
{
    int ct,i;
    f>>n>>m;
    v[0]=0;
    for(i=1;i<=n;i++)
       f>>v[i];

    for(i=1;i<=n;i++)
        if(i%4==0)
           v[i]+=v[i-1]+v[i-2]+v[i-4];
        else
           if(i%2==0)
              v[i]+=v[i-1];

    for(i=1;i<=m;i++)
       {
           f>>ct;
           if(ct==0)
              modific();
           else
              if(ct==1)
                 sum();
              else
                 if(ct==2)
                    frfirst();
       }
    f.close();
    g.close();
    return 0;
}
