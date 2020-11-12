#include <iostream>
#include <queue>
#include <string>
using namespace std;

int main()
{
    queue<string> q;
    q.push("UNU");
    q.push("DOI");
    cout<<q.front()<<' '<<q.back()<<'\n'<<q.size()<<'\n';

    q.push("TREI");
    q.push("PATRU");
    while(!q.empty())
    {
        cout<<q.front()<<' ';
        q.pop();
    }
    return 0;
}
