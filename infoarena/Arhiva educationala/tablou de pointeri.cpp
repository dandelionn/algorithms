#include <iostream>
#include <fstream>

using namespace std;

ifstream f("trie.in");
ofstream g("trie.out");

struct nod{int a,b; nod *p[26];} *arb;

int x;
char a[27];

int main()
{
    arb=new nod;
    arb->a=1;
    arb->p[20]=new nod;
    arb->p[20]->a=1;
    cout<<arb->p[20]->a;

}
