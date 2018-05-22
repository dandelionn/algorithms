#include <fstream>
#include <iostream>
#include <algorithm>

using namespace std;
ifstream f("energii.in");
ofstream g("energii.out");

struct el{int e,c;}a[10002];
int G,W,i,C=0,E;

struct cmp{
   bool operator()(el a,el b) const
     {
       if(a.c<b.c)
            return 1;
       else
            return 0;
     }};

int main()
{
    f>>G>>W;
    for(i=1;i<=G;i++)
        f>>a[i].e>>a[i].c;
    sort(a+1,a+G+1,cmp());
    for(i=1;i<=G;i++)
        cout<<a[i].c;

    for(i=1;i<=G;i++)
        {E+=a[i].e;
        C+=a[i].c;
        if(E>=W)
            i=G+1;}

    if(E>=W)
       cout<<C;
    else
       cout<<-1;
}
