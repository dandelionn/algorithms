#include <iostream>
#include <map>
#include <string>
using namespace std;

int main()
{
    map<string,int> agenda;
    agenda["Voicu Alin"]=234124;//insereaza in map o pereche(string,int) cu cheia
                               // "Voicu Alin" si valoarea 234124
    agenda["Vladescu Carmen"]=424234;
    agenda["Muresan Flavia"]=345345;

    ///Citeste cateva nume si cauta numerele lor de telefon
    string nume;
    while( getline(cin,nume) )
         if(agenda.find(nume)!=agenda.end())
             cout<<"Telefonul lui "<<nume<<" este "<<agenda[nume]<<'\n';
         else
             cout<<nume<<" nu este in agenda\n";

    return 0;
}
