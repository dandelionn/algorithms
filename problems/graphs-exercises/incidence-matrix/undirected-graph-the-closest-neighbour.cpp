#include <fstream>
#include <iostream>
using namespace std;
ifstream f("graf7.in");
void vecini(int a[][3],int m,int p)
{
    int i,min=60000;
    cout<<"cei mai apropiati vecini sunt: ";
    for(i=1;i<=m;i++)
       if(a[i][0]==p||a[i][1]==p)
          if(a[i][2]<min)
             min=a[i][2];
    for(i=1;i<=m;i++)
       if(a[i][0]==p&&a[i][2]==min)
          cout<<'\n'<<a[i][1]<<" cu lungimea "<<a[i][2];
       else
          if(a[i][1]==p&&a[i][2]==min)
            cout<<'\n'<<a[i][0]<<" cu lungimea "<<a[i][2];
}
int main()
{
    int n,m,a[20][3],k,p;
    f>>n>>m;
    for(k=1;k<=m;k++)
           f>>a[k][0]>>a[k][1]>>a[k][2];
    cout<<"nodul ";cin>>p;
    vecini(a,m,p);
    f.close();
}
