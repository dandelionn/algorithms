#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s(7,'Y');           ///Creeaza s cu 7 elemente de val. 'Y'
    string ss=string(3,'A');  ///Creeaza ss cu 3 elemente 'A'
    cout<<s<<' '<<ss<<'\n';

    char a[]="SALUT ";

    string s1(a);
    string s2=string(a);
    string s3="VOIOS!";   ///Conversie implicita

    cout<<s1<<s2<<s3;

    string s4("NICIODATA",4);   ///Initializeaza s4 cu "NICI"
    string s5=string(a,3);      ///Initializeaza s5 cu "SAL"
    cout<<s4<<" "<<s5;

    return 0;
}
