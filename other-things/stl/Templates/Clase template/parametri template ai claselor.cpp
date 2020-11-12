#include <iostream>

template <class T,int n,template <class N> class A>
class B {/*...*/};
///este la fel de corecta constructia:
/*template <class T,int n, template <class> class A>
class B{...};*/

template <class T> class X {/*...*/};

int main()
{
    B<char,10,X> b; ///Corect. T==char,n==10,A==X
}
