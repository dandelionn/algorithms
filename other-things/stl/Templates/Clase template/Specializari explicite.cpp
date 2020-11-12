#include <iostream>
using namespace std;
template <typename T> class A{/*corpul sablonului*/};   ///Sablon primar

///Specializare explicita cu numele A<int> pentru T==int
template<> class A<int>{
    ///corpul specializarii
};

///Specializare explicita pentru T==char
template<> class A<char>{
    ///Corpul specializarii
};

template <class T> class Sir{     ///Sablonul general
     T t[100];
     int n;
  public:
     void citeste()
     {
         cin>>n;
         for(int i=0;i<n;i++)
            cin>>t[i];
     }
     void afiseaza() const
     {
         for(int i=0;i<n;i++)
             cout<<t[i]<<' ';
     }
};

template<> class Sir<char>{     ///Specializare
    char t[100];                ///Alte date membre
  public:
    void citeste() const   ///Alte implementari pentru
    {                      ///functiile membre
        cin>>(char*) t;
    }
    void afiseaza() const
    {
        cout<<t;
    }
};

int main()
{
    Sir<int> s1; ///Instantiere din sablonul general
    s1.citeste();
    s1.afiseaza();

    Sir<char> s2;  ///Se utilizeaza definitia specializarii
    s2.citeste();
    s2.afiseaza();

    return 0;
}
