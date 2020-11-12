#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s("ABCDEFG");

    string s1(s,3);  ///Creeaza s1 copiind toate elementele din s
                     ///incepand cu pozitia 3
    cout<<s1;
    string s2=string(s,5);  ///Creeaza s2 copiind toate elementele
                           ///din s incepand cu pozitia 5
    cout<<'\n'<<s2;

    string s3(s,2,3);
    cout<<'\n'<<s3;

    string s4=string(s,2,20);
    cout<<'\n'<<s4;

    return 0;
}
