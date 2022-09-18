#include<iostream>
using namespace std;
void bubbleSort(int*arr,int size){
    // Base case
    if(size==0 || size == 1){
        return;
    }
    // case 1
    for(int i=0; i<size-1; i++){
        if(arr[i]>arr[i+1]){
            swap(arr[i],arr[i+1]);
        }
    }
    // Recurrsion Call
    bubbleSort(arr,size-1);
}

int main(){
    int arr[] = {4,1,5,6};
    int size = 4;
    bubbleSort(arr,size);
    for(int val:arr){
        cout<<val<<" ";
    }
    return 0;
}