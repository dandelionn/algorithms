#include <iostream>
#include <windows.h>
using namespace std;
int main()
{
    HANDLE hConsole;
    hConsole = GetStdHandle (STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole,74);
    cout << "Bright red text\n";
    int i,j,nr=0;
    char a=219;
    char b=219;
    char c=219;
    SetConsoleTextAttribute
    	    (hConsole, FOREGROUND_BLUE+FOREGROUND_GREEN+FOREGROUND_RED| FOREGROUND_INTENSITY);
	            cout << "Bright red text\n";
     SetConsoleTextAttribute
        (hConsole, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
                    cout << "Bright blue text\n";
    SetConsoleTextAttribute
        (hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    cout<<"\n\n\n";
    cout<<"   "<<b;
    for(i=1;i<72;i++)
        cout<<a;
    cout<<b<<'\n';
    for(j=0;j<=47;j++)
        {SetConsoleTextAttribute
            (hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
        cout<<"   "<<b;
        if(j%6==0&&j!=0)
           {for(i=1;i<=72;i++)
              cout<<a;
           cout<<'\n';
           cout<<"   "<<b;
           if(nr==0)
              nr=1;
           else
              nr=0;}
        for(i=1;i<=72;i++)
            if(i%9==0)
                {SetConsoleTextAttribute
    	              (hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
                 cout<<b;
                 if(nr==0)
                    nr=1;
                 else
                    nr=0;}
            else
                 if(nr==1)
                    {SetConsoleTextAttribute
                        (hConsole, FOREGROUND_BLUE+FOREGROUND_GREEN+FOREGROUND_RED | FOREGROUND_INTENSITY);
                    cout<<c;}
                 else
                    {SetConsoleTextAttribute
                        (hConsole, FOREGROUND_BLUE+FOREGROUND_GREEN| FOREGROUND_INTENSITY);
                    cout<<c;}
        cout<<'\n';}
    cout<<"   "<<b;
    for(i=1;i<72;i++)
        cout<<a;
    cout<<b<<'\n';
    cout<<"\n\n";
    Sleep(8000);
}
