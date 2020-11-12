#include <iostream>
#include <string>
using namespace std;

void Scrie(string::size_type  i)
{
    if(i!=string::npos)
       cout<<"Gasit!Incepe la pozitia"<<i<<'\n';
    else
       cout<<"Nu s-a gasit\n";
}

int main()
{
    string s1("ABCDEF"), s2;
    string::size_type pos;
    cin>>s2;

    pos =s1.find(s2);
    Scrie(pos);
    pos =s1.find(s2,2);
    Scrie(pos);
    pos =s1.find("CDE");
    Scrie(pos);
    pos =s1.find("CDE",2);
    Scrie(pos);
    pos =s1.find_first_of("KDAT");
    Scrie(pos);
    cout<<s1.substr(2,3)<<'\n';

    pos =s1.rfind(s2);
    Scrie(pos);
    pos =s1.rfind(s2,2);
    Scrie(pos);
    pos =s1.rfind("CDE");
    Scrie(pos);
    pos =s1.rfind("CDE",2);

    return 0;
}
