#include <iostream>
using namespace std;

template <typename T,int DIM>
class Stiva{
    T st[DIM];      ///Data membru template
    int varf;       ///Data membru non-template
  public:            ///Declaratiile functiilor membre
    Stiva();
    void Pune(T val);
    T scoate();
    void afiseaza() const;
};

///Definitiile sunt prefixate cu  headerul template

template <typename T,int DIM>
Stiva<T,DIM>::Stiva():varf(0){} ///Constructorul clasei

template<typename T,int DIM>
void Stiva<T,DIM>::Pune(T val)
{
    st[varf++] = val;
}

template <typename T,int DIM>
T Stiva<T,DIM>::scoate()
{
    return st[--varf];
}

template<typename T,int DIM>
void Stiva<T,DIM>::afiseaza() const
{
    for(int i=varf-1;i>=0;i--)
       cout<<st[i]<<" ";
    cout<<'\n';
}
int main()
{
    Stiva<string,100> S1;   ///Stiva de stringuri

    S1.Pune("UNU");S1.Pune("DOI");S1.Pune("TREI");
    S1.afiseaza();    ///Scrie: TREI DOI UNU

    cout<<S1.scoate();     ///Scrie: TREI
    cout<<S1.scoate();     ///Scrie: DOI
    S1.afiseaza();         ///Scrie: UNU

    Stiva<int, 1000> S2;     ///Stiva de numere intregi
    ///...
    return 0;
}
