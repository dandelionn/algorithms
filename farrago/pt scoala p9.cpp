#include <iostream>
using namespace std;
struct data{int zi,an;char luna[15];};
struct meteo{data d;char nume[40];float p,t;}a[365];
unsigned int i,n;
float tmax=0;
int main()
{
    cout<<"Numarul de zile= ";cin>>n;
    for(i=0;i<n;i++)
       {
           cout<<'\n';
           cout<<"Introduceti data:"<<'\n';
           cout<<"Ziua ";cin>>a[i].d.zi;cin.get();
           cout<<"Luna ";cin.get(a[i].d.luna,15);cin.get();
           cout<<"An ";cin>>a[i].d.an;cin.get();
           cout<<"Numele meteorologului de serviciu: ";cin.get(a[i].nume,40);cin.get();
           cout<<"Presiunea atmosferica(mmHg) ";cin>>a[i].p;cout;cin.get();
           cout<<"Temperatura atmosferica("<<(char) 248<<"C) ";cin>>a[i].t;cin.get();
           if(a[i].t>tmax)
             tmax=a[i].t;
           cout<<"---------------------------------------"<<'\n';
       }
    cout<<'\n'<<'\n'<<"Temperatura maxima inregistrata("<<(char) 248<<"C)= "<<tmax<<'\n';
    cout<<"Temperatura maxima a fost inregistrata in data de:"<<'\n';
    for(i=0;i<n;i++)
       if(a[i].t==tmax)
         {
             cout<<a[i].d.zi<<' '<<a[i].d.luna<<' '<<a[i].d.an<<'\n';
             cout<<"Numele meteorologului de serviciu: "<<a[i].nume<<'\n';
         }
}
