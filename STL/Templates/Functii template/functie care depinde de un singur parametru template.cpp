#include <iostream>
#include <string>

using namespace std;

template <typename type>

type Max(type a,type b)
{
    return a > b ? a : b;
}
int main()
{
    cout<<Max(8,9)<<'\n' ///Instantiere int Max(int, int)
        <<Max('Y','Z')<<'\n'  ///Instantiere char Max(char, char)
        <<Max(-3.4,6.7)<<'\n'; ///Instantiere double Max(double, double)
    string s1="programare",s2="generica";
    cout<<Max(s1,s2)<<'\n'; ///Instantiere string Max(string, string)
    cout<<Max("oniric","vis");  ///Instantiere const char* Max(const char*,const char*)
    return 0;
}
