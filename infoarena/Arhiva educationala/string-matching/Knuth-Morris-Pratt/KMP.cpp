#include <fstream>
#include <string.h>
#include <iostream>
using namespace std;

ifstream f("strmatch.in");
ofstream g("strmatch.out");

int n,m,urm[10000001];
char a[10000001],b[10000001];


void Urmatorul(char a[],int m)
{
    int k,i;
    urm[1]=0;
    k=0;
    cout<<"urm[1]=0"<<'\n';
    cout<<"k=0"<<'\n';
    for(i=2;i<=m;i++)
       {cout<<"______________________________________"<<'\n';
       cout<<"i="<<i<<'\n';
       while( k>0 && a[k+1]!=a[i] )
            {cout<<"k=urm["<<k<<"]=";
            k=urm[k];
            cout<<k<<'\n';}
        if( a[k+1]==a[i] )
           {k=k+1;
           cout<<"k="<<k<<'\n';}
        urm[i]=k;
        cout<<"urm["<<i<<"]="<<k<<'\n';}
}

void potrivire(char a[],char b[],int n,int m)
{
    int i,k,j;
    k=0;
    cout<<"k=0"<<'\n';
    for(i=1;i<=n;i++)
        {cout<<"______________________________________"<<'\n'<<' ';
        for(j=1;j<=m;j++)
            cout<<j;
        cout<<'\n'<<a<<'\n';
        cout<<b<<'\n';
        cout<<"a["<<k+1<<"]="<<a[k+1]<<' '<<"b["<<i<<"]="<<b[i]<<'\n';
        cout<<"i="<<i<<'\n';
        while( k>0 && a[k+1]!=b[i] )
            {cout<<"k=urm["<<k<<"]=";
            k=urm[k];
            cout<<k<<'\n';
            cout<<"a["<<k+1<<"]="<<a[k+1]<<' '<<"b["<<i<<"]="<<b[i]<<'\n';}
        if( a[k+1]==b[i] )
            {k=k+1;
           cout<<"k="<<k<<'\n';}          ///s-a mai gasit un caracter corect
        if(k==m)
           {g<<i-m<<'\n';
           cout<<"k=urm["<<k<<"]=";
           k=urm[k];
           cout<<k<<'\n';}}
}



int main()
{
    ///a-sirul care se cauta
    f>>a>>b;
    m=strlen(a);n=strlen(b);

    int i;
    for(i=m+1;i>=1;--i)
        a[i]=a[i-1];
    for(i=n+1;i>=1;--i)
        b[i]=b[i-1];
    a[0]=' ';b[0]=' ';

    cout<<"Urmatorul:"<<'\n';
    Urmatorul(a,m);
    cout<<'\n'<<"urm=[";
    for(int i=1;i<=m;i++)
       cout<<urm[i]<<',';
    cout<<"\b]"<<"\n\n";
    cout<<"Potrivire:"<<'\n';
    potrivire(a,b,n,m);

    f.close();
    g.close();
}
