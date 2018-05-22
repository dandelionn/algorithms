#include <iostream>
#include <fstream>
using namespace std;
ifstream f("statii.txt");
struct statii{int s,k;};
statii a[20];
int n,m;
void citeste()
{
    int i;
    f>>n>>m;
    for(i=1;i<=m;i++)
       {f>>a[i].s;a[i].k=i;}
    f.close();
}
void greedy()
{
    int i,s=0;
    for(i=1;i<=m;i++)
       if(s+a[i].s>n)
          {cout<<"statia "<<a[i-1].k<<'\n';
          s=a[i].s;}
       else
          s+=a[i].s;
}
int main()
{
    citeste();
    greedy();
}

