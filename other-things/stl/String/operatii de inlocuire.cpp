#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s1("ABCDEF"), s2("bcde");
    s1.replace(1,3,s2);        // sau
    cout<<s1;                  //   cout<<s1.replace(1,3,2);

    s1="ABCDEF"; cout<<'\n';
    cout<<s1.replace(1,2,s2,0,3);

    s1="ABCDEF";  cout<<'\n';

    cout<<s1.replace(s1.begin(),s1.begin()+1,s2)<<'\n';
    s1.replace(s1.begin(),s1.begin()+8,s2.begin(),s2.end());
    cout<<s1<<'\n';

    s1="ABCDEF";
    cout<<s1.replace(1,3,2,'W')<<'\n';

    s1="ABCDEF";
    cout<<s1.replace(s1.begin()+1,s1.end(),"DCB",2);

    return 0;
}
