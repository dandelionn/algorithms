#include <iostream>
#include <iterator>
#include <vector>
#include <set>
#include <typeinfo>
using namespace std;

template <typename Iter>
Iter Avanseaza(Iter it,int n)
{
    if(typeid(typename
       iterator_traits<Iter>::iterator_category)
       ==typeid(random_access_iterator_tag))

       return it+=n;
    else
    {
        while(--n) ++it;
        return it;
    }
}

int main()
{
    int a[]={34, 54, 34, 75, 12};
    vector<int> v(a,a+5);

    cout<<*Avanseaza(v.begin(),3);  ///Compileaza fara probleme

    set<int> s(a,a+5);
    cout<<*Avanseaza(s.begin(),3);   ///Eroare !!

    return 0;
}
