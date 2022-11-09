/*
Input:
N = 5
Arr[] = {1,2,3,-2,5}
Output:
9
Explanation:
Max subarray sum is 9
of elements (1, 2, 3, -2, 5) which 
is a contiguous subarray.
*/
#include<bits/stdc++.h>
using namespace std;
int maxSubarrySum(vector<int>&arr,int n){
    // step 1
    int sum = 0;
    int Maxi = INT_MIN;
    for(int i=0; i<n; i++){
        // step 2 : calculate currentsum
        sum+=arr[i];
        // step 3 
        if(sum<0){
            sum = 0;
        }
        // step 4
        Maxi = max(Maxi,sum);
    }
    return Maxi;
}
int main(){
    vector<int> arr = {1,2,3,-2,5};
    int n = arr.size();
    int maxSum = maxSubarrySum(arr,n);
    cout<<"Max Subarray sum is "<<maxSum<<endl;
    return 0;
}