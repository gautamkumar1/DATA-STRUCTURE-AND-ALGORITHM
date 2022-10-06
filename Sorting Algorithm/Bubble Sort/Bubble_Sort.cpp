#include <bits/stdc++.h>
using namespace std;

void BubbleSort(vector<int> &arr)
{
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j + 1], arr[j]);
            }
        }
    }
}

int main()
{
    vector<int> arr = {4, 2, 8, 1, 3};
    BubbleSort(arr);
    for (int val : arr)
    {
        cout << val << " ";
    }
    cout << endl;
    return 0;
}