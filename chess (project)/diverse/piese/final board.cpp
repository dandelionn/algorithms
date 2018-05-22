#include <iostream>
#include <fstream>
#include <windows.h>
using namespace std;

ifstream f("forgot final.txt");

#define nnewline  cout<<"\n\n\n\n\n"
#define space cout<<"          "

int i,j,indicator=-1;
char a[100][100];




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

void board()
{
    HANDLE hConsole;
    hConsole = GetStdHandle (STD_OUTPUT_HANDLE);
    system("color 20"); //20 //90  //30 //60
    nnewline;
    space;
    for(i=0;i<=65;i++)
       {for(j=0;j<=97;j++)
           if(a[i][j]=='0')
                {if(indicator!=0)
                      {SetConsoleTextAttribute(hConsole,255);
                      indicator=0;}
                cout<<(char) 219;}
           else
              if(a[i][j]=='1')
                  {if(indicator!=1)
                      {SetConsoleTextAttribute(hConsole,0);
                      indicator=1;}
                  cout<<(char) 219;}
              else
                 if(a[i][j]=='2')
                     {if(indicator!=2)
                         {SetConsoleTextAttribute(hConsole,247);  //234
                         indicator=2;}
                     cout<<(char) 219;}
                 else
                    if(a[i][j]=='3')
                         {if(indicator!=3)
                             {SetConsoleTextAttribute(hConsole,244);  //247
                             indicator=3;}
                         cout<<(char) 219;}
                    else
                         {if(indicator!=9)
                             {SetConsoleTextAttribute(hConsole,62);  //154  //30 //28 //25 //23 //22 //42 //62
                             indicator=9;}
                         if(a[i][j]=='9')
                            cout<<(char) 219;
                         else
                            if(a[i][j]<'Z')
                                cout<<a[i][j];
                            else
                                cout<<a[i][j]-'a';}
        cout<<'\n';SetConsoleTextAttribute(hConsole,43);space;;indicator=111;}
}

void move(int x1,int y1,int x2,int y2)
{
    int i,j;
    char m1,m2;
    m1=a[x1+1][y1+1];
    m2=a[x2+1][y2+1];
    if(m1==m2)
       for(i=1;i<=8;i++)
          for(j=1;j<=12;j++)
             {a[x2+i][y2+j]=a[x1+i][y1+j];
             if(a[x1+i][y1+j]-'0'>1)
                 a[x1+i][y1+j]=m1;}
   else
       for(i=1;i<=8;i++)
           for(j=1;j<=12;j++)
               {if(a[x2+i][y2+j]-'0'>1)
                   a[x2+i][y2+j]=m2;
               if(a[x1+i][y1+j]-'0'>1)
                   a[x2+i][y2+j]=a[x1+i][y1+j];
               a[x1+i][y1+j]=m1;}
}

int main()
{
    SetWindow(160,160);




    for(i=0;i<=65;i++)
       for(j=0;j<=97;j++)
           f>>a[i][j];


    board();
    Sleep( 2000 );
    char c[5];

    while(1<2)
    {    cin>>c;
         if(c[1]<'a')
             c[1]+=32;
         cout<<c[1];
         if(c[3]<'a')
             c[3]+=32;
         cout<<c[3];
         move((c[0]-'1')*8,(c[1]-'a')*12,(c[2]-'1')*8,(c[3]-'a')*12);
         board();
    }
    system("CLS");
    //board();
    Sleep( 2000 );
    getchar();
}
