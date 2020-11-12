#include <iostream>

///float nu este tip intreg
///template <float d=832.> class B {/*....*/};  ///Eroare

template<int n=70,char c='L'> class A{     ///Corect
   public:
     void Scrie()
      {
          std::cout<<n<<" "<<c<<'\n';
      }
};

int main()
{
    A<200,'W'> a1;  ///Corect n==200, c=='W'
    a1.Scrie();

    A<200> a2;      ///Corect n==200, c=='L'
    a2.Scrie();

    A<> a3;         ///Corect n==70 c=='L'
    a3.Scrie();

    int d;
    std::cin>>d;
    ///A<d> a4;    ///Eroare. d este non-const, deci nu poate
                         ///fi utilizat ca argument template
    return 0;
}
