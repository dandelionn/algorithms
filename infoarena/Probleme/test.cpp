#include <fstream>
#include <string.h>

using namespace std;
ifstream f("text.in");
ofstream g("text.out");
char a;
unsigned int n=0,nr=0,i;
int main()
{
        while(f.get(a))
            {
             if((a>='a'&&a<='z')||(a>='A'&&a<='Z'))
                 {while((a>='a'&&a<='z')||(a>='A'&&a<='Z'))
                       {f.get(a);
                        nr++;}
                  n++;}
            }

    g<<nr/n;
    f.close();
    g.close();
}
