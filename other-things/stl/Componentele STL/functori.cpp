#include <iostream>

struct A{
    template <class T>
    T operator() (T t) const   ///supraincarcare operator()
    { return t; }
};

int main()
{
    A a;   ///a este un functor
    std::cout<<a("HI")<<" "<<a(3434)<<"  "<<a('T');

    return 0;
}
