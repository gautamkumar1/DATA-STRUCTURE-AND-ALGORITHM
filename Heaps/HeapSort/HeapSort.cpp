#include<iostream>
using namespace std;

void heapifiy(int*arr,int n,int i){
    int largest = i;
    int left = 2*i;
    int right = 2*i+1;
    if(left<=n && arr[largest]<arr[left]){
        largest = left;
    }
    if(right<=n && arr[largest]<arr[right]){
        largest = right;
    }
    if(largest!=i){
        swap(arr[largest],arr[i]);
        heapifiy(arr,n,largest);
    }
}

void bulidMaxHeap(int*arr,int n){
    for(int i=n/2; i>0; i--){
        heapifiy(arr,n,i);
    }
}
// T(N) : O(logn)
void HeapSort(int*arr,int n){
    int size = n;
    while (size>1)
    {
        swap(arr[size],arr[1]);
        size--;
        heapifiy(arr,size,1);
    }
    
}

void printHeap(int*arr,int n){
    for(int i=1; i<=n; i++){
        cout<<arr[i]<<" ";
    } cout<<endl;
}

int main(){
    int arr[] = {-1,10,9,89,12};
    int size = 4;
    bulidMaxHeap(arr,size);
    HeapSort(arr,size);
    printHeap(arr,size);
    return 0;
}