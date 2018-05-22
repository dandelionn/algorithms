#include <fstream>
using namespace std;
ifstream f("fractii.in");
ofstream g("fractii.out");
unsigned int nr,Q,P,N,a,b,x,k,d;
int main()
{
    f>>N;
    nr=(N*2)-1;
    for(P=3; P<=N; P++)
    {
        d=2;
        k=0;
        while(d<=P/2)
        {
            if(P%d==0)
                k++;
            d++;
        }
        if(k!=0)
            nr+=(P-k)*2-2;
    }
    g<<nr<<'\n';
    g.close();
    f.close();
}
