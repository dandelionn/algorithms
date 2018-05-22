#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct F{
    int n;                ///Retine starea obiectului *this
    void operator()(int x)
    {n++; cout<<x<<" ";}

};

int main()
{
    vector<int> v; int x;
    while(cin>>x)
        v.push_back(x);
    F ob=for_each(v.begin(),v.end(),F());

    cout<<"\n"<<ob.n;   ///ob-functorul returnat

    return 0;
}
