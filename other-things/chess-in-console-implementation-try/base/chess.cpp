#include <iostream>
#include <windows.h>
#include <stdio.h>

using namespace std;

void board()
{
    system ("color 12");
    HANDLE hConsole;
    hConsole = GetStdHandle (STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole,74);
    cout << "Bright red text\n";
    int nr=0;
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
    int i,j=13/2,j13=13,contor=1; //contor pentru 8
    char a='A';
    cout<<"       ";
    for(i=1;i<=104;i++)
        if(i==j&&contor<=8)
           {cout<<a;
           a=a+1;
           j+=j13;
           if(i%3==0)
              j13--;
           contor++;}
        else
           cout<<' ';
    cout<<'\n';
    contor=3;
    int numar=1;
    a=219;
    for(j=0;j<=63;j++)
        {SetConsoleTextAttribute
            (hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
        if(j==contor)
           {cout<<"      "<<numar;
           numar++;
           contor+=8;}
        else
           cout<<"       ";
        if(j%8==0&&j!=0)
           {
           if(nr==0)
              nr=1;
           else
              nr=0;}
        for(i=1;i<=104;i++)
            if(i%13==0)
                if(nr==0)
                    nr=1;
                 else
                    nr=0;
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
    cout<<"   ";
    cout<<"\n\n";
}
void SetWindow(int Width, int Height)
{
    _COORD coord;
    coord.X = Width;
    coord.Y = Height;

    _SMALL_RECT Rect;
    Rect.Top = 0;
    Rect.Left = 0;
    Rect.Bottom = Height - 1;
    Rect.Right = Width - 1;

    HANDLE Handle = GetStdHandle(STD_OUTPUT_HANDLE);      // Get Handle
    SetConsoleScreenBufferSize(Handle, coord);            // Set Buffer Size
    SetConsoleWindowInfo(Handle, TRUE, &Rect);            // Set Window Size
}
int main()
{
    SetWindow(160,160);
    board();
    getchar();
}

