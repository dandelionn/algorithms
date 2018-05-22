#include <iostream>
#include <string>
using namespace std;

int main()
{
    char a[]="Aniversare";
    string s1("Univers"),s2("Universalitate");

    if(s1.compare(s2)<0)
       cout<<"s1<s2\n";
    if(s1.compare(0,7,s2,0,7)==0)
       cout<<"subsiruri egale\n";
    if(s1.compare(1,3,a,2,5)>0)
       cout<<"subsiruri diferite";
    return 0;
}
