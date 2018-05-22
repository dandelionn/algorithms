#include <iostream>
#include <string>
using namespace std;

ifstream f("scmax.in");
ofstream g("scmax.out");



void update(int x,int i)
{
    if(x>v[i])
        {swap(x,v[i]);
        if(v[i*2]==0)
            v[i*2]=x;
        else
           if(v[i*2+1]==0)
              v[i*2+1]=x;
           else
             if(v[i*2]<v[i*2+1])
                update(x,i*2);
             else
                update(x,i*2+1);}
}


int main()
