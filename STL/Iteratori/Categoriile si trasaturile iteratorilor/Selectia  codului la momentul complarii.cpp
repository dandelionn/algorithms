///Selectia codului la momentul compilarii cu _iterator_tag-uri
#include <iostream>
#include <vector>
#include <list>
#include <iterator>
using namespace std;

template<typename Iter>
Iter Avans(Iter it,int n, random_access_iterator_tag)
{
    return it+=n;
}

template <typename Iter>
Iter Avans(Iter it,int n, bidirectional_iterator_tag)
{
    if(n>0)
    {
        while(n--) ++it;
           return it;
    }
    else
    {
        while(n++) --it;
           return it;
    }
}

template<typename Iter>
Iter Avanseaza(Iter it,int n)
{
    return Avans(it,n,
                 typename iterator_traits<Iter>::iterator_category());
}

int main()
{
    int a[]={34, 34, 67, 45 ,67};
    vector<int> V(a,a+5);
    list<int> L(a,a+5);
    cout<<*Avanseaza(V.begin(),3)<<'\n';
    cout<<*Avanseaza(L.begin(),4);

    return 0;
}
