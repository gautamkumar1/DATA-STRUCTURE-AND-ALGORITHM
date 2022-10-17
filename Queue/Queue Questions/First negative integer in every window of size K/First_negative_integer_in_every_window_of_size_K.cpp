/*

Question Statements: Given an array A[] of size N and a positive integer K, find the first negative integer for each and every window(contiguous subarray) of size K.
Example 1:
Input :
N = 5
A[] = {-8, 2, 3, -6, 10}
K = 2
Output :
-8 0 -6 -6
Explanation :
First negative integer for each window of size k
{-8, 2} = -8
{2, 3} = 0 (does not contain a negative integer)
{3, -6} = -6
{-6, 10} = -6
*/

#include <iostream>
#include <deque>
#include <vector>
using namespace std;

vector<long long> printFirstNegativeInteger(long long int A[], long long int N, long long int K)
{
    vector<long long> ans;
    deque<long long int> dq;
    // Store negative number (index) i to k-1 tak
    for (int i = 0; i < K; i++)
    {
        if (A[i] < 0)
        {
            dq.push_back(i);
        }
    }
    // Step 2 : agar koii negative number hai us index par to usko answer me push krna hai
    if (dq.size() > 0)
    {
        ans.push_back(A[dq.front()]); // Negative Number
    }
    else
    {
        ans.push_back(0);
    }
    // Step 3 : Ek or loop chalan hai jo ki i = k to i to n-1 tak chalega or k windows ka size check karega
    for (int i = K; i < N; i++)
    {
        if (!dq.empty() && i - dq.front() >= K)
        {
            dq.pop_front();
        }
        // Store negative index number
        if (A[i] < 0)
        {
            dq.push_back(i);
        }
        // Repeat Step 2
        if (dq.size() > 0)
        {
            ans.push_back(A[dq.front()]); // Negative Number
        }
        else
        {
            ans.push_back(0);
        }
    }
    return ans;
}


int main(){
    long long int A[] = {-8, 2, 3, -6, 10};
    long long int N = 5;
    long long int K = 2;
    vector<long long> ans = printFirstNegativeInteger(A,N,K);
    for(auto val : ans){
        cout<<val<<" ";
    }
    return 0;
}