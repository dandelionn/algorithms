#include <vector>
#include <iostream>
using namespace std;

int main()
{
    vector<int> v(100);
    cout<<v.size()<<' '<<v.capacity()<<'\n';

    /**clear(),resize(),reserve(), destructorul ~vector<int>()
    nu reduc capacitatea containerului v */

    v.clear();
    cout<<v.size()<<' '<<v.capacity()<<'\n';
    v.resize(0);
    cout<<v.size()<<' '<<v.capacity()<<'\n';
    v.reserve(0);
    cout<<v.size()<<' '<<v.capacity()<<'\n';
    v.~vector<int>();
    cout<<v.size()<<' '<<v.capacity()<<'\n';

    ///Idiom-ul "swap trick"
    vector<int>().swap(v);
    cout<<v.size()<<' '<<v.capacity()<<'\n';

    v.reserve(100);      ///marim capacitatea la 100
    v.resize(45);        ///45 elemente
    cout<<v.size()<<' '<<v.capacity()<<'\n';

    ///Idiom-ul "shrink to fit"
    vector<int>(v).swap(v);
    cout<<v.size()<<' '<<v.capacity()<<'\n';

    return 0;
}
