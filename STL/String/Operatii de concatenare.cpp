#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main()
{
    string d1("Standard "), d2("Template ");
    char d[]="Librar";
    cout<<d1+d2+d+'y'<<'\n';

    string s1,s2,s3("de catre tine");
    s1.append("Lungul");
    cout<<s1.append("pe drum",2,5)<<'\n';

    s2.append(s1);
    s2+=' ';
    s2+="al noptii";
    s2.append(s3,2,7);

    char a[]="azi stau";
    vector<char> v(a,a+8);
    s2.append(v.begin()+1,v.begin()+3);
    s2.push_back(' ');
    cout<<s2.append(3,'.');

    return 0;
}
