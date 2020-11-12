#include <iostream>
#include <vector>

using namespace std;

int main()
{
    const int DIM=5;         ///compile-time
    int x[DIM];
    vector<int> a(DIM);

    int n;
    cin>>n;    ///run-time
    int y[n];           ///Ilegal! but legal???
    vector<int> b(n);   ///Corect! Alocare dinamica.
    for(int i=0;i<n;i++)
       cin>>b[i];
    for(int i=n-1;i>=0;i--)
       cout<<b[i]<<' ';
    cout<<'\n';

    for(int i=1;i<=n;i++)
        cin>>y[i];
    for(int i=1;i<=n;i++)
        cout<<y[i]<<' ';

    return 0;
}
