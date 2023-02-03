/*
Input:
n = 5
arr[] = {4, 2, 7, 6, 9}
Output:
62
Explanation:
First, connect ropes 4 and 2, which makes
the array {6,7,6,9}. Cost of
this operation 4+2 = 6. Next, add ropes
6 and 6, which results in {12,7,9}.
Cost of this operation 6+6 = 12.
Then, add 7 and 9, which makes the array {12,16}.
Cost of this operation 7+9 = 16. And
finally, add these two which gives {28}.
Hence, the total cost is 6 + 12 + 16 +
28 = 62.
*/

#include <bits/stdc++.h>
using namespace std;
long long minCost(long long arr[], long long n)
{
    priority_queue<long long int, vector<long long int>, greater<long long int>> pq;
    for (long long int i = 0; i < n; i++)
    {
        pq.push(arr[i]);
    }
    long long int cost = 0;
    while (pq.size() > 1)
    {
        long long int a = pq.top();
        pq.pop();
        long long int b = pq.top();
        pq.pop();
        long long int sum = a + b;
        cost += sum;
        pq.push(sum);
    }
    return cost;
}

int main(){
    long long arr[] =  {4, 2, 7, 6, 9};
    long long n = 5;
    long long cost = minCost(arr,n);
    cout<<"Minimum Cost of ropes is "<<cost<<endl;
    return 0;
}