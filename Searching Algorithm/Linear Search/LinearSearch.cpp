#include<bits/stdc++.h>
using namespace std;

int Linear_Search(vector<int>&arr,int target){
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        if(arr[i]==target){
            return i;
        }
    }
    return -1;
}

int main(){
    vector<int> arr = {4,1,3,8,9};
    int target = 9;
    int index = Linear_Search(arr,target);\
    cout<<"Element Found At Index is : "<<index<<endl;
    return 0;
}