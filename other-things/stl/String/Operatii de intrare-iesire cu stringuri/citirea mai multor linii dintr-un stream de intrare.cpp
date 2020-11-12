#include <iostream>
#include <string>
using namespace std;
int main()
{
    string s;
    while( getline(cin,s) )  ///Citeste cate o linie
        cout<<s<<'\n';       ///Inchideti stream-ul cin cu Ctrl+Z
    return 0;
}
