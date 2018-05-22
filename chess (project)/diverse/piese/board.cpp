#include <iostream>
#include <fstream>
#include <windows.h>
#include <stdio.h>

using namespace std;

ifstream f("board.txt");
ofstream g("resultchar.txt");

int a[100][100];
int i,j,nr=0;


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
    HANDLE hConsole;
    hConsole = GetStdHandle (STD_OUTPUT_HANDLE);

    for(i=1; i<=64; i++)
        for(j=1; j<=96; j++)
            f>>a[i][j];
    for(i=1; i<=64; i++)
    {
        for(j=1; j<=96; j++)
            cout<<a[i][j];
        cout<<'\n';
    }
    f.close();

    cout<<"\n\n\n\n\n";
    SetConsoleTextAttribute(hConsole,145);

    for(i=1; i<=8; i++)
    {
        for(j=1; j<=126; j++)
            cout<<' ';
        cout<<'\n';
    }

    for(i=1; i<=64; i++)
    {
        cout<<"              ";
        cout<<(char) 219;
        for(j=1; j<=96; j++)
            if(a[i][j])
                if(i>32)
                {
                    SetConsoleTextAttribute(hConsole,234);
                    cout<<(char) 219;
                }
                else
                {
                    SetConsoleTextAttribute(hConsole,247);
                    cout<<(char) 219;
                }
            else if(nr==1)
            {
                SetConsoleTextAttribute(hConsole,255);
                cout<<(char) 219;
                if(j%12==0)
                    nr=0;
            }
            else
            {
                SetConsoleTextAttribute(hConsole,0);
                cout<<(char) 219;
                if(j%12==0)
                    nr=1;
            }
        SetConsoleTextAttribute(hConsole,145);
        cout<<(char) 219;
        cout<<"               "<<'\n';
        if(i%16==0)
            nr=0;
        else if(i%8==0)
            nr=1;
    }
    for(i=1; i<=8; i++)
    {
        for(j=1; j<=126; j++)
            cout<<' ';
        cout<<'\n';
    }


    ///result.txt;
    int bo=0;
    int ob=2;
    for(i=1; i<=64; i++)
    {
        for(j=1; j<=96; j++)
        {
            if(a[i][j]==0)
                g<<bo;
            else
                g<<ob;
            if(j%12==0)
            {
                if(bo==0)
                    bo=1;
                else
                    bo=0;
            }
        }
        if(i%8==0)
        {
            if(bo==0)
                bo=1;
            else
                bo=0;
        }
        if(i>32)
            ob=3;
        g<<'\n';
    }


    getchar();
}


