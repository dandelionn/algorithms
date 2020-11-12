#include <iostream>

template <typename T> class A{
    //...
};

///Sablon primar
template <class T,char c,template<class> class X>
class B{
    //...
};

///Specializare explicita
template<> class B<float,'R',A>{   ///furnizeaza argumente pentru toti
    /*...*/                       ///parametri template
};
int main()
{
    return 0;
}
