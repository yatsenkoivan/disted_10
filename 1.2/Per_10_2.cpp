#include <iostream>
using namespace std;

int main()
{
    int N;
    cin >> N;
    
    string res = "";
    
    while (N > 0)
    {
        res = char(N%2 + '0')+res;
        N /= 2;
    }
    cout << res << endl;
}
