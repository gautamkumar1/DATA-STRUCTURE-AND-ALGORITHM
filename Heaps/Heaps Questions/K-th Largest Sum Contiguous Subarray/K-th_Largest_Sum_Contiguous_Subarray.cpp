#include<bits/stdc++.h>
using namespace std;

/*
N = 3
K = 2
Arr = {3,2,1}
Output:
5
Explanation:
The different subarray sums we can get from the array
are = {6,5,3,2,1}. Where 5 is the 2nd largest.
*/

// Approach 1 
// T(n) : O(n^2*klogn) andd S(N) : O(n2*k)
int kthLargest_Approach1(vector<int>&arr,int n,int k){
    vector<int> ans; // storeing all sum of subarray
    for(int i=0; i<n; i++){
        int sum = 0;
        for(int j=i; j<n; j++){
            sum+=arr[j];
            ans.push_back(sum);
        }
    }
    sort(ans.begin(),ans.end());
    return ans[ans.size()-k];
}
// Approach 2 Using Min-Heap
// T(n) : O(klongn) and S(N) : O(k)
int kthLargest_approach2(vector<int>&arr,int n,int k){
    priority_queue<int,vector<int>,greater<int> > minHeap;
    for(int i=0; i<n; i++){
        int sum=0;
        for(int j=i; j<n; j++){
            sum+=arr[j];
            if(minHeap.size()<k){
                minHeap.push(sum);
            }
            else{
                if(sum > minHeap.top()){
                    minHeap.pop();
                    minHeap.push(sum);
                }
            }
        }
    }
    return minHeap.top();
}
int main(){
    vector<int> arr = {3,2,1};
    int n = 3;
    int k = 2;
    int ans = kthLargest_approach2(arr,n,k);
    cout<<k<<"th Largest Sum is "<<ans<<endl;
    return 0;
}