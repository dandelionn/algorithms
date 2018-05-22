#include <iostream>

using namespace std;

int p[100],k;

int main()
{
    k=4;
    p[k]=2;
    switch(p[k])
       {
           case 1: if(k & 1)
                  {cout<<'1'<<' ';
                  return 1;} break; //spre N;
           case 2: if(k & 2)
                  {cout<<'2'<<' ';
                  return 1;}
                  break; //spre E;
           case 3: if(k & 4)
                  {cout<<'3'<<' ';
                  return 1;}
                  break; //spre S;
           case 4: if(k & 8)
                  {cout<<'4'<<' ';
                  return 1;}        //spre V;
       }
}
