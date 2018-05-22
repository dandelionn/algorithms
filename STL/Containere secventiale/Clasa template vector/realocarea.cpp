#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> v;
    for(int i=0;i<18;i++)
    {
        cout<<v.size()<<' '<<v.capacity()<<'\n';
        v.push_back(i);
    }


    vector<int> v1;   ///Capacitate 0;
    v1.push_back(54);  ///Realocare.Capacitate 1

    vector<int>::iterator it(v1.begin());
    cout<<*it<<'\n';   ///Afiseaza 54

    ///it va fi invalidat prin realocare
    v.push_back(90);   ///Realocare.Capacitate 2
    cout<<*it<<'\n';       ///Eroare! Comportament nedefinit !

    return 0;
}
