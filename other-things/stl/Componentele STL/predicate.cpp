#include <iostream>
#include <algorithm>
using namespace std;

struct elev{string nume;int varsta;};

bool maitanar(elev e1,elev e2)   ///Predicat binar
{
    return e1.varsta<e2.varsta;   ///Criteriul de sortare
}

int main()
{
    elev e[]={{"Vasile",34},{"Retuh",43},{"Consrradf",38}};

    sort(e,e+3,maitanar);

    for(int i=0;i<3;i++)
       cout<<e[i].nume<<" "<<e[i].varsta<<'\n';
    return 0;
}
