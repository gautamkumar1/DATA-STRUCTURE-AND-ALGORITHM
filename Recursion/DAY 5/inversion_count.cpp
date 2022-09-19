#include<iostream>
using namespace std;
/*
Two elements a[i] and a[j] form an inversion if a[i] > a[j] 
Input: arr[] = {8, 4, 2, 1}
Output: 6

Explanation: Given array has six inversions:
(8, 4), (4, 2), (8, 2), (8, 1), (4, 1), (2, 1).


Input: arr[] = {3, 1, 2}
Output: 2

Explanation: Given array has two inversions:
(3, 1), (3, 2) 
*/
int inversionCount(int*arr,int n){ // Method one 
    int count = 0;
    for (int i = 0; i < n-1; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            if(arr[i]>arr[j])
             count++;
        }
        
    }
    return count;
}

// Method 2
int merge(int *a, int low, int high, int mid)
{
    int i, j, k;
    i = low;
    j = mid + 1;
    k = low;
    int b[100];
    int count = 0;
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
            count = count+(mid-i);
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
    return count;
}

int mergeSort(int *arr, int low, int high)
{
    int count = 0;
    if (low < high)
    {
        int mid = low + (high - low) / 2;
        count+=mergeSort(arr,low,mid);
        count+=mergeSort(arr,mid+1,high);
        count+=merge(arr,low,mid+1,high);
    }
    return count;
}
int main(){
    int arr[3] = {3,1,2};
    int n = 3;
    // int ans = inversionCount(arr,n);
    int ans = mergeSort(arr,0,n-1);
    cout<<"Number of Inversions Count is "<<ans;
    return 0;
}