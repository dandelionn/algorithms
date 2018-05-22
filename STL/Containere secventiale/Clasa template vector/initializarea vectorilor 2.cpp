#include <iostream>

using namespace std;

int a[3]={-3,14,-4};
//vector<int> v(3) ={5,67,8};  ///Ilegal


int main()
{
    int x=int(); ///Echivalent cu int x=0
    cout<<x;
    cout<<int(); ///Creeaza in stiva o variabila temporara,
                ///anonima, de tip int, initializata cu 0.
    int* p= new int(7); ///Aloca dinamic o variabila de tip int, initializata cu valoarea 7.
    cout<<*p;
}
