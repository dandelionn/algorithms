#include <iostream>
#include <stack>
using namespace std;

int main()
{
    stack<char> s;

    s.push('A');
    s.push('B');

    cout<<s.top()<<'\n';
    s.pop();

    s.top()='W';

    s.push('W');
    s.push('W');

    while(!s.empty())
    {
        cout<<s.top()<<' ';
        s.pop();
    }

    return 0;
}
