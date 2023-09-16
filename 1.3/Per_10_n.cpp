#include <iostream>
using namespace std;

int main()
{
    char arr[] {'A', 'B', 'C', 'D', 'E', 'F'};
    
    int b, n;
    cin >> b >> n;
    
    int mult = 1;
    string res = "";
    int val;
    
    while (b > 0)
    {
        val = b%n;
        if (val > 9)
        {
            res = arr[val-10] + res;
        }
        else
        {
            res = char(val+'0')+res;
        }
        b /= n;
    }
    cout << res << endl;
}
