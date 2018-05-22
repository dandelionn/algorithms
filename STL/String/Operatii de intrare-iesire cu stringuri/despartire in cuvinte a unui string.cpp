#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int main()
{
    string s;
    string cuv;
    getline(cin,s);   ///Citesc de la tastatura un string
    istringstream iss(s);  ///Citesc din string si pun in iss
    while (iss>>cuv)    ///Extrag cate un cuvant din iss
         cout<<cuv<<'\n';
}
