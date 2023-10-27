#include <iostream>
using namespace std;

int func1(int n)
{
    if (n == 0) return 1;
    int _0=0, _1=0, _2=0;
    _0 = func1(n-1);
    if (n > 1) _1 = func1(n-2);
    if (n > 2) _2 = func1(n-3);
    
    return _0+_1+_2;
}

int func2(int n)
{
    if (n <= 3) return n;
    int a=1, b=2, c=4;
    
    int temp;
    for (int i=4; i<=n; i++)
    {
        temp = a+b+c;
        a = b;
        b = c;
        c = temp;
    }
    return c;
}

int main()
{
    int K, N;
    cin >> K >> N;
    
    switch(K)
    {
        case 1:
            cout << func1(N) << endl;
            break;
        case 2:
            cout << func2(N) << endl;
            break;
    }
}
