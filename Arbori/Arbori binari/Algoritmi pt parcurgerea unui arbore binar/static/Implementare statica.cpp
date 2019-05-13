#include <iostream>
#include <fstream>
#include <cstdio>
#include <vector>

std::ifstream f("static_tree.txt");

int st[20], dr[20], n;

std::vector<bool> markChildren(const std::vector<int>& left, const std::vector<int>& right)
{   
    std::vector<bool> children(left.size(), false);
    
    /*for(auto x: left)
    {
        children[x] = true;
    }

    for(auto x: right)
    {
        children[x] = true;
    }*/

    for(auto i=0; i < left.size(); ++i)
    {
        children[left[i]] = true;
        children[right[i]] = true;
    }

    return children;
}


int findRoot(const std::vector<int>& left, const std::vector<int>& right)
{
    auto children = markChildren(left, right);

    auto root = -1;
    auto rootFlag = false;

    for(auto i=0; i< children.size(); ++i)
    {
        if(children[i] == rootFlag)
        {
            root = i;
            i = children.size(); //break
        }
    }

    return root;
}

void parseRSD()
{
    std::cout<<i<<' ';
    if(st[i]!=0)
       rsd(st[i]);
    if(dr[i]!=0)
       rsd(dr[i]);
}

void parseRSD()
{
    
}

int rad()
{
    int i,j,ok;
    for(i=1;i<=n;i++)
    {
        ok=0;
        for(j=1;j<=n;j++)
        {
            if(st[j]==i||dr[j]==i)
            {
                ok=1;
            }
        }
        if(ok==0)
        {
          return i;
        }
    }

}
void rsd(int i)
{
    std::cout<<i<<' ';
    if(st[i]!=0)
       rsd(st[i]);
    if(dr[i]!=0)
       rsd(dr[i]);
}
int main()
{
    int i,j,r;
    f>>n;
    for(i=1;i<=n;i++)
        f>>st[i];
    for(i=1;i<=n;i++)
        f>>dr[i];
    r=rad();
    rsd(r);

    std::getchar();
}
