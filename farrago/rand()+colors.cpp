#include <iostream>
#include <stdlib.h>

using namespace std;
int main()
{
   int m=19;
   while(m<20)
       {if(rand()%3==0)
          {system( "color 01" );
          cout<<'0';}
       if(rand()%3==1)
          {system( "color 05" );
          cout<<'1';}
       if(rand()%3==2)
          {system( "color 09" );
          cout<<'2';}}
}
