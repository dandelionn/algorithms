#include <graphics.h>
#include <iostream>
using namespace std;
int main()
{
    int gdriver = DETECT, gmode;
    initgraph(&gdriver, &gmode, "");
    if (graphresult())
    {
        cout<<"Tentativa nereusita ...";
    }
    else
    {
        cout<<"Totul functioneaza corect, afisez!";
        setcolor(RED);
        moveto(0,0);
        lineto(getmaxx(),getmaxy());
    }
    cout<<endl<<"Apasa o tasta pentru a inchide...";
    getch();
    return 0;
}
