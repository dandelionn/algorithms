#include <iostream>
using namespace std;
void afis(int x)
{ if (x>3)
cout<<x-1<<" ";
afis(x/3);
}
int main()
{
    int x;
    cout<<"x=";cin>>x;
    afis(x);
}
