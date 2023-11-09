#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main()
{
	int n;
	cin >> n;
	
	vector<bool> arr(n+1, 1);
	
	arr[0] = 0;
	arr[1] = 0;
	
	int end = sqrt(n);
	
	for (int i=2; i<=end; i++)
	{
		if (arr[i] == 0) continue;
		
		for (int j=i*2; j<=n; j+=i)
		{
			arr[j] = 0;
		}
	}
	
	for (int i=2; i<=n; i++)
	{
		if (arr[i]) cout << i << ' ';
	}
	cout << endl;
}
