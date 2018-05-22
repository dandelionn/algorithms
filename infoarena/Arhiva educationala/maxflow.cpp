#include <iostream>
#include <fstream>
#include <vector>
#include <stack>

using namespace std;

ifstream f("maxflow.in");
ofstream g("maxflow.out");

struct Muchie{int x, y, c;};
struct Nod{Muchie m; int rc, pos, code;};

vector<Nod> v[1001];
stack<Nod> st;
bool active[5001];

int n, m, x, y, c;

int main()
{
    f >> n >> m;

    for(int i=1; i <= m; i++)
    {
        active[i] = 0;

        f >> x >> y >> c;

        Nod nod;

        nod.m.x = x;
        nod.m.y = y;
        nod.m.c = c;
        nod.m.code = i;

        v[x].push_back(nod);
    }

    vector<Nod>::iterator it;

    for(it = v[1].begin(); it!=v[1].end(); ++it)
    {
        (*it).m.c = 0;
        st.push(*it);
    }

    Nod nod;

    nod.m.x = 1;
    nod.m.y = 1;
    nod.m.c = -1;
    nod.m.code = 0;

    st.push(nod);

    while(!st.empty())
    {

    }

    return 0;
}
