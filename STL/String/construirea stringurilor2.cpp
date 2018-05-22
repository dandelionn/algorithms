#include <iostream>
#include <string>
using namespace std;

string s("COPIERE ");

int main()
{
    string s1;

    string s2=string(s);   ///Construieste s2, s3, s4
    string s3(s2), s4=s3;  ///prin copierea obiectului s

    cout<<s1  ///Nu se afiseaza nimic
        <<s2<<s3<<s4;
    return 0;
}
