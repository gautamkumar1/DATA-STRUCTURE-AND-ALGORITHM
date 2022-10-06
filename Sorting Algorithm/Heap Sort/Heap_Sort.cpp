#include<bits/stdc++.h>
using namespace std;

void Heapfiy(int*arr,int n,int i){
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if(left<n && arr[left]>arr[largest]){
        largest = left;
    }
    if(right<n && arr[right]>arr[largest]){
        largest = right;
    }
    if(largest!=i){
        swap(arr[i],arr[largest]);
        Heapfiy(arr,n,largest);
    }
}

void BulidMaxHeap(int*arr,int n){
    for (int i = n/2-1; i>=0; i--)
    {
        Heapfiy(arr,n,i);
    }
}

void HeapSort(int*arr,int n){
    BulidMaxHeap(arr,n);
    for (int i = n-1; i>=0; i--)
    {
        swap(arr[0],arr[i]);
        Heapfiy(arr,i,0);
    }
}

int main(){
    int arr[5] = {4,2,8,1,3};
    int n = 5;
    HeapSort(arr,n);
    for(int val: arr){
        cout<<val<<" ";
    } cout<<endl;
    return 0;
}