#include <iostream>
#include <cmath>
using namespace std;


double V(const double& R, const double& h)
{
    return M_PI * R*R * h;
}

double Sb(const double& R, const double& h)
{
    return 2 * M_PI * R * h;
}

double Sp(const double& R, const double& h)
{
    return 2 * M_PI * R * (R+h);
}


int main()
{
    int N;
    double R, h;
    cin >> N >> R >> h;
    
    switch(N)
    {
        case 1:
            cout << V(R,h);
            break;
        case 2:
            cout << Sb(R,h);
            break;
        case 3:
            cout << Sp(R,h);
            break;
    }
}