#include <iostream>
using namespace std;

int main()
{
    int N, a;
    cin >> N >> a;
    
    string res = "";
    
    while (N > 0)
    {
        res = char(N%a + '0')+res;
        N /= a;
    }
    cout << res << endl;
}
