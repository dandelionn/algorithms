
#include <iostream>
#include <exception>
#include <vector>

using namespace std;

int main()
{
    vector<int> v(5);
    for(int i=0;i<5;i++)
        cin>>v[i];
    for(int i=0;i<5;i++)
        cout<<v.at(i)<<' ';
    v[0]=45;
    v[9]=70;   ///Comportament nedefinit,but is this working???
    cout<<'\n'<<v[0]<<' '<<v[9]<<'\n';
    try{
        v.at(10)=56;   ///Arunca exceptia out_of_range
    }catch(exception e){
        cout<<"Exceptie! ";
    }
    cout<<v[10];
    return 0;
}
