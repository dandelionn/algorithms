#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;

int main()
{
    ///Creeaza un ostream iterator pentru stream-ul cout
    ostream_iterator<char> o1(cout);

    ///Operatii specifice iteratorilor
    *o1='A';  ///Insereaza 'A' in stream-ul cout
    o1++;     ///Fara efect
    o1='B';   ///Scrie 'B' pe ecran
    ++o1;     ///Fara efect
    o1='C';   ///Scrie 'C' pe ecran
    o1='\n';  ///Scrie '\n' pe ecran

    vector<int> v;
    v.push_back(20);
    v.push_back(10);
    v.push_back(30);

    ///Insereaza in cout toate elementele din v,
    ///delimitate de sirul " | ";
    copy(v.begin(),v.end(),ostream_iterator<int>(cout," | "));

    return 0;
}
