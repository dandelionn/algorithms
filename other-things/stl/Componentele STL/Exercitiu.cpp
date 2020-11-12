#include <iostream>
#include <algorithm>
using namespace std;
typedef const char* sir;
struct elev{sir nume;int varsta;};

class Criteriu{
    public:
    bool operator() (elev e1,elev e2) const
    {
        return e1.varsta<e2.varsta;
    }
};

int main()
{
    elev e[]={{"Vasile",45},{"Uneregiads",5},{"Ydse",7}};

    sort(e,e+3,Criteriu());

    for(int i=0;i<3;i++)
        cout<<e[i].nume<<' '<<e[i].varsta<<'\n';
    return 0;
}
