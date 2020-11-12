#include <iostream>
#include <windows.h>
#include <stdio.h>
using namespace std;

int main()
{
    HANDLE hConsole;
    hConsole = GetStdHandle (STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute
        (hConsole,FOREGROUND_GREEN+FOREGROUND_BLUE| FOREGROUND_INTENSITY);
	            cout << "Bright red text\n";
	char g=177;
    char a=186;
    char b=201;
    char c=205;
    char d=187;
    char e=200;
    char f=188;
    char s=219;
    int i,j;
    cout<<b;
    for(i=1;i<=30;i++)
       cout<<c;
    cout<<d<<'\n';
    for(i=1;i<=30;i++)
       {cout<<a;
       for(j=1;j<=30;j++)
          cout<<s;
       cout<<a<<'\n';}
    cout<<e;
    for(i=1;i<=30;i++)
       cout<<c;
    cout<<f<<'\n';
    cout<<c<<e<<f<<'\n';

    char a0=30;

    system("color 09");
    system("color 18");

    SetConsoleTextAttribute
                        (hConsole, FOREGROUND_BLUE+FOREGROUND_GREEN| FOREGROUND_INTENSITY);

    cout<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<'\n';
    cout<<s<<s<<s<<a<<a<<c<<c<<a<<a<<s<<s<<s<<'\n';
    cout<<s<<s<<s<<s<<b<<a<<a<<d<<s<<s<<s<<s<<'\n';
    cout<<s<<s<<s<<s<<b<<a<<a<<d<<s<<s<<s<<s<<'\n';
    cout<<s<<s<<s<<s<<b<<a<<a<<d<<s<<s<<s<<s<<'\n';
    cout<<s<<s<<s<<s<<b<<a<<a<<d<<s<<s<<s<<s<<'\n';
    cout<<s<<s<<s<<a<<a<<c<<c<<a<<a<<s<<s<<s<<'\n';
    cout<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<'\n';

    SetConsoleTextAttribute
                        (hConsole, FOREGROUND_BLUE+FOREGROUND_GREEN+FOREGROUND_RED | FOREGROUND_INTENSITY);

    cout<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<'\n';
    cout<<s<<s<<s<<a<<a<<c<<c<<a<<a<<s<<s<<s<<'\n';
    cout<<s<<s<<s<<s<<b<<a<<a<<d<<s<<s<<s<<s<<'\n';
    cout<<s<<s<<s<<s<<b<<a<<a<<d<<s<<s<<s<<s<<'\n';
    cout<<s<<s<<s<<s<<b<<a<<a<<d<<s<<s<<s<<s<<'\n';
    cout<<s<<s<<s<<s<<b<<a<<a<<d<<s<<s<<s<<s<<'\n';
    cout<<s<<s<<s<<a<<a<<c<<c<<a<<a<<s<<s<<s<<'\n';
    cout<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<'\n';

    SetConsoleTextAttribute
                        (hConsole, FOREGROUND_BLUE+FOREGROUND_GREEN| FOREGROUND_INTENSITY);

    cout<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<'\n';
    cout<<s<<s<<s<<a<<a<<c<<c<<a<<a<<s<<s<<s<<'\n';
    cout<<s<<s<<s<<s<<b<<a<<a<<d<<s<<s<<s<<s<<'\n';
    cout<<s<<s<<s<<s<<b<<a<<a<<d<<s<<s<<s<<s<<'\n';
    cout<<s<<s<<s<<s<<b<<a<<a<<d<<s<<s<<s<<s<<'\n';
    cout<<s<<s<<s<<s<<b<<a<<a<<d<<s<<s<<s<<s<<'\n';
    cout<<s<<s<<s<<a<<a<<c<<c<<a<<a<<s<<s<<s<<'\n';
    cout<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<'\n';

    SetConsoleTextAttribute
                        (hConsole, FOREGROUND_BLUE+FOREGROUND_GREEN+FOREGROUND_RED | FOREGROUND_INTENSITY);

    cout<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<'\n';
    cout<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<'\n';
    cout<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<'\n';
    cout<<s<<s<<s<<a<<a<<c<<c<<a<<a<<s<<s<<s<<'\n';
    cout<<s<<s<<s<<s<<b<<a<<a<<d<<s<<s<<s<<s<<'\n';
    cout<<s<<s<<s<<s<<b<<a<<a<<d<<s<<s<<s<<s<<'\n';

    cout<<s<<s<<s<<a<<a<<c<<c<<a<<a<<s<<s<<s<<'\n';
    cout<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<'\n';


    cout<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<'\n';
    cout<<s<<s<<s<<g<<g<<g<<g<<g<<g<<s<<s<<s<<'\n';
    cout<<s<<s<<s<<s<<g<<g<<g<<g<<s<<s<<s<<s<<'\n';
    cout<<s<<s<<s<<s<<g<<g<<g<<g<<s<<s<<s<<s<<'\n';
    cout<<s<<s<<s<<s<<g<<g<<g<<g<<s<<s<<s<<s<<'\n';
    cout<<s<<s<<s<<s<<g<<g<<g<<g<<s<<s<<s<<s<<'\n';
    cout<<s<<s<<s<<g<<g<<g<<g<<g<<g<<s<<s<<s<<'\n';
    cout<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<'\n';


    SetConsoleTextAttribute
                        (hConsole, FOREGROUND_BLUE+FOREGROUND_GREEN| FOREGROUND_INTENSITY);

    cout<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<'\n';
    cout<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<'\n';
    cout<<s<<s<<s<<g<<g<<g<<g<<g<<g<<s<<s<<s<<'\n';
    cout<<s<<s<<s<<s<<g<<g<<g<<g<<s<<s<<s<<s<<'\n';
    cout<<s<<s<<s<<s<<g<<g<<g<<g<<s<<s<<s<<s<<'\n';
    cout<<s<<s<<s<<s<<g<<g<<g<<g<<s<<s<<s<<s<<'\n';
    cout<<s<<s<<s<<g<<g<<g<<g<<g<<g<<s<<s<<s<<'\n';
    cout<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<'\n';

    SetConsoleTextAttribute
                        (hConsole, FOREGROUND_BLUE+FOREGROUND_GREEN+FOREGROUND_RED | FOREGROUND_INTENSITY);

    cout<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<'\n';
    cout<<s<<s<<s<<s<<s<<g<<g<<s<<s<<s<<s<<s<<'\n';
    cout<<s<<s<<s<<g<<g<<g<<g<<g<<g<<s<<s<<s<<'\n';
    cout<<s<<s<<s<<s<<g<<g<<g<<g<<s<<s<<s<<s<<'\n';
    cout<<s<<s<<s<<s<<s<<g<<g<<s<<s<<s<<s<<s<<'\n';
    cout<<s<<s<<s<<s<<g<<g<<g<<g<<s<<s<<s<<s<<'\n';
    cout<<s<<s<<s<<g<<g<<g<<g<<g<<g<<s<<s<<s<<'\n';
    cout<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<'\n';

    SetConsoleTextAttribute
                        (hConsole, FOREGROUND_BLUE+FOREGROUND_GREEN+FOREGROUND_RED | FOREGROUND_INTENSITY);
    cout<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<'\n';
    cout<<s<<s<<s<<s<<s<<g<<g<<s<<s<<s<<s<<s<<'\n';
    cout<<s<<s<<s<<s<<g<<g<<g<<g<<s<<s<<s<<s<<'\n';
    cout<<s<<s<<s<<s<<g<<g<<g<<g<<s<<s<<s<<s<<'\n';
    cout<<s<<s<<s<<s<<g<<g<<g<<g<<s<<s<<s<<s<<'\n';
    cout<<s<<s<<s<<g<<g<<g<<g<<g<<g<<s<<s<<s<<'\n';
    cout<<s<<s<<s<<g<<g<<g<<g<<g<<g<<s<<s<<s<<'\n';
    cout<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<'\n';

    SetConsoleTextAttribute
                        (hConsole, FOREGROUND_BLUE+FOREGROUND_GREEN| FOREGROUND_INTENSITY);

    cout<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<'\n';
    cout<<s<<s<<a0<<a0<<a0<<a0<<a0<<a0<<a0<<a0<<s<<s<<'\n';
    cout<<s<<s<<s<<g<<g<<g<<g<<g<<g<<s<<s<<s<<'\n';
    cout<<s<<s<<s<<s<<g<<g<<g<<g<<s<<s<<s<<s<<'\n';
    cout<<s<<s<<s<<s<<s<<g<<g<<s<<s<<s<<s<<s<<'\n';
    cout<<s<<s<<s<<s<<g<<g<<g<<g<<s<<s<<s<<s<<'\n';
    cout<<s<<s<<s<<g<<g<<g<<g<<g<<g<<s<<s<<s<<'\n';
    cout<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<'\n';

     SetConsoleTextAttribute
                        (hConsole, FOREGROUND_BLUE+FOREGROUND_GREEN+FOREGROUND_RED | FOREGROUND_INTENSITY);
    char a191=191;
    char a218=218;
    char a222=222;
    char a221=221;
    cout<<a0<<'\n';
    cout<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<'\n';
    cout<<s<<s<<s<<s<<s<<a222<<a221<<s<<s<<s<<s<<s<<'\n';
    cout<<s<<s<<s<<s<<s<<a218<<a191<<s<<s<<s<<s<<s<<'\n';
    cout<<s<<s<<s<<s<<a0<<g<<g<<a0<<s<<s<<s<<s<<'\n';
    cout<<s<<s<<s<<a0<<g<<g<<g<<g<<a0<<s<<s<<s<<'\n';
    cout<<s<<s<<a0<<g<<g<<g<<g<<g<<g<<a0<<s<<s<<'\n';

    cout<<s<<s<<s<<s<<g<<g<<g<<g<<s<<s<<s<<s<<'\n';
    cout<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<'\n';

    SetConsoleTextAttribute
                        (hConsole, FOREGROUND_BLUE+FOREGROUND_GREEN| FOREGROUND_INTENSITY);

    cout<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<'\n';
    cout<<s<<s<<g<<g<<s<<g<<g<<s<<g<<g<<s<<s<<'\n';
    cout<<s<<s<<s<<g<<g<<g<<g<<g<<g<<s<<s<<s<<'\n';
    cout<<s<<s<<s<<s<<g<<g<<g<<g<<s<<s<<s<<s<<'\n';
    cout<<s<<s<<s<<s<<s<<g<<g<<s<<s<<s<<s<<s<<'\n';
    cout<<s<<s<<s<<s<<g<<g<<g<<g<<s<<s<<s<<s<<'\n';
    cout<<s<<s<<s<<g<<g<<g<<g<<g<<g<<s<<s<<s<<'\n';
    cout<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<'\n';

    SetConsoleTextAttribute
                        (hConsole, FOREGROUND_BLUE+FOREGROUND_GREEN+FOREGROUND_RED | FOREGROUND_INTENSITY);

    cout<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<'\n';
    cout<<s<<s<<s<<s<<s<<g<<g<<s<<s<<s<<s<<s<<'\n';
    cout<<s<<s<<s<<g<<g<<g<<g<<g<<g<<s<<s<<s<<'\n';
    cout<<s<<s<<s<<s<<g<<g<<g<<g<<s<<s<<s<<s<<'\n';
    cout<<s<<s<<s<<s<<s<<g<<g<<s<<s<<s<<s<<s<<'\n';
    cout<<s<<s<<s<<s<<g<<g<<g<<g<<s<<s<<s<<s<<'\n';
    cout<<s<<s<<s<<g<<g<<g<<g<<g<<g<<s<<s<<s<<'\n';
    cout<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<'\n';

    SetConsoleTextAttribute
                        (hConsole, FOREGROUND_BLUE+FOREGROUND_GREEN| FOREGROUND_INTENSITY);

    cout<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<'\n';
    cout<<s<<s<<s<<g<<s<<g<<s<<s<<s<<s<<s<<s<<'\n';
    cout<<s<<s<<s<<g<<g<<g<<g<<g<<g<<s<<s<<s<<'\n';
    cout<<s<<s<<s<<s<<g<<g<<g<<g<<g<<s<<s<<s<<'\n';
    cout<<s<<s<<s<<s<<g<<g<<s<<s<<s<<s<<s<<s<<'\n';
    cout<<s<<s<<s<<g<<g<<g<<g<<g<<s<<s<<s<<s<<'\n';
    cout<<s<<s<<g<<g<<g<<g<<g<<g<<g<<s<<s<<s<<'\n';
    cout<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<'\n';

    SetConsoleTextAttribute
                        (hConsole, FOREGROUND_BLUE+FOREGROUND_GREEN+FOREGROUND_RED | FOREGROUND_INTENSITY);

    cout<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<'\n';
    cout<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<'\n';
    cout<<s<<s<<s<<s<<s<<g<<g<<s<<s<<s<<s<<s<<'\n';
    cout<<s<<s<<s<<s<<g<<g<<g<<g<<s<<s<<s<<s<<'\n';
    cout<<s<<s<<s<<s<<g<<g<<g<<g<<s<<s<<s<<s<<'\n';
    cout<<s<<s<<s<<s<<g<<g<<g<<g<<s<<s<<s<<s<<'\n';
    cout<<s<<s<<s<<s<<g<<g<<g<<g<<s<<s<<s<<s<<'\n';
    cout<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<'\n';

    getchar();
}
