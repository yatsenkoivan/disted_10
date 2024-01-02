#include <iostream>
#include <stack>
using namespace std;

long long func1(const int& a, int n)
{
	if (n == 0) return 1ll;
	return a*func1(a,n-1);
}

long long func2(const int& a, int n)
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
	
long long func3(const int& a, int n)
{
	if (n == 0) return 1;
	stack<long long> values;
	long long current;
	while (n > 0)
	{
		if (n%2 == 0)
			values.push(1);
		else
			values.push(a);
		n /= 2;
	}
	while (values.size() > 1)
	{
		current = values.top();
		values.pop();
		values.top() = values.top()*current*current;
	}
	return values.top();
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
		case 3:
			cout << func3(a, n) << endl;
			break;
	}	
}