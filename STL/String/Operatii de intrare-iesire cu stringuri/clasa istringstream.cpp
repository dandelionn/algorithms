#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int main()
{
    int nr;
    string s("2013");
    istringstream is;   ///Declar un obiect istringstream
    is.str(s);          ///Citesc din s si introduc in is
    is>>nr;             ///Extrag din is si scriu in nr

    cout<<nr;        ///Scrie 2013(valoare int)

    return 0;
}
