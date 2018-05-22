#include <fstream>
#include <iostream>
using namespace std;
ifstream f("medii.txt");
void cifra(float x,int &y)
{
    y=((int) x)%10;
}
int main()
{
    float n;
    int nr=0,y,x;
    while(!f.eof())
         {f>>n;
         cifra(n,y);
         f>>n;
         cifra(n,x);
         if(y==x-1)
           nr++;}
    cout<<nr;
    f.close();
}
