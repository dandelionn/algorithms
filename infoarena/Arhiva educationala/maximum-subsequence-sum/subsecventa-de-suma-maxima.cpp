#include <fstream>
#include <iostream>
using namespace std;
ifstream f("ssm.in");
ofstream g("ssm.out");
const int Nmax=6000001;
int a[Nmax],n,bestsum,best[Nmax],sum[Nmax];
int main()
{
    int i,min;
    f>>n;
    for(i=1;i<=n;i++)
       {f>>a[i];
       a[i]=-i;}
    cout<<sum[0]<<'\n';
    for(i=1;i<=n;i++)
        {sum[i]=a[i]+sum[i-1];
        cout<<sum[i]<<' ';}
    cout<<'\n';
    min=sum[0];          //min are initial valoare lui sum[0],adica valoarea 0;
    bestsum=-100000;      //min va retine secventa de suma minima negativa sau valoarea initiala(adica 0) daca nu exista secvente cu suma<0;
    cout<<min<<' '<<bestsum<<'\n';
    for(i=1;i<=n;i++)
       {
            cout<<'\n'<<"i="<<i<<'\n';
           best[i]=sum[i]-min;        //daca min este negativ(-(-)=+) se va inlatura din suma[i] seventa cu valoare negativa (care scade valoarea numarului)
           cout<<best[i]<<'\n';
           if(min>sum[i])         //daca intalneste o suma negativa(<0) min primeste valoarea acesteia
              min=sum[i];
           if(bestsum<best[i])    //bestsum retine suma maxima gasita la un moment dat;
              bestsum=best[i];
           cout<<min<<' '<<bestsum<<'\n';
       }
    cout<<"valoare maxima="<<bestsum;
}
