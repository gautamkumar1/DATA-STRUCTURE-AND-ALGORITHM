#include <iostream>
using namespace std;

void merge(int *a, int low, int high, int mid)
{
    int i, j, k;
    i = low;
    j = mid + 1;
    k = low;
    int b[100];
    while (i <= mid && j <= high)
    {
        if (a[i] < a[j])
        {
            b[k] = a[i];
            i++;
            k++;
        }
        else
        {
            b[k] = a[j];
            j++;
            k++;
        }
    }
    while (i <= mid)
    {
        b[k] = a[i];
        i++;
        k++;
    }
    while (j <= high)
    {
        b[k] = a[j];
        j++;
        k++;
    }
    for (int x = low; x <= high; x++)
    {
        a[x] = b[x];
    }
}

void mergeSort(int *arr, int low, int high)
{
    if (low < high)
    {
        int mid = low + (high - low) / 2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);
        merge(arr, low, high, mid);
    }
}

int main()
{
    int arr[] = {5, 8, 1, 3, 2, 0, 8, 9, 2, 3, 6};
    int n = 11;
    mergeSort(arr, 0, n - 1);
    for (int val : arr)
    {
        cout << val << " ";
    }
    return 0;
}