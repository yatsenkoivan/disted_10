#include <iostream>
using namespace std;

int main()
{
    int N;
    cin >> N;
    
    int _2last = N%100;
    
    if (_2last >= 11 && _2last <= 14)
    {
        cout << "rokiv\n";
        return 0;
    }
    switch(N%10)
    {
        case 1:
            cout << "rik\n";
            break;
        case 2:
        case 3:
        case 4:
            cout << "roky\n";
            break;
        default:
            cout << "rokiv\n";
            break;
    }
}
