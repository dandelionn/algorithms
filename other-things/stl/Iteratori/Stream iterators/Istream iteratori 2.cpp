#include <iostream>
#include <iterator>
#include <algorithm>
using namespace std;

int main()
{
    ///Construieste un istream iterator
    ///Si un end-of-stream iterator
    istream_iterator<int>is_it(cin),eos_it;

    while(is_it!=eos_it)
    {                       ///*is_it returneaza
        cout<<*is_it<<" ";  ///valoarea citita.
        ++is_it;            ///Citeste valoare si
    }                       ///returneaza un iterator la ea
    return 0;
}
