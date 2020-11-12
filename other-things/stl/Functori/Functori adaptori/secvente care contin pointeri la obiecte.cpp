#include <functional>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Om{
    int varsta;
    char sex;
    public:
      Om(int v,char s):varsta(v),sex(s) {}  ///Constructor
      void Scrie() const
      {cout<<varsta<<' '<<sex<<'\n';}
};

int main()
{
    vector<Om*> v;   ///Secventa de pointeri la obiecte
    ///In vector depozitam adresele obiectelor alocate dinamic
    v.push_back(new Om(24,'M'));
    v.push_back(new Om(18,'F'));
    v.push_back(new Om(16,'F'));

    ///Apeleaza functia membra Scrie(),pentru fiecare obiect
    for_each(v.begin(),v.end(),mem_fun(&Om::Scrie));
    vector<Om*>::iterator it, aux;

    ///Atentie!
    ///Trebuie sa eliberati memoria gestionata de pointeri!
    for(it=v.begin();it!=v.end();++it)
    {
        aux=it;   ///it nu se modifica
        delete *aux;
    }

    return 0;
}
