#include <iostream>
#include <stack>
using namespace std;

int main()
{
    stack<int> St;
    int N;
    int x;
    cin >> N;
    for (int i=0; i<N; i++)
    {
        cin >> x;
        St.push(x);
    }
    
    while (!St.empty())
    {
        if (St.top() > 0 && St.top()%2 == 0)
            cout << St.top() << ' ';
        St.pop();
    }
    cout << endl;
}
