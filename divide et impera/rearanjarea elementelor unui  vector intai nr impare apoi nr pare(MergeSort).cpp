#include <iostream>
using namespace std;
int x[100],n;
void divizeaza(int s,int d,int &m)
{
    m=(s+d)/2;
}
void interclaseaza(int s,int d,int m)
{
    int i=s,j=m+1,k=1,v[100];
    while(i<=m&&j<=d)
         {
             if(x[i]%2==1)
                {
                    v[k]=x[i];
                    i++;
                    k++;
                }
             else
                    {i++;}
             if(x[j]%2==1)
                {
                    v[k]=x[j];
                    j++;
                    k++;
                }
             else
                    {j++;}
         }
    if(i<=m)
       while(i<=m)
            {
                if(x[i]%2==1)
                    {v[k]=x[i];
                    k++;}
                i++;
            }
    else
       while(j<=d)
            {
                if(x[j]%2==1)
                   {v[k]=x[j];
                   k++;}
                j++;
            }
    for(i=s;i<=d;i++)
        if(x[i]%2==0)
           {v[k]=x[i];
           k++;}
    for(i=s,k=1;i<=d;k++,i++)
        x[i]=v[k];
}
void MergeSort(int s,int d)
{
    int m;
    if(s<d)
        {
            divizeaza(s,d,m);
            MergeSort(s,m);
            MergeSort(m+1,d);
            interclaseaza(s,d,m);
        }
}
int main()
{
    int i;
    cout<<"n= ";cin>>n;
    for(i=1;i<=n;i++)
        {
            cout<<"x["<<i<<"]=";
            cin>>x[i];
        }
    MergeSort(1,n);
    cout<<"vectorul sortat"<<'\n';
    for(i=1;i<=n;i++)
       cout<<x[i]<<' ';
}
