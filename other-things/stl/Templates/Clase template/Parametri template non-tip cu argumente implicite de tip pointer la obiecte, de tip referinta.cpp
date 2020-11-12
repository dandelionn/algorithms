#include <iostream>
class X{/*..*/};
X ob1,ob2;
template <X* P=&ob1> class Y{/*...*/};

int main()
{
    Y<> y1;   ///Corect. P==&ob1
    Y<&ob2> y2;   ///Corect.
    return 0;
}
