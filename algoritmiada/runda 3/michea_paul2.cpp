#include <fstream>
#include <iostream>

using namespace std;

struct element{int x,y;};
element d[9]={{0,0},{-1,2},{1,2},{2,1},{2,-1},{1,-2},{-1,-2},{-2,-1},{-2,1}};

ifstream f("room94.in");
ofstream g("room94.out");

int a[9][9]={0},b[9][9]={0},c[9][9]={0},u[9][9],vizitat[9][9]={0};
int i,j,l1,c1,l2,c2,l3,c3;

void mutariknight(int l,int c,int nrm)
{
    int i;
    if(nrm==0)
       a[l][c]=1000;
    else
       a[l][c]=nrm;
    for(i=1;i<=8;i++)
        if(((l+d[i].x>=0)&&(c+d[i].y>=0)&&(l+d[i].x<=7)&&(c+d[i].y<=7))&&((a[l+d[i].x][c+d[i].y]==0)||(a[l+d[i].x][c+d[i].y]>nrm+1)))
            mutariknight(l+d[i].x,c+d[i].y,nrm+1);
}
void mutaribishop(int l,int c,int nrm)
{
    int i,j,x,y;
    cout<<l<<' '<<c<<'\n';
    cout<<"nrm "<<nrm<<'\n';
    nrm++;
    for(i=0;i<=7;i++)
        {if((l+i<=7&&c+i<=7)&&(b[l+i][c+i]==0||b[l+i][c+i]>nrm))
           b[l+i][c+i]=nrm;
        if((l-i>=0&&c-i>=0)&&(b[l-i][c-i]==0||b[l-i][c-i]>nrm))
           b[l-i][c-i]=nrm;
        if((l-i>=0&&c+i<=7)&&(b[l-i][c+i]==0||b[l-i][c+i]>nrm))
           b[l-i][c+i]=nrm;
        if((l+i<=7&&c-i>=0)&&(b[l+i][c-i]==0||b[l+i][c-i]>nrm))
           b[l+i][c-i]=nrm;}
     nrm++;
     for(i=0;i<=7;i++)
        for(j=0;j<=7;j++)
            if(b[i][j]==0)
               b[i][j]=2;
}
void Queen(int b[][9],int l,int c,int nrm)
{
    int i;
    cout<<l<<' '<<c<<'\n';
    cout<<"nrm "<<nrm<<'\n';
    for(i=0;i<=7;i++)
        {if((l+i<=7&&c+i<=7)&&(b[l+i][c+i]==0||b[l+i][c+i]>nrm))
           b[l+i][c+i]=nrm;
        if((l-i>=0&&c-i>=0)&&(b[l-i][c-i]==0||b[l-i][c-i]>nrm))
           b[l-i][c-i]=nrm;
        if((l-i>=0&&c+i<=7)&&(b[l-i][c+i]==0||b[l-i][c+i]>nrm))
           b[l-i][c+i]=nrm;
        if((l+i<=7&&c-i>=0)&&(b[l+i][c-i]==0||b[l+i][c-i]>nrm))
           b[l+i][c-i]=nrm;}
     for(i=0;i<=7;i++)
        for(j=0;j<=7;j++)
            if(b[i][j]==0)
               b[i][j]=2;
     for(i=0;i<=7;i++)
        if(b[l][i]==0)
           b[l][i]==1;
        if(b[i][c]==0)
            b[i][c]=1;
     for(i=0;i<=7;i++)
        for(j=0;j<=7;j++)
         if(b[i][j]==0)
            b[i][j]=1;

}
void test()
{
    int i,j,k;
    for(i=1;i<=64;i++)
       for(j=1;j<=64;j++)
           for(k=1;k<=64;k++)
               cout<<"1";

}
int main()
{
    for(i=0;i<=7;i++)
       {for(j=0;j<=7;j++)
          {f>>u[i][j];
          cout<<u[i][j]<<' ';
          if(u[i][j]==5)
             {a[i][j]=-1;
             b[i][j]=-1;
             c[i][j]=-1;
             vizitat[i][j]=1;}
          if(u[i][j]==4)
             {a[i][j]=-2;
             b[i][j]=-2;
             c[i][j]=-2;
             vizitat[i][j]=1;}
          if(u[i][j]==3)
             {l1=i;c1=j;}    //knight
          if(u[i][j]==2)
             {l2=i;c2=j;
             vizitat[i][j]=1;}   //bishop
          if(u[i][j]==1)
             {l3=i;c3=j;}}  //queen
       cout<<'\n';}
    mutariknight(l1,c1,0);
    a[l1][c1]=0; //knight
    for(i=0;i<=7;i++)
      {for(j=0;j<=7;j++)
          g<<a[i][j]<<' ';
      g<<'\n';}
    b[l2][c2]=1;
    mutaribishop(l2,c2,0);
    b[l2][c2]=0;
    g<<'\n';
    for(i=0;i<=7;i++)
      {for(j=0;j<=7;j++)
          g<<b[i][j]<<' ';
      g<<'\n';}
    Queen(c,l3,c3,1);
    c[l3][c3]=0;
    g<<'\n';
    for(i=0;i<=7;i++)
      {for(j=0;j<=7;j++)
          g<<c[i][j]<<' ';
      g<<'\n';}
    return 0;
}
