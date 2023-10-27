#include <iostream>
#include <vector>
using namespace std;

void set_neighbors(vector<vector<bool>>& arr, int i, int j)
{
    arr[i][j] = 0;
    //down
    if (i < arr.size()-1 && arr[i+1][j]) set_neighbors(arr, i+1, j);
    //up;
    if (i > 0 && arr[i-1][j]) set_neighbors(arr, i-1, j);
    //right
    if (j < arr[i].size()-1 && arr[i][j+1]) set_neighbors(arr, i, j+1);
    //left
    if (j > 0 && arr[i][j-1]) set_neighbors(arr, i, j-1);
}

int func(vector<vector<bool>> arr)
{
    int res = 0;
    for (int i=0; i<arr.size(); i++)
    {
        for (int j=0; j<arr[i].size(); j++)
        {
            if (arr[i][j])
            {
                set_neighbors(arr, i, j);
                res++;
            }
        }
    }
    return res;
}

int main()
{
    short m, n;
    cin >> m >> n;
    
    vector<vector<bool>> arr(m, vector<bool>(n));
    
    bool temp;
    for (int i=0; i<m; i++)
    {
        for (int j=0; j<n; j++)
        {
            cin >> temp;
            arr[i][j] = temp;
        }
    }
    
    cout << func(arr) << endl;
}