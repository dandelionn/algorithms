#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s("ABCDEF");
    string::iterator it;
    it=s.erase(s.begin()+1);
    cout<<*it<<' '<<s<<'\n';

    it=s.erase(s.begin()+1,s.begin()+3);
    cout<<*it<<' '<<s<<'\n';
    s.erase(2);   ///Sterge elementul de pe pozitia 2
    cout<<s<<'\n';
    s.erase();    ///Sterge toata secventa
    return 0;
}
