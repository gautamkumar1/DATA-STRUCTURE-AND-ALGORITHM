#include <iostream>
using namespace std;

void inserTionSort(int *arr, int n)
{
    // Base Case
    if (n == 0 || n == 1)
    {
        return;
    }
    int value = arr[n - 1];
    int j = n - 2;
    while (j >= 0 && arr[j] > value)
    {
        arr[j + 1] = arr[j];
        j--;
    }
    arr[j + 1] = value;

    inserTionSort(arr, n - 1);
}

int main()
{
    int arr[] = {4, 1, 5, 6};
    int size = 4;
    inserTionSort(arr, size);
    for (int val : arr)
    {
        cout << val << " ";
    }
    return 0;
}