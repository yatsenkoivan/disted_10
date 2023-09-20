#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin>>N;
    if (N%100 >= 11 && N%100 <= 19)
    {
        cout << "rokiv" << endl;
    }
    else
    {
        switch(N%10)
        {
            case 1:
                cout<<"rik\n";
                break;
            case 2:
            case 3:
            case 4:
                cout<<"roky"<<endl;
                break;
            default:
                cout<<"rokiv"<<endl;
                break;
        }
    }
}
