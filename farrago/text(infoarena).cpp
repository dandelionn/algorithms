#include <fstream>
#include <string.h>
using namespace std;
ifstream f("text.in");
ofstream g("text.out");
char a[256],b[256];
unsigned int n=0,nr=0,i;
int main()
{
    f.getline(a,256);
    for(i=0;i<strlen(a);i++)
    {
        if((a[i]>='a'&&a[i]<='z')||(a[i]>='A'&&a[i]<='Z'))
            nr++;
        else
        {
            a[i]=' ';
            if(a[i-1]!=' ')
              n++;
        }
    }
    n=n-1;
    g<<(int) nr/n;
    f.close();
    g.close();
}
