#include <iostream>
using namespace std;
template<class T1,class T2,class T3>   ///T1,T2,T3 parametri template tip
void F(T1 a,T2 b,T3 c)
{
    cout<<a<<" "<<b<<" "<<c<<" tip\n";
}

enum E{elem=10};

template <int n,char c, E e>    ///parametrii template non-tip
void F()
{
    cout<<n<<" "<<c<<" "<<e<<" non-tip\n";
}
template<int n>
void F()
{
    ///n++;    ///Eroare. Valoarea nu poate fi modificata
}

template<typename T,int n>
void scrie(T t[])
{
    for(int i=0;i<n;i++)
       cout<<t[i]<<' ';
}

int main()
{
    const int N=200;
    F<N>();

    int M=100;
    ///F<M>();       ///Eroare

    const char C='o';
    F<N,C,elem>();

    int i=1;
    char j='i';
    double r=0.2201;
    F(i,j,r);

    int h[]={1,2,3,4,5,6,7,6,3};
    scrie<int,9>(h);

    return 0;
}
