#include <iostream>
#include <stack>
using namespace std;

int main()
{
    stack<int> St;
    int N,K;
    int x;
    cin >> N >> K;
    for (int i=0; i<N; i++)
    {
        cin >> x;
        if (x%K == 0)
            St.push(x);
    }
    
    while (!St.empty())
    {
        cout << St.top() << ' ';
        St.pop();
    }
    cout << endl;
}
