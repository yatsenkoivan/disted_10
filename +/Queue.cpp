#include <iostream>
#include <queue>
using namespace std;

int main()
{
    queue<int> q;
    int N, K;
    int x;
    cin >> N >> K;

    for (int i=0; i<N; i++)
    {
        cin >> x;
        if (x < 0 && x%K == 0) q.push(x);
    }
    
    while (!q.empty())
    {
        cout << q.front() << ' ';
        q.pop();
    }
    
    cout << endl;
}
