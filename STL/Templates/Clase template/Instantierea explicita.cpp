#include <iostream>
using namespace std;

template <typename Tip> class A{Tip G;};

int main()
{
    A<float> *p;
    ///template A<float>; ???instantiere explicita
    class A<int>;    ///<-sau instantiere explicita
    class A<double>;
}
