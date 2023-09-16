#include <iostream>
#include <cmath>
using namespace std;


double Vk(const double& R)
{
    return 4.0/3 * M_PI*pow(R,3);
}

double Vs(const double& R, const double& h)
{
    return 1.0/3 * M_PI * h*h * (3*R-h);
}

double S(const double& R, const double& h)
{
    return 2 * M_PI * R * h;
}


int main()
{
    int N;
    double R, h;
    cin >> N >> R >> h;
    
    switch(N)
    {
        case 1:
            cout << Vk(R);
            break;
        case 2:
            cout << Vs(R,h);
            break;
        case 3:
            cout << S(R,h);
            break;
    }
}