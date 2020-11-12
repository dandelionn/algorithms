#include <iostream>
#include <iterator>
#include <vector>
using namespace std;

int main()
{
    int a[]={1, 2, 3};
    vector<int> V;
    vector<int>::iterator i;

    ///Constructorul creeaza un general insert iterator, it
    insert_iterator<vector<int> > it(V, V.end());

    *it=10;   ///Insereaza 10 inainte de sfarsit
    it=20;    ///Acelasi efect

    ///inserter() insereaza 1,2,3, dupa al doilea element
    copy(a, a+3, inserter(V,V.begin()+1));

    for(i=V.begin();i!=V.end();++i)
        cout<<*i<<' ';
}
