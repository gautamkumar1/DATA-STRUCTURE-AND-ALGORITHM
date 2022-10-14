#include<bits/stdc++.h>
using namespace std;
/*
    // arr : given array
    // l : starting index of the array i.e 0
    // r : ending index of the array i.e size-1
    // k : find kth smallest element and return using this function
*/
// T(n) : O(n) and S(n) = O(n)
int GetKthSmallestElement(int*arr,int l,int r,int k){
    priority_queue<int> pq;
    int size = r-l+1;
    for (int i = 0; i < size; i++)
    {
        pq.push(arr[i]);
    }
    int count = 0;
    while (count!=size-k)
    {
        pq.pop();
        count++;
    }
    return pq.top();
}

int main(){
    int arr[] = {7 ,10 ,4 ,3 ,20 ,15};
    int size = 6;
    int k = 5;
    int ans = GetKthSmallestElement(arr,0,size-1,k);
    cout<<k<<"rd Smallest Element is : "<<ans<<endl;
    return 0;
}