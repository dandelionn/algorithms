#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    string s1("ABC"),s2("XYZ");
    cout<<s1.insert(2,s2)<<'\n';
    s1="ABC";
    cout<<s1.insert(1,s2,1,2)<<'\n';

    s1="ABC";
    cout<<s1.insert(3,"PQR")<<'\n';

    s1="ABC";
    cout<<s1.insert(0,3,'K')<<'\n';

    s1="ABC";
    s1.insert(s1.end(),'T');
    cout<<s1<<'\n';

    s1="ABC";
    vector<char> v(s2.begin(),s2.end());
    s1.insert(s1.end(),v.begin(),v.end());
    cout<<s1<<'\n';
    return 0;
}
