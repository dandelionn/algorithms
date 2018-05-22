#include <iostream>
#include <fstream>

using namespace std;

ifstream f("arbore.txt");
struct stiva{int NP,PFNNP;};
stiva st[20];
int t[20],n,vf;

int nodt(int x)
{
    for(int i=1;i<=n;i++)
       if(t[i]==x)
          return 0;
    return 1;
}
void init(int r)
{
    int i=1;vf=1;
    while(i<=n&&t[i]!=r)
         i++;
    st[vf].NP=r;
    st[vf].PFNNP=i;
}
int este_vida()
{
    return  vf==0;
}
void adaug(int x,int y)
{
    vf++;st[vf].NP=x;st[vf].PFNNP=y;
}
void elimin()
{vf--;}
void prelucrare()
{
    int NC, PFNNC, NP, PFNNP, i;

    NC=st[vf].NP;
    PFNNC=st[vf].PFNNP;
    NP=PFNNC;
    i=PFNNC+1;

    cout<<NP<<' ';
    PFNNP=st[vf].PFNNP;
    elimin();


    while(i<=n && t[i]!=NC)
         i++;

    if(i<=n)
       {
           PFNNC=i;
           adaug(NC,PFNNC);
       }

    if(!nodt(NP))
       {i=PFNNP+1;
       while(i<=n && t[i]!=NP)
            i++;
       if(i<=n)
          {
              PFNNP=i;
              adaug(NP,PFNNP);
          }}
}
void citire()
{
    f>>n;
    for(int i=1;i<=n;i++)
        f>>t[i];
    f.close();
}
int rad()
{
    for(int i=1;i<=n;i++)
       if(t[i]==0)
          return i;
    return 0;
}
int main()
{
    int r;
    citire();
    r=rad();
    init(r);
    cout<<"Nodurile vizitate: "<<r<<' ';
    while(!este_vida())
        prelucrare();
}
