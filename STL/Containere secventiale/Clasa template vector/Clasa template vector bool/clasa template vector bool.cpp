#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<bool> v(3);   ///v= [false,false,false]
    v[0]=~v[1];          ///v= [true,false,false]
    v.flip();            ///v= [flase,true,true]
    vector<bool>::swap(v[0],v[1]);  ///v=[true,false,true]

    vector<bool>::iterator it;
    for(it=v.begin();it!=v.end();++it)
        cout<<(*it? "true":"false");

    return 0;
}
