#include <iostream>
#include <string>
using namespace std;

void F(string s)
{cout<<s<<'\n';}

void G(const char* str)
{cout<<str<<'\n';}

int main()
{
    string s("string");
    char a[]="string C";
    F(s);
    F(a);             ///conversie implicita
    G(a);
    //G(s);          ///Eroare   conversie imposibila
    G(s.c_str());       ///conversie explicita
    return 0;
}
