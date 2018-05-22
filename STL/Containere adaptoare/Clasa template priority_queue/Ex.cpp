#include <iostream>
#include <queue>
using namespace std;

int main()
{
    ///         Max-Heap
    priority_queue<int,vector<int>,greater<int> > q1;

    ///         Min-Heap
    priority_queue<int> q;

    q.push(15);      ///Complexitate: O(log n)
    q.push(90);
    q.push(2);
    q.push(111);
    q.push(-34);
    q.push(70);
    cout<<q.size()<<'\n';   ///O(1)

    while(!q.empty())       ///O(1)
    {
        cout<<q.top()<<" ";    ///O(1)
        q.pop();               ///O( log(n) )
    }
    return 0;
}
