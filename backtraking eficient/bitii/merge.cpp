#include <fstream>
#include <vector>

using namespace std;
ifstream f("submultimi.in");
ofstream g("submultimi.out");

bool isSet (size_t pos, long long n )
{
    long long mask;
    mask = 1 << (pos - 1);

    return (n & mask) != 0;
}

void sets ( vector<int> &v )
{
        for (unsigned long long count = 0; count <= (1 << v.size() - 1 ) - 1; count ++)
        {
                for (size_t i = 1; i < v.size(); i++)
                    if (isSet (i, count))
                        g<< v[i] << ' ';

                g<< endl;
        }


}

int main()
{
    int n;
    f>>n;

    vector <int> v;
    v.push_back(0);
    for(int i=1;i<=n;i++)
        v.push_back(i);


    sets( v );







    return 0;
}
