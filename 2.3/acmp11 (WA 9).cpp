#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int k, n;
    cin >> k >> n;
    vector<uint64_t> arr(n);
    arr[0] = 1;
    uint64_t s=arr[0];
    for (int i=1; i<k; i++)
    {
        arr[i] = s+1;
        s += arr[i];
    }
    for (int i=k; i<n; i++)
    {
        arr[i] = s;
        s -= arr[i-k];
        s += arr[i];
    }
    
    cout << arr[n-1] << endl;
}
