#include <iostream>
#include <vector>
using namespace std;

int a;

int main()
{
    vector<int> v;
    for(int i=0;i<5;i++)
       {
           cin>>a;
           v.push_back(a);  ///Vectorul se modifica dinamic
       }
    cout<<v.size()<<'\n';
    for(int i=0;i<v.size();i++)
        cout<<v[i]<<' ';


    /**
    vector<char> c(5);
    c[5]='X';  ///Eroare! ultimul element valid
               ///in container era c[4]

    vector<float> c1;  ///Container vid(0 elemente)
    c1[0]=56.3;       ///Eroare! c1[0] nu exista
    c1[1]=-5.7;       ///Eroare! c1[1] nu exista
    **/

    return 0;
}
