#include <iostream>
#include <iterator>
#include <algorithm>
using namespace std;

int main()
{
    copy(istream_iterator<string>(cin),   ///Citeste din cin
         istream_iterator<string>(),     ///pana la end-of-stream
         ostream_iterator<string>(cout,"\n"));   ///Scrie in cout

    return 0;
}
