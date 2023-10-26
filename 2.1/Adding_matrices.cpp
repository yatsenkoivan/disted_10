#include <iostream>
#include <vector>
using namespace std;

void add(const vector<vector<int>>& arr1, const vector<vector<int>>& arr2, vector<vector<int>>& res)
{
    for (int i=0; i<arr1.size(); i++)
    {
        for (int j=0; j<arr1[i].size(); j++)
        {
            res[i][j] = arr1[i][j] + arr2[i][j];
        }
    }
}

int main()
{
    short M, N;
    cin >> M >> N;
    vector<vector<int>> arr1(M, vector<int>(N));
    vector<vector<int>> arr2(M, vector<int>(N));
    vector<vector<int>> res(M, vector<int>(N));
    
    for (int i=0; i<M; i++)
    {
        for (int j=0; j<N; j++)
            cin >> arr1[i][j];
    }
    
    for (int i=0; i<M; i++)
    {
        for (int j=0; j<N; j++)
            cin >> arr2[i][j];
    }
    
    add(arr1, arr2, res);
    
    for (int i=0; i<M; i++)
    {
        for (int j=0; j<N; j++)
        {
            cout << res[i][j] << ' ';
        }
        cout << endl;
    }
}
