#include <iostream>
#include <fstream>

using namespace std;

ifstream f("arbore.txt");

int t[20],pt[20],vizitat[20]={0},i,n,k;

int nodt()
{
    for(int i=1;i<n;i++)
       if(vizitat[i]==0)
           return 0;
    return 1;
}

int main()
{
    f>>n;

    for(i=1;i<=n;i++)
       f>>t[i];

    for(i=1;i<=n;i++)
       f>>pt[i];
    f.close();

    cout<<"Nodurile vizitate sunt: ";

    while(!nodt())
        {
        for(i=1; i<n && vizitat[t[i]] ;i++);

        k=i; vizitat[t[k]]=1; cout<<t[k]<<' ';

        for(i=k+1; i<n ;i++)
            if(pt[i]==pt[k])
               {cout<<t[i]<<' ';
               vizitat[t[i]]=1;}

        cout<<pt[k]<<' ';vizitat[pt[k]]=1;}
}
