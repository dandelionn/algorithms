#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    char a[]="String's world";
    vector<char> v(a,a+14);

    string s1(a,a+14);    ///Copiaza [a,a+14)
    string s2(&a[0],&a[14]);   ///Identic

    string s3(v.begin(),v.begin()+6);
    string s4=string(a,a+6);

    cout<<s1<<'\n'<<s2<<'\n'
       <<s3<< ' ' <<s4<<'\n';

    return 0;
}
