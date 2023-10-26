#include <iostream>
#include <set>
using namespace std;

bool check(int n)
{
    int a = n;
    int b = n+n;
    set<short> digits;
    for (; a>0; a/=10)
    {
        digits.insert(a%10);
    }
    for (; b>0; b/=10)
    {
        digits.insert(b%10);
    }
    return digits.size()==8;
}

bool check_res(int n, set<short> digits)
{
    for (; n>0; n/=10)
    {
        digits.insert(n%10);
    }
    return digits.size()==8;
}

int main()
{
    for (int i=1000; i<5000; i++)
    {
        if (check(i) == 0) continue;
        cout << i << '+' << i << '=' << i+i << endl;
    }
}
