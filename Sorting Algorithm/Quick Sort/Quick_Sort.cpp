#include<iostream>
#include<algorithm>
using namespace std;

int pivot(int*arr,int low,int high){
    int pivot = arr[low];
    int c = 0;
    for(int i = low+1; i<=high; i++){
        if(arr[i]<pivot){
            c++;
        }
    }
    int PivotIndex = c+low;
    swap(arr[PivotIndex],arr[low]);
    int left = low;
    int right = high;
    while (left<PivotIndex && right > PivotIndex)
    {
        while (arr[left]<=pivot)
        {
            left++;
        }
        while (arr[right]>=pivot)
        {
            right--;
        }
        if (left<PivotIndex && right > PivotIndex)
        {
            swap(arr[left],arr[right]);
            left++;
            right--;
        }
    }
    return PivotIndex;   
}

void QuickSort(int*arr,int low,int high){
    if(low>=high){
        return ;
    }
    int PivotIndex = pivot(arr,low,high);
    QuickSort(arr,low,PivotIndex-1);
    QuickSort(arr,PivotIndex+1,high);
}

int main(){
    int arr[5] = {4,3,2,1,6};
    QuickSort(arr,0,4);
    for(int val:arr){
        cout<<val<<" ";
    }cout<<endl;
    return 0;
}