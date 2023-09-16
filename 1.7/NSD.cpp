#include <iostream>
using namespace std;

int alg1(int a, int b)
{
    if (a == 0 || b == 0) return max(a,b);
    while (a != b)
    {
        if (a > b) a -= b;
        else b -= a;
    }
    return a;
}

int alg2(int a, int b)
{
    if (a == 0 || b == 0) return max(a,b);
    int temp;
    while (true)
    {
        temp = a%b;
        if (temp == 0) break;
        a = b;
        b = temp;
    }
    return b;
}

int main()
{
    int n, a, b;
    cin >> n >> a >> b;
    
    if (n == 1) cout << alg1(a,b) << endl;
    if (n == 2) cout << alg2(a,b) << endl;
}