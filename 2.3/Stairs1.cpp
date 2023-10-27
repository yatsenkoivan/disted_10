#include <iostream>
using namespace std;

int func(int n)
{
    if (n == 0) return 1;
    int _0=0, _1=0, _2=0;
    _0 = func(n-1);
    if (n > 1) _1 = func(n-2);
    if (n > 2) _2 = func(n-3);
    
    return _0+_1+_2;
    
}

int main()
{
    int N;
    cin >> N;
    
    cout << func(N) << endl;
}
