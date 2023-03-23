#include <iostream>
#include <numeric>
using namespace std;
bool isPossibleSolution(int A[], int N, int M, int mid)
{
    int pagesSum = 0;
    int student = 1;
    for (int i = 0; i < N; i++)
    {
        // element greater than mid
        if (A[i] > mid)
            return false;
        if (pagesSum + A[i] > mid)
        {
            student++;
            pagesSum = A[i];
            if (student > M)
            {
                return false;
            }
        }
        else
        {
            pagesSum += A[i];
        }
    }
    return true;
}
int findPages(int A[], int N, int M)
{
    // Number students Greater than N
    if (M > N)
        return -1;
    int low = 0;
    int high = accumulate(A, A + N, 0);
    int ans = -1;
    while (low <= high)
    {
        int mid = (high + low) >> 1;
        if (isPossibleSolution(A, N, M, mid))
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return ans;
}
int main()
{
    int N = 4;
    int A[] = {12, 34, 67, 90}; 
    int M = 2;
    cout<<"Minimum Number Of Book Allocation is "<<findPages(A,N,M)<<endl;
    return 0;
}