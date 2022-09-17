#include<iostream>
using namespace std;

bool binarySearch(int*arr,int low,int high,int key){
    if(low>high)
        return false;
    int mid = low+(high-low)/2;
    if(arr[mid] == key){
        return true;
    }
    else if(arr[mid]<key){
        return binarySearch(arr,mid+1,high,key);
    }
    else
    {
        return binarySearch(arr,low,mid-1,key);
    }
    
}

int main(){
    int arr[5] = {1,2,3,4,5};
    int size = 5;
    int low = 0;
    int high = size-1;
    int key = 2;
    bool ans = binarySearch(arr,low,high,key);
    if(ans){
        cout<<"Element found"<<endl;
    }
    else
    {
        cout<<"Element not found"<<endl;
    }
    return 0;
    
}