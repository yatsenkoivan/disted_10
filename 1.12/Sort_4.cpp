#include <iostream>
#include <vector>
using namespace std;

void bubble_sort(vector<int>& arr)
{
    bool sorted;
    for (int i=0; i<arr.size(); i++)
    {
        sorted = 1;
        for (int j=0; j<arr.size()-1-i; j++)
        {
            if (arr[j] > arr[j+1])
            {
                swap(arr[j], arr[j+1]);
                sorted = 0;
            }
        }
        if (sorted) return;
    }
}

void selection_sort(vector<int>& arr)
{
    int mn;
    int mn_index;
    for (int i=0; i<arr.size(); i++)
    {
        mn = arr[i];
        mn_index = i;
        for (int j=i+1; j<arr.size(); j++)
        {
            if (arr[j] < mn)
            {
                mn = arr[j];
                mn_index = j;
            }
        }
        swap(arr[i], arr[mn_index]);
    }
}

void insertion_sort(vector<int>& arr)
{
    for (int i=1; i<arr.size(); i++)
    {
        for (int j=i; j>0; j--)
        {
            if (arr[j] < arr[j-1])
            {
                swap(arr[j], arr[j-1]);
            }
            else
                break;
        }
    }
}

void bubble_sort2(vector<int>& arr)
{
    bool sorted;
    bool to_left = 1;
    for (int i=0; i<arr.size(); i++)
    {
        sorted = 1;
        if (to_left)
        {
            for (int j=0; j<arr.size()-1; j++)
            {
                if (arr[j] > arr[j+1])
                {
                    swap(arr[j], arr[j+1]);
                    sorted = 0;
                }
            }
        }
        else
        {
            for (int j=arr.size()-1; j>0; j--)
            {
                if (arr[j] < arr[j-1])
                {
                    swap(arr[j], arr[j-1]);
                    sorted = 0;
                }
            }
        }
        
        if (sorted) return;
        
        to_left = ~to_left;
    }
}


int main()
{
    short K, N;
    cin >> K >> N;
    vector<int> arr(N);
    for (int i=0; i<N; i++) cin >> arr[i];
    
    switch(K)
    {
        case 1:
            bubble_sort(arr);
            break;
        case 2:
            selection_sort(arr);
            break;
        case 3:
            insertion_sort(arr);
            break;
        case 4:
            bubble_sort2(arr);
            break;
    }
    
    for (int i : arr)
    {
        cout << i << ' ';
    }
    cout << endl;
    
}
