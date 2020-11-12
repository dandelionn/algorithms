#include <iostream>
#include <utility>
using namespace std;

int main()
{
    pair<int, double> p1;  ///creeaza perechea
    cout<<p1.first<<" "<<p1.second<<'\n';   ///0 0.

    pair<float,const char*> p2(4.5,"Hi");
    cout<<p2.first<<" "<<p2.second<<'\n';   ///4.5 Hi

    pair<int,string> a[20];
    a[0].first=1;   a[0].second="yabadabadu";
    a[1].first=2;   a[1].second="yabadabadooooo";
    cout<<'\n'<<a[0].first<<' '<<a[0].second<<'\n';
    cout<<a[1].first<<' '<<a[1].second<<'\n';
//____________________________________________________________
    pair<int, double>::first_type n=10;
    pair<int, double>::second_type d=10.11;
    ///      /\
    ///      ||
    ///      \/
    //int n=10;
    //double d=10.11;
//____________________________________________________________
   ///Functia make_pair()
   make_pair(5.4,"Hi"); //in locul apelului constructorului: pair<float,char*>(5.4,"Hi");
   make_pair(6,'Y');   //in locul pair<char,int>(6,'Y');

    return 0;
}
