#include <iostream>
#include <cmath>
using namespace std;


double Sb(const double& R, const double& L)
{
    return M_PI*R*L;
}

double V(const double& R, const double& h)
{
    return 1.0/3 * M_PI * R*R * h;
}

double Sp(const double& R, const double& L)
{
    return M_PI * R * (R+L);
}


int main()
{
    int N;
    double R, h, L;
    cin >> N >> R >> h >> L;
    
    switch(N)
    {
        case 1:
            cout << Sb(R, L);
            break;
        case 2:
            cout << V(R,h);
            break;
        case 3:
            cout << Sp(R,L);
            break;
    }
}