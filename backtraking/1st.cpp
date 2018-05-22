#include <iostream>
#include <iostream>
using namespace std;
int n,sol[10];
int succesor(int k)
{
    if(sol[k]<n)
    {
        sol[k]++;
        return 1;
    }
    else
        return 0;
}
int valid(int k)
{
    int i ,ev=1;
    for(i=1; i<=k-1; i++)
        if(sol[k]==sol[i])
            ev=0;
    return ev;
}
void back(int k)
{
    if(k==n+1)
    {
        for(int i=1; i<=n; i++)
            cout<<sol[i];
        cout<<'\n';
    }
    else
    {
        sol[k]=0;
        while(succesor(k))
            if(valid(k))
                back(k+1);
    }
}
int main()
{
    cout<<"n=";
    cin>>n;
    back(n);
}
