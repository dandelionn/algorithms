#include <fstream>
#include <vector>

using namespace std;
ifstream f("flip.in");
ofstream g("flip.out");

long long int a[17][17],s=0,s1;
int n,m;
void sum()
{
    int i,j;s1=0;
    for(i=1;i<=n;i++)
       for(j=1;j<=m;j++)
           s1+=a[i][j];
    if(s1>s)
       s=s1;
}
void linia(int l)
{
    for(int j=1;j<=m;j++)
        a[l][j]=a[l][j]*(-1);

}
void coloana(int c)
{
    for(int i=1;i<=n;i++)
        a[i][c]=a[i][c]*(-1);
}

bool isSet (size_t pos, long long n )
{
    long long mask;
    mask = 1 << (pos - 1);

    return (n & mask) != 0;
}

void sets ( vector<int> &v )
{
        for (unsigned long long count = 0; count <= (1 << v.size() - 1 ) - 1; count ++)
        {
                for (size_t i = 1; i < v.size(); i++)
                    if (isSet (i, count))
                        if(v[i]<=n)
                           linia(v[i]);
                        else
                           coloana(v[i]-n);
                sum();

        }


}

int main()
{
    int i,j;
    f>>n>>m;
    for(i=1;i<=n;i++)
       for(j=1;j<=m;j++)
           {f>>a[i][j];
           s+=a[i][j];}

    vector <int> v;
    v.push_back(0);
    for(int i=1;i<=n+m;i++)
        v.push_back(i);


    sets( v );

    g<<s;
    f.close(); g.close();

    return 0;
}
