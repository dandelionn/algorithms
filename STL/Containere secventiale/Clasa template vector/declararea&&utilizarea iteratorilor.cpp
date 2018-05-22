#include <iostream>
#include <vector>
using  namespace std;

int main()
{
    vector<int>::iterator it1; ///it1 este iterator pentru elementele
                               ///de tip int,ale containerului
    vector<int>::const_iterator it2; ///it2 este un iterator constant

    vector<float> v(10); ///vector cu 10 elemente
    vector<float>::const_iterator it;
    for(it=v.begin();it!=v.end();++it)
        {
            cout<<*it<<' ';
            ///*it=10;      ///Ilegal
        }
    return 0;
}
