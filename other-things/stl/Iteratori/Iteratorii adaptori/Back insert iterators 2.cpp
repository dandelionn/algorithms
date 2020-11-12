#include <iterator>
#include <vector>
#include <iostream>
using namespace std;

int main()
{
    int a[]={1,2,3};
    vector<int> V;
    vector<int>::iterator it;

    ///Insereaza la sfarsit 1 2 3,prin apelul constructorului
    copy(a,a+3,back_insert_iterator<vector<int> >(V));

    ///Insereaza la sfarsit 1 2 3,cu functia back_inserter()
    copy(a,a+3,back_inserter(V));

    for(it=V.begin(); it!=V.end();++it)
        cout<<*it<<' ';

    return 0;
}
