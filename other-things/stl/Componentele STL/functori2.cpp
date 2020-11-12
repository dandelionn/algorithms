#include <iostream>
#include <algorithm>
using namespace std;

class Scrie{
    public:
        void operator() (int elem) const
        {
            cout<<elem<<' ';
        }
};
int main()
{
    int a[]={1,-3, 4, 9};
    for_each(a,a+4,     ///Proceseaza intervalul [a,a+4)
             Scrie());  ///Operatia aplicata
}
