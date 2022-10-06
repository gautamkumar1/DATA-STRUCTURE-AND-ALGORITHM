#include<bits/stdc++.h>
using namespace std;

// Formula total occurence = (last index - first index )+1;

int firstIndex(vector<int>&arr,int target){
    int len = arr.size();
    int ans = -1;
    int low  = 0;
    int high = len-1;
    while (low<=high)
    {
        int mid = low+(high-low)/2;
        if(arr[mid]==target){
            ans = mid;
            high = mid-1;
        }
        else if(arr[mid]<target){
            low = mid+1;
        }
        else
        {
            high = mid-1;
        }
        
    }
    return ans;
}

int LastIndex(vector<int>&arr,int target){
    int len = arr.size();
    int ans = -1;
    int low = 0;
    int high = len-1;
    while (low<=high)
    {
        int mid = low+(high-low)/2;
        if(arr[mid]==target){
            ans = mid;
            low = mid+1;
        }
        else if(arr[mid]<target){
            low = mid+1;
        }
        else
        {
            high = mid-1;
        }
        
    }
    return ans;
}

int totalOccurence(vector<int>&arr,int target){
    int first_Index = firstIndex(arr,target);
    int Last_Index = LastIndex(arr,target);
    int ans = (Last_Index-first_Index)+1;
    return ans;
}

int main(){
    vector<int> arr = {1,2,3,4,4,4,50};
    int target = 4;
    int TotalOccurence = totalOccurence(arr,target);
    cout<<"Total Number of Occurence  is "<<TotalOccurence<<endl;
    return 0;
}