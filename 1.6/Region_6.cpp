#include <iostream>
using namespace std;

bool InCircle(const double& x, const double& y, const double& R)
{
    return (x*x + y*y <= R*R);
}


bool check1(const double& x, const double& y, const double& a, const double& R)
{
    return (x >= -a && InCircle(x,y,R));
}

bool check2(const double& x, const double& y, const double& a, const double& R)
{
    return (abs(x) <= a && InCircle(x,y,R) == false);
}

bool check3(const double& x, const double& y, const double& R)
{
    return InCircle(x,y,R) && ((x >= 0 && y >= 0) || (x <= 0 && y <= 0 && y <= x));
}


int main()
{
    int N;
    double x, y, a, R;
    cin >> N >> x >> y >> a >> R;
    
    bool res = false;
    
    switch(N)
    {
        case 1:
            res = check1(x,y,a,R);
            break;
        case 2:
            res = check2(x,y,a,R);
            break;
        case 3:
            res = check3(x,y,R);
            break;
    }
    
    cout << (res ? "true" : "false") << endl;
}