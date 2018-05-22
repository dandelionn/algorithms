#include <iostream>

/// Sablon primar
template<class T1,class T2,char c> class A{/*...*/};

template <class T1, class T2> class A<T2*,T1,'Y'>{/*...*/};

template <class T, char c> class A<T, T, c>{/*...*/};

template <class T> class A<float, T , 'K'>{/*...*/};

template <class T> class A<T, T* , 'J'>{/*...*/};

int main()
{
return 0;
}
