#include <iostream>
#include <fstream>

using namespace std;
ifstream f("evaluare.in");
ofstream g("evaluare.out");

char a[100001];
int st=0;

int main()
{
        f>>a;
        for(int i=0; a[i] != ')'; i++)
            if(a[i]=='(')
                 {st++;
                 poz=i;}

        cout<<st;
        cout<<a;



}
