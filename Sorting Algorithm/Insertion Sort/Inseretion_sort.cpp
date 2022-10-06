#include<bits/stdc++.h>
using namespace std;

void InsertionSort(vector<int>&arr){
    int n = arr.size();
        for (int i = 1; i < n; i++)
        {
            int j = i-1;
            int key = arr[i];
            while (j>=0)
            {
                if(arr[j]>key){
                    arr[j+1] = arr[j];
                }
                else
                {
                    break;
                }
                j--;
                
            }
            arr[j+1] = key;
        }
}

int main(){
    vector<int> arr = {4,2,6,8,1,3};
    InsertionSort(arr);
    for(int val: arr){
        cout<<val<<" ";
    } cout<<endl;
    return 0;
}