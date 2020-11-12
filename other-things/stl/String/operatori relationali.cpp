#include <iostream>
#include <string>
using namespace std;

int main()
{
    char a[]="unu";
    string s1("Unu"),s2;
    cin>>s2;
    if( s1 < s2 ) cout<<" s1 < s2 ";
    if( s1 <= s2 ) cout<<" s1 <= s2 ";
    if( s1 > s2 ) cout<<" s1 > s2 ";
    if( s1 >= s2 ) cout<<" s1 >= s2 ";
    if( s1 != s2 ) cout<<" s1 != s2 ";
    if( s1 == s2 ) cout<<" s1 == s2 ";

    if( s1 < a ) cout<<" s1 < a ";
    if( a < s1 ) cout<<" a < s1 ";
    // ...
    return 0;
}
