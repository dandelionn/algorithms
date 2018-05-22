#include <iostream>
#include <set>
using namespace std;

int main()
{
    multiset<char> s1;
    multiset<float> s2;
    ///if(s1==s2)      //Eroare.Tipul elementelor nu este acelasi.
       /*...*/
    set<int> s3;    ///Criteriul este dat de tipul less<int>
    set<int, greater<int> > s4;
    ///if(s3<s4)       //Criteriul de comparatie nu este acelasi.
       /*...*/

    return 0;
}
