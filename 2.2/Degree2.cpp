#include <iostream>
using namespace std;

long long func1(const int& a, const int& n)
{
	if (n == 0) return 1ll;
	return a*func1(a,n-1);
}

long long func2(const int& a, const int& n)
{
	if (n == 0) return 1ll;
	long long res = func2(a, n/2);
	res *= res;
	
	if (n%2 != 0)
	{
		res *= a;
	}
	return res;
		
}
	

int main()
{
	int k, a, n;
	cin >> k >> a >> n;
	
	switch(k)
	{
		case 1:
			cout << func1(a, n) << endl;
			break;
		case 2:
			cout << func2(a, n) << endl;
			break;
	}	
}