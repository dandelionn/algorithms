#include <iostream>

class A{
    public:
    template<typename U,typename V>
    void F(U u,V v);
};

template<typename U,typename V>
void A::F(U u,V v)
{
    std::cout<<u<<"  "<<v<<'\n';
}

int main()
{
    A a;
    a.F<int,const char*>(45,"text");
    a.F(45.5,"t");
    return 0;
}
