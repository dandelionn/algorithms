#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main()
{
    string s="STL";
    ostringstream os;

    ///Inserez in stream diverse valori
    os<<"Salut "<<s<<' '<<2013<<"!\n";
    s=os.str();    ///Scriu continutul stream-ului in string
    cout<<s;
    return 0;
}
