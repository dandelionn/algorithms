#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;

struct Om{
    int varsta;
    char sex;
    void Scrie() const
    {cout<<varsta<<' '<<sex<<'\n';}
    void ScrieVarsta(char s) const
    {if (sex==s) cout<<varsta<<' ';}
};

int main()
{
    Om om[]={{18,'F'},{21,'M'},{16,'F'}};
    ///Apeleaza Om::Scrie() pentru fiecare obiect Om
    for_each(om,om+3,mem_fun_ref(&Om::Scrie));

    ///Apeleaza Om::ScrieVarsta() pentru fiecare fata
    for_each(om,om+3,bind2nd(mem_fun_ref(&Om::ScrieVarsta),'F'));

    return 0;
}
