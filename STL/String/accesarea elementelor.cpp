#include <iostream>
#include <string>
#include <exception>
using namespace std;

int main()
{
    string s("the Town");
    for(int i=0;i<s.length();i++)
       cout<<s[i];
    cout<<'\n';
    for(int i=0;i<s.size();i++)
       cout<<s.at(i);
    cout<<'\n';
    s[0]='T';
    s[4]='t';
    ///s[11]='E';  Comportament nedefinit
    try{
        s.at(11)='E';  ///Arunca exceptia out_of_range
    }catch(exception e){
           cout<<"Exceptie!";
    }
    cout<<s[11]<<' '<<s.at(11);
    return 0;
}
