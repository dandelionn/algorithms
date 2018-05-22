#include <iostream>
using namespace std;
struct nod{int x,y;};
int *a,*b,*c,*p,*q,*r,*n,*aux;
nod *t;
int main()
{
    a=new int;b=new int;c=new int;aux=new int;n=new int;
    cout<<"n= ";cin>>*n;
    p=new int[*n];
    t=new nod;
    cout<<"a= ";cin>>*a;
    cout<<"b= ";cin>>*b;
    cout<<"c= ";cin>>*c;
    cout<<"media aritmetica= "<<(*a+*b+*c)/3<<'\n';
    cout<<"elementele sirului sunt: "<<'\n';
    for(q=p;q<p+*n;q++)
       cin>>*q;
    for(q=p,r=p+*n-1;q<r;q++,r--)
        {
            *aux=*r;
            *r=*q;
            *q=*aux;
        }
    cout<<"sirul inversat:";
    for(q=p;q<p+*n;q++)
       cout<<*q<<' ';
    cout<<'\n'<<"elementele nodului: ";
    cout<<"t->x= ";cin>>t->x;
    cout<<"t->y= ";cin>>t->y;
    cout<<t->x<<' '<<t->y<<'\n';
    delete a;delete []p;delete b;delete c;delete t;delete aux;
}
