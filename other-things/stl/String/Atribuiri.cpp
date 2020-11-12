#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s1,s2("DOI");
    s1="UNU";cout<<s1;
    s1=' ';cout<<s1;
    cout<<s1.assign(s2)<<' ';
    cout<<s1.assign(s2,1,2)<<' ';
    cout<<s1.assign("DOISPREZECE",7,4);
    cout<<" "<<s1.assign(5,'W');
    cout<<" "<<s1.assign("ABCDE",3);

    cout<<'\n'<<string::npos;

    return 0;
}
