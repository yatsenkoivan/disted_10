#include <iostream>
using namespace std;


double Sb(const double& a, const double& b, const double& c, const double& h)
{
    return (a+b+c)*h;
}

double Sp(const double& a, const double& b, const double& c)
{
    return 2*(a*b + b*c + a*c);
}

double V(const double& a, const double& b, const double& c)
{
    return a*b*c;
}


int main()
{
    int N;
    double a, b, c, h;
    cin >> N >> a >> b >> c >> h;
    
    switch(N)
    {
        case 1:
            cout << Sb(a,b,c,h);
            break;
        case 2:
            cout << Sp(a,b,c);
            break;
        case 3:
            cout << V(a,b,c);
            break;
    }
}