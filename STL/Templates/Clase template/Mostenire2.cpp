#include <iostream>
///Clasa sablon mosteneste o clasa template:

template <typename T> class A{
    T t;
    //...
};

template <typename T1,typename T2>
class B:public A<T2>{
   T1 t1;
   //...
};
int main()
{
    B<int,char> ob1;   ///T1==int,T2==char
    return 0;
}
