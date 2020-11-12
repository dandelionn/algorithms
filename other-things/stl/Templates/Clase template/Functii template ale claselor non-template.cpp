#include <iostream>

class A {         ///clasa non-template
    public:
    template <typename U,typename V>
    void F(U u,V v)  ///functie membra template
    {
        std::cout<<u<<"  "<<v<<'\n';
    }
};
int main()
{
    A a[100];
    a[1].F<int,char>(45,'Y');    ///Specificare explicita a
                             ///argumentelor template.
   a[1].F(45,'Y');        ///Deducerea argumentelor template
   a[2].F<double,char>(45.67,'Z');
   a[2].F("cool",424654654);
   return 0;
}
