#include <fstream>
using namespace std;
ifstream f("culori3.in");
ofstream g("culori3.out");
unsigned int k=0;
void culori(int i,int n)
{
    if(n==1)
       k++;
    else
        {
            if(i>1)
               culori(i-1,n-1);
            if(i<5)
               culori(i+1,n-1);
        }
}
int main()
{
    unsigned int i,n;
    f>>n;
    for(i=1;i<=5;i++)
       culori(i,n);
    g<<k;
}
