#include <functional>
#include <iostream>
using namespace std;

int main()
{
    int x=4,y=2;
    if(greater<int>()(x,y))
      cout<<" x > y ";
    if(not_equal_to<int>()(x,y))
      cout<<" x != y ";


    multiplies<int> M;  ///Construieste un obiect functie
    cout<<M(x,y);

    return 0;
}
