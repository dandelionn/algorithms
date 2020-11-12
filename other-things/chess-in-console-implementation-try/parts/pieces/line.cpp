#include <iostream>
#include <fstream>
#include <windows.h>
using namespace std;

ifstream f("piese.in");
ofstream g("board.in");

int a[200][200],i,j=1,y=8,z=12;

int main()
{
    system("color 16");
    HANDLE hConsole;
    hConsole = GetStdHandle (STD_OUTPUT_HANDLE);
    while(!f.eof())
         {
             for(i=1;i<=y;i++)
                for(j=z-11;j<=z;j++)
                    f>>a[i][j];
             z+=12;
         }
    f.close();
    int nr=1;
    for(i=1;i<=8;i++)
       {for(j=1;j<=79;j++)
           if(a[i][j])
               {SetConsoleTextAttribute
                      (hConsole,0);
               cout<<(char) 219;}
           else
               if(nr==1)
                  {SetConsoleTextAttribute
                        (hConsole, FOREGROUND_BLUE+FOREGROUND_GREEN| FOREGROUND_INTENSITY);
                  cout<<(char) 219;
                  if(j%12==0)
                     nr=0;}
               else
                  {SetConsoleTextAttribute
    	    (hConsole, 127);
                  cout<<(char) 219;
                  if(j%12==0)
                     nr=1;}
       cout<<'\n';}
    nr=0;
    for(i=1;i<=8;i++)
       {for(j=1;j<=79;j++)
           if(a[i][j])
               {SetConsoleTextAttribute
                      (hConsole,247);
               cout<<(char) 219;}
           else
               if(nr==1)
                  {SetConsoleTextAttribute
                        (hConsole, FOREGROUND_BLUE+FOREGROUND_GREEN| FOREGROUND_INTENSITY);
                  cout<<(char) 219;
                  if(j%12==0)
                     nr=0;}
               else
                  {SetConsoleTextAttribute
    	    (hConsole, 127);
                  cout<<(char) 219;
                  if(j%12==0)
                     nr=1;}
       cout<<'\n';}
    nr=1;
    cout<<'\n';
    for(i=1;i<=8;i++)
       {for(j=1;j<=79;j++)
           if(a[i][j])
               {SetConsoleTextAttribute
                      (hConsole,FOREGROUND_BLUE| FOREGROUND_INTENSITY);
               cout<<(char) 219;}
           else
               if(nr==1)
                  {SetConsoleTextAttribute
                        (hConsole, FOREGROUND_BLUE+FOREGROUND_GREEN| FOREGROUND_INTENSITY);
                  cout<<(char) 219;
                  if(j%12==0)
                     nr=0;}
               else
                  {SetConsoleTextAttribute
    	    (hConsole, 127);
                  cout<<(char) 219;
                  if(j%12==0)
                     nr=1;}
       cout<<'\n';}
     nr=0;
    for(i=1;i<=8;i++)
       {for(j=1;j<=79;j++)
           if(a[i][j])
               {SetConsoleTextAttribute
                      (hConsole,194);
               cout<<(char) 219;}
           else
               if(nr==1)
                  {SetConsoleTextAttribute
                        (hConsole, FOREGROUND_BLUE+FOREGROUND_GREEN| FOREGROUND_INTENSITY);
                  cout<<(char) 219;
                  if(j%12==0)
                     nr=0;}
               else
                  {SetConsoleTextAttribute
    	    (hConsole, 127);
                  cout<<(char) 219;
                  if(j%12==0)
                     nr=1;}
       cout<<'\n';}
       for(i=1;i<=8;i++)
          {for(j=1;j<=60;j++)
              g<<a[i][j]<<' ';
           for(j=25;j<=36;j++)
              g<<a[i][j]<<' ';
           for(j=13;j<=24;j++)
              g<<a[i][j]<<' ';
           for(j=1;j<=12;j++)
              g<<a[i][j]<<' ';
           g<<'\n';
          }
       for(i=1;i<=8;i++)
          {for(j=1;j<=8;j++)
              for(int d=61;d<=72;d++)
                   g<<a[i][d]<<' ';
          g<<'\n';}
       for(i=1;i<=32;i++)
          {for(j=1;j<=96;j++)
               g<<'0'<<' ';
          g<<'\n';}
       for(i=1;i<=8;i++)
          {for(j=1;j<=8;j++)
              for(int d=61;d<=72;d++)
                   g<<a[i][d]<<' ';
          g<<'\n';}
       for(i=1;i<=8;i++)
          {for(j=1;j<=36;j++)
              g<<a[i][j]<<' ';
           for(j=49;j<=60;j++)
              g<<a[i][j]<<' ';
           for(j=37;j<=48;j++)
              g<<a[i][j]<<' ';
           for(j=25;j<=36;j++)
              g<<a[i][j]<<' ';
           for(j=13;j<=24;j++)
              g<<a[i][j]<<' ';
           for(j=1;j<=12;j++)
              g<<a[i][j]<<' ';
           g<<'\n';
          }
    getchar();

}
