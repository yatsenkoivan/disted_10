#include <iostream>
using namespace std;


double A2(const double& a1, const double& d)
{
    return a1 + d;
}

double An(const double& a1, const double& d, const int& n)
{
    return a1 + d*(n-1);
}

double S(const double a1, const double& d, const int& n)
{
    return n*(a1 + An(a1,d,n)) / 2;
}


int main()
{
    int K, n;
    double a1,d ;
    cin >> K >> a1 >> d >> n;
    
    switch(K)
    {
        case 1:
            cout << A2(a1,d);
            break;
        case 2:
            cout << An(a1,d,n);
            break;
        case 3:
            cout << S(a1,d,n);
            break;
    }
}