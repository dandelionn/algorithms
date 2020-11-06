#include <fstream>
using namespace std;

ifstream f("trie.in");
ofstream g("trie.out");

struct nod{int e,nr; struct nod* adr[26];}root;

void init( nod  *x )
{
    x->nr=0;
    x->e=0;
    for(int i=0; i<=25; i++ )
        x->adr[i]=0;
}
void addWord(char w[])
{
    nod *currentNod = &root;
    for(int i=0; w[i]!=0 ;i++)
        {
            if( currentNod -> adr[ w[i] - 'a' ] == NULL )
                   {
                    currentNod -> adr[ w[i] - 'a' ] = new nod;
                    init(currentNod -> adr[ w[i] - 'a' ]);
                   }

            currentNod = currentNod -> adr[ w[i] - 'a' ];
            currentNod->e++;
        }
    currentNod->nr++;

}

void eraseWord( char w[] )
{
    nod *currentNod = &root;
    for(int i=0; w[i]!=0 ;i++)
        {currentNod = currentNod -> adr[ w[i] - 'a' ];
        currentNod->e--;}
    currentNod->nr--;
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
    return currentNod -> nr;
}

int longestPrefix( char w[] )
{
    nod *currentNod = &root;
    int i;
    for(i=0; w[i]!=0 ;i++)
        {
        if( currentNod -> adr[ w[i] - 'a' ] == NULL )
            return i;

        currentNod = currentNod -> adr[ w[i] - 'a' ];
        if( currentNod->e < 1)
            return i;
        }
    return i;
}

int main()
{
    init( &root );

    int id;
    char w[21];
    while(f>>id)
        {
             f>>w;
             if( id == 0 )
                  addWord(w);
             else
                   if( id==1 )
                        eraseWord(w);
                   else
                         if( id==2 )
                             g << numberOfAparitions(w) <<'\n';
                         else
                             g << longestPrefix(w) <<'\n';
        }
   f.close(); g.close();
}
