#include <iostream>
using namespace std;
struct tanar{char nume[40],starea;int varsta;}a[100];
int n,i,v,x,y,conditie,k,cma;
int main()
{
    cout<<"nr. de persoane= ";cin>>n;
    for(i=0;i<n;i++)
        {
            cin.get();
            cin.get(a[i].nume,40);
            cin>>a[i].starea;
            cin>>a[i].varsta;
        }
    cout<<" Introduceti:"<<'\n';
    cout<<" 1 pentru a afisa toate persoanele care au starea sanatatii foarte buna si varsta egala cu o anumita valoare"<<'\n';
    cout<<" 2 pentru a cauta persoana cu varsta cea mai apropiata de o anumita varsta"<<'\n';
    cout<<" 3 pt a afisa toate persoanele cu varste cuprinse intr-un anumit interval specificat avand starea sanatatii foarte buna"<<'\n';
    cout<<" 0 pt a termina executia programului"<<'\n';
    cout<<"tasta= ";cin>>conditie;
    while(conditie==1||conditie==2||conditie==3)
          {if(conditie==1)
             {
                 cin>>v;
                 for(i=0;i<n;i++)
                     if((a[i].starea=='F')&&(a[i].varsta==v))
                        cout<<a[i].nume<<'\n';
             }
          if(conditie==2)
             {
                cin>>v;
                k=0;
                cma=a[0].varsta;
                y=cma-v;
                y=(int) y;
                for(i=1;i<n;i++)
                    {
                        x=a[i].varsta-v;
                        x=(int) x;
                        if(x<y)
                          {
                              k=i;
                              cma=a[i].varsta;
                              y=x;
                          }
                    }
                cout<<a[k].nume<<' '<<a[k].varsta<<' '<<"ani"<<'\n';  //numarul cel mai apropiat de valoarea introdusa
             }
          if(conditie==3)
              {
                  cin>>x; //inceputul intervalului
                  cin>>y; //sfarsitul intervalului
                  for(i=0;i<n;i++)
                     if((a[i].varsta>=x&&a[i].varsta<=y)&&(a[i].starea=='F'))
                       cout<<a[i].nume<<'\n';
              }
          conditie=0;
          cout<<"Introduceti 4 daca doriti sa refolositi programul";
          cin>>x;
          if(x==4)
            {
                cout<<" Introduceti:"<<'\n';
                cout<<" 1 pentru a afisa toate persoanele care au starea sanatatii foarte buna si varsta egala cu "<<'\n';
                cout<<" 2 pentru a cauta persoana cu varsta cea mai apropiata de o anumita varsta"<<'\n';
                cout<<" 3 pt a afisa toate persoanele cu varste cuprinse intr-un anumit interval specificat avand starea sanatatii foarte buna"<<'\n';
                cout<<" 0 pt a termina executia programului"<<'\n';
                cout<<"tasta= ";cin>>conditie;
            }
          }
}
