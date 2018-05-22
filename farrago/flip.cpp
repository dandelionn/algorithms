#include <iostream>
using namespace std;
int b[16],p;
int back(int n)
{

int i=1,a[20];
void afisare()
{int j=1;
    while(j<=i)
       {b[j]=a[j];
       j++;}
    b[j+1]=0;
    p=b;
    return p;
    cout<<'\n';
}
int main()
{
    while(i>0)
         {
             a[i]++;
             afisare();
             i++;
             if(i==3)
                   while(a[i]!=3)
                        {
                            a[i]++;
                            afisare();
                        }
             while(a[i]==3)
                  {
                      a[i]=0;
                      i--;
                  }
         }
}

}
int i=1,a[20];
void afisare()
{int j=1;
    while(j<=i)
       {cout<<a[j];
       j++;}
    cout<<'\n';
}
int main()
{
    while(i>0)
         {
             a[i]++;
             afisare();
             i++;
             if(i==3)
                   while(a[i]!=3)
                        {
                            a[i]++;
                            afisare();
                        }
             while(a[i]==3)
                  {
                      a[i]=0;
                      i--;
                  }
         }
}
