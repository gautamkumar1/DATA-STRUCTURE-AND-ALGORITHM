#include<iostream>
using namespace std;

int partition(int*arr,int low,int high){
    int pivot = arr[low];
    int count = 0;
    for(int i=low+1; i<=high; i++){
        if(arr[i]<=pivot){
            count++;
        }
    }
    int pivotIndex = count+low;
    swap(arr[pivotIndex],arr[low]);
    int i = low;
    int j = high;
    while (i<pivotIndex && j>pivotIndex)
    {
        if(arr[i]<=pivot){
            i++;
        }
        if(arr[j]>pivot){
            j--;
        }
        if(i<pivotIndex && j>pivotIndex){
            swap(arr[i++],arr[j--]);
        }
        
    }
    return pivotIndex;
    
}

void quickSort(int*arr,int low,int high){
    if(low>=high){
        return;
    }
    int pivotIndex = partition(arr,low,high);
    quickSort(arr,low,pivotIndex);
    quickSort(arr,pivotIndex+1,high);
}

int main(){
    int arr[5] = {4,8,1,0,9};
    int n = 5;
    quickSort(arr,0,n-1);
    for(int val: arr){
        cout<<val<<" ";
    }
    return 0;
}