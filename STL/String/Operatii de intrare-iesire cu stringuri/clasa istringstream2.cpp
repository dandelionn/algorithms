#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int main()
{
    int nr;
    string s;
    s="234 45 678 2 890";
    istringstream iss(s);    ///Construiesc un stream de intrare
                            ///cu valori citite din s
    while(iss>>nr)         ///Extrag din iss valori in formatul cerut (int)
         cout<<nr<<'\n';

    return 0;
}
