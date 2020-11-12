#include <iostream>
#include <vector>
using namespace std;

int main()
{
    //1_Dezavantajele sunt multiple:construirea si distrugerea de obiecte temporare
    //si realocari ale vectorilor.
    vector<int> v;               ///Auxiliar - vector vid
    vector<vector<int> > m;      ///Vector de vectori vid
    ///Se creeaza in v pe rand,fiecare linie
    int k;
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            cin>>k;
            v.push_back(k);  ///Adauga un element la linie
        }
    m.push_back(v);     ///Adauga linia la matrice
    v.clear();      ///Sterge toate elementele din v
    }
    //2__________________________________________________________
    cin>>m>>n;
    vector<vector<int> > v(m,n);   //  <=> vector<vector<int> > v(m,vector<int>(n))
    for(int i=0;i<m;i++)
       for(int j=0;j<n;j++)
           cin>>v[i][j];
    //3_memorarea matricei de adiacenta prin folosirea unui vector de vector de bool
    cin>>n;
    vector<vector<bool> > a(n,n); //   <=>vector<vector<float> > a(n,vector<bool>(n));

    //4_tablou tridimensional
    cin>>m>>n>>k;
    vector<vector<vector<float> > > v(m,vector<vector<float> > (n,vector<float>(k)) );

    //5_matrice
    vector<vector<int> > v;
    cin>>m>>>n;
    v.resize(m);        ///m-linii
    for(int i=0;i<n;i++)
        v[i].resize(n);   ///Fiecare linie are n elemente

}
