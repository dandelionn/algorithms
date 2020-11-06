#include <fstream>

using namespace std;


ifstream f("damesah.in");
ofstream g("damesah.out");
int a[15],n;
int dp[30],ds[30],col[15],nr=0;

void back(int k)
{
    int i,e;
    if(k<=n)                                  ///k-linia    ///a[k]-coloana
       for(i=1;i<=n;i++)
            {
                if(k<i)
                    e=n+(i-k)+1;
                else
                    e=k-i+1;
                if(col[i]==0 && ds[k+i]==0 && dp[e]==0 )
                   {col[i]=1;    ds[k+i]=1;    dp[e]=1;
                    a[k]=i;
                    back(k+1);
                    col[i]=0;    ds[k+i]=0;    dp[e]=0;}
            }
    else
        {
            if(nr==0)
                {for(i=1;i<=n;i++)
                    g<<a[i]<<' ';
                g<<'\n';}
            nr++;}
}



int main()
{
    int i;

    f>>n;
    for(i=1;i<=14;i++)
        col[i]=0;
    for(i=1;i<=29;i++)
        {ds[i]=0;
        dp[i]=0;}
    back(1);
    g<<nr;

    f.close(); g.close();
}
