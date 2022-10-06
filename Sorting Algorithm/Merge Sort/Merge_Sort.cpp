#include <bits/stdc++.h>
using namespace std;

void merge(int *A, int low, int high, int mid)
{
    // int i,j,k;
    int B[100];
    int i = low;
    int j = mid + 1;
    int k = low;
    while (i <= mid && j <= high)
    {
        if (A[i] < A[j])
        {
            B[k] = A[i];
            i++;
            k++;
        }
        else
        {
            B[k] = A[j];
            j++;
            k++;
        }
    }
    while (i <= mid)
    {
        B[k] = A[i];
        i++;
        k++;
    }
    while (j <= high)
    {
        B[k] = A[j];
        j++;
        k++;
    }
    for (int i = low; i <= high; i++)
    {
        A[i] = B[i];
    }
}

void MergeSort(int *arr, int low, int high)
{
    if (low < high)
    {
        int mid = low + (high - low) / 2;
        MergeSort(arr, low, mid);
        MergeSort(arr, mid + 1, high);
        merge(arr, low, high, mid);
    }
}

int main()
{
    int arr[] = {4, 2, 8, 1, 3};
    MergeSort(arr, 0, 4);
    for (int val : arr)
    {
        cout << val << " ";
    }
    cout << endl;
    return 0;
}