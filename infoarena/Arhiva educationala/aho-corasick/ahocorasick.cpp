#include <fstream>
#include <string.h>
using namespace std;

ifstream f("ahocorasick.in");
ofstream g("ahocorasick.out");

struct nod{int e; struct nod* adr[26];}root;

void init( nod  *x )
{
    x->e=0;
    for(int i=0; i<=25; i++ )
        x->adr[i]=0;
}
void addWord(int i,int j,char w[])
{
    nod *currentNod = &root;
    for(;i<=j ;i++)
        {
            if( currentNod -> adr[ w[i] - 'a' ] == NULL )
                   {
                    currentNod -> adr[ w[i] - 'a' ] = new nod;
                    init(currentNod -> adr[ w[i] - 'a' ]);
                   }

            currentNod = currentNod -> adr[ w[i] - 'a' ];
            currentNod->e++;
        }
}

int numberOfAparitions( char w[] )
{
    nod *currentNod = &root;

    for(int i=0; w[i]!=0 ;i++)
           {
           if(currentNod -> adr[ w[i] - 'a' ] != NULL)
                 {currentNod = currentNod -> adr[ w[i] - 'a' ];
                 if(currentNod->e < 1)
                     return 0;}
           else
                 return 0;
            }
    return currentNod -> e;
}

int main()
{
    init( &root );
    int n,fin;
    char w[21];
    char a[100001];

    f>>a;
    fin=strlen(a);
    for(int i=0;i<fin;i++)
        if(fin-i>= 10000)
            addWord(i,i+9999,a);
        else
            addWord(i,fin-1,a);

    f>>n;
    for(int i=1;i<=n;i++)
         {f>>w;
         g << numberOfAparitions(w) <<'\n';}

    f.close(); g.close();
}
