#include <iostream>
using namespace std;
int Binary_Search(int *arr, int low, int high, int k)
{
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] == k)
        {
            return mid;
        }
        else if (arr[mid] < k)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return -1;
}

int Exponential_Search(int *arr, int n, int k)
{
    if (arr[0] == k)
    {
        return 0;
    }
    int i = 1;
    while (i < n && arr[i] <= k)
    {
        i *= 2;
    }

    return Binary_Search(arr, i / 2, min(i, n - 1), k);
}


int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int n = 5;
    int k = 4;
    cout << "Element found at index is " << Exponential_Search(arr, n, k) << endl;
    return 0;
}