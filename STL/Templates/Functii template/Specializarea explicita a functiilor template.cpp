#include <iostream>
using namespace std;

template<class T>
void F(T)
{
    cout<<"Instantiere din sablonul general\n";
}

template<>    //Specializare explicita pentru T = int
void F(int)
{
    cout<<"Specializare explicita 1\n";
}
template<>    //Specializare explicita pentru T = const char*
void F(const char*)
{
    cout<<"Specializare explicita 2\n";
}
int main()
{
    F(5.7);  //Instantiaza void F(double) din sablonul general
    F(20); //Apeleaza specializarea void F(int)
    F("specializare");  //Apeleaza specializarea void F(const char*)
    return 0;
}
