#include <iostream>
#include <string>
using namespace std;

template <typename T,int DIM>
class Stiva{
    T st[DIM];  ///data membru template
    int varf;     ///data membru non-template
  public:
    Stiva():varf(0){}  ///Constructorul clasei
    void Pune(T val)
    {st[varf++]=val;}
    T scoate()
    {return st[--varf];}
    void afiseaza() const
    {
        for(int i=varf-1;i>=0;i--)
            cout<<st[i]<<" ";
        cout<<"\n";
    }
};
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
