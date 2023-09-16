#include <iostream>
using namespace std;

int main()
{
    int N, a;
    cin >> N >> a;
    
    int res = 0;
    int mult = 1;
    
    while (N > 0)
    {
        res += mult * (N%10);
        N /= 10;
        mult *= a;
    }
    
    cout << res << endl;
}
