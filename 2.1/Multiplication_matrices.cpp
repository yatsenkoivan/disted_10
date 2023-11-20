#include <iostream>
#include <vector>
using namespace std;

template<typename T>
void operator>>(istream& in, vector<vector<T>>& arr)
{
    for (int i=0; i<arr.size(); i++)
    {
        for (int j=0; j<arr[i].size(); j++)
            in >> arr[i][j];
    }
}

template<typename T>
ostream& operator<<(ostream& out, const vector<vector<T>>& arr)
{
    for (int i=0; i<arr.size(); i++)
    {
        for (int j=0; j<arr[i].size(); j++)
        {
            out << arr[i][j] << ' ';
        }
        out << endl;
    }
    return out;
}

int main()
{
    int m,n,k;
    cin >> m >> n >> k;
    
    vector<vector<int>> A(m, vector<int>(n));
    vector<vector<int>> B(n, vector<int>(k));
    
    cin >> A;
    cin >> B;
    
    int temp;
    vector<vector<int>> Res(m, vector<int>(k));
    for (int i=0; i<m; i++)
    {
        for (int j=0; j<k; j++)
        {
            temp = 0;
            for (int t=0; t<n; t++)
            {
                temp += A[i][t]*B[t][j];
            }
            Res[i][j] = temp;
        }
    }

    cout << Res << endl;
}
