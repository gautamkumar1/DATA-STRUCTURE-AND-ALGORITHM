#include <iostream>
using namespace std;
int minIndex(int *arr, int n)
{
    int min = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] < min)
        {
            return i;
        }
    }
}
void selectionSort(int *arr, int n, int i)
{
    // Base Case
    if (i + 1 > n)
    {
        return;
    }
    int Index = i;
    for (int j = i + 1; j < n; j++)
    {
        if (arr[j] < arr[Index])
        {
            Index = j;
        }
    }
    swap(arr[Index], arr[i]);
    selectionSort(arr, n, i + 1);
}

int main()
{
    int arr[] = {4, 1, 5, 6, 2, 3, 7};
    int size = 7;
    selectionSort(arr, size, 0);
    for (int val : arr)
    {
        cout << val << " ";
    }
    return 0;
}