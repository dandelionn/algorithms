#include <iostream>
#include <stdlib.h>
#include <windows.h>

using namespace std;
int main()
{
   int i,m=1;
   cout<<"i=";cin>>i;
   while(m) //bucla infinita
       cout<<rand()%i<<' ';
}
