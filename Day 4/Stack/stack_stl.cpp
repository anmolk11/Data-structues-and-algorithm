#include <stack>
#include <iostream>
using namespace std;

int main()
{
    stack<int> stk;
    stk.push(10);
    stk.push(20);
    stk.push(30);
    stk.push(40);
    
    while (!stk.empty())
    {
        cout << "Top : " << stk.top() << '\n';
        stk.pop();
    }
}