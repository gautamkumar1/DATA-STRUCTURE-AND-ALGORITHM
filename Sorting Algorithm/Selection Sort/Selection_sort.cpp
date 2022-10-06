#include<bits/stdc++.h>
using namespace std;

void SelectionSort(vector<int>&arr){
    int n = arr.size();
    for (int i = 0; i < n-1; i++)
    {
        int minIndex = i;
        for (int j = i+1; j < n; j++)
        {
            if(arr[j]<arr[minIndex]){
                minIndex = j;
            }
        }
        swap(arr[minIndex],arr[i]);
        
    }
    
}

int main(){
    vector<int> arr = {4,2,8,1,3};
    SelectionSort(arr);
    for(int val: arr){
        cout<<val<<" ";
    } cout<<endl;
    return 0;
}