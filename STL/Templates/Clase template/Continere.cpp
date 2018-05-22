#include <iostream>

template <typename T> class A{
    T x;      ///x - obiect continut
};

template <typename T1,typename T2> class B{
    A<T1> a;   /// a-obiect continut
    T2    b;   /// b-obiect continut de asemenea
};

int main()
{
    B<int,char> b;  ///Corect. T1==int , T2==char
    B<int,A<char> > c; ///Corect. T1==int,T2== A<char>
    return 0;
}
