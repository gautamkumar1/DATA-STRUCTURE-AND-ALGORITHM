#include<bits/stdc++.h>
using namespace std;

int Binarysearch(vector<int>&arr,int target){
    int n = arr.size();
    int low = 0;
    int high = n-1;
    while (low<=high)
    {
        int mid = low+(high-low)/2;
        if(arr[mid]==target){
            return mid;
        }
        else if (arr[mid]<target)
        {
            low = mid+1;
        }
        else
        {
            high = mid-1;
        }
    }
    return -1;
}

int main(){
    vector<int> arr = {4,1,3,8,9};
    int target = 9;
    int index = Binarysearch(arr,target);
    cout<<"Element Found At Index is : "<<index<<endl;
    return 0;
}