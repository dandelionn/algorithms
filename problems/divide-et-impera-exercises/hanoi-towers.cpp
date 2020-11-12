#include <iostream>
using namespace std;
void hanoi(int n,char a,char b,char c)
{
    if(n==1)
       cout<<"Mutarea :"<<a<<"->"<<b<<'\n';
    else
       {
           hanoi(n-1,a,c,b);
           cout<<"Mutarea :"<<a<<"->"<<b<<'\n';
           hanoi(n-1,c,b,a);
       }
}
int main()
{
    int n;
    char a='A',b='B',c='C';
    cout<<"n= ";cin>>n;
    hanoi(n,a,b,c);
}
