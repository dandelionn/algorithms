///M[i][j] se executa in O(logN*logM).
#include <iostream>
#include <map>
#include <iomanip>
using namespace std;

map<int,map<int,int> > M;  ///Cheia are tipul int.Valoarea
                           ///asociata este un map<int,int>
int main()
{
    int m,n;
    cin>>m>>n;
    for(int i=0;i<m;i++)
       for(int j=0;j<n;j++)
           cin>>M[i][j];

    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
           cout<<setw(10)<<M[i][j];
        cout<<'\n';
    }
    return 0;
}
