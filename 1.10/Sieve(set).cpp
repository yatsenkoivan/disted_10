#include <iostream>
#include <set>
#include <cmath>
using namespace std;

int main()
{
	int n;
	cin >> n;
	
	set<int> arr;
	
	for (int i=2; i<=n; i++) arr.insert(i);
	
	int end = sqrt(n);
	
	for (int i=2; i<=end; i++)
	{
		if (arr.find(i) == arr.end()) continue;
		
		for (int j=i*2; j<=n; j+=i)
		{
			arr.erase(j);
		}
	}
	
	for (int i : arr)
	{
		cout << i << ' ';
	}
	cout << endl;
	
}
