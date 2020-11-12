#include <iostream>

using namespace std;

template<class T1,class T2,class T3> class A{/*...*/};  ///Sablon primar

///Specializari partiale:
template<class N> class A<N,float,float>{/*...*/};
template<class N> class A<char,int,N>{/*...*/};

///Specializare explicita(completa):
template<> class A<float,string,char>{/*...*/};


int main()
{
    return 0;
}
