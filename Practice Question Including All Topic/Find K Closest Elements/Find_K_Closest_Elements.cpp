#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Method - 1 : Uisng Two Pointer approach

vector<int> FindclosestElemet_UsingTwoPoinetr(vector<int> &arr, int k, int x)
{
    int low = 0;
    int high = arr.size() - 1;
    while (high - low >= k)
    {
        // Finding diff , if diff creater than high to low inc
        if (x - arr[low] > arr[high] - x)
        {
            low++;
        }
        else
        {
            high--;
        }
    }
    vector<int> ans;
    // storeing ans
    for (int i = low; i <= high; i++)
    {
        ans.push_back(arr[i]);
    }
    return ans;
}
int lowerbound(vector<int> &arr, int x)
{
    int low = 0;
    int high = arr.size() - 1;
    int ans = high;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] >= x)
        {
            high = mid - 1;
            ans = mid;
        }
        else if (arr[mid] < x)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return ans;
}
// Uisng Binary Search
// T(N) : O(Logn + K) and S(n) : O(k)
vector<int> findClosestElements(vector<int> &arr, int k, int x)
{
    int high = lowerbound(arr, x);
    int low = high - 1;
    while (k--)
    {
        if (low < 0)
        {
            high++;
        }
        else if (high >= arr.size())
        {
            low--;
        }
        else if (x - arr[low] > arr[high] - x)
        {
            high++;
        }
        else
        {
            low--;
        }
    }
    // vector<int> ans;
    // for(int i=low+1; i<high; i++){
    //     ans.push_back(arr[i]);
    // }
    return vector<int>(arr.begin() + low + 1, arr.begin() + high);
}
int main()
{
    vector<int> arr = {12, 16, 22, 30, 35, 39, 42, 45, 48, 50, 53, 55, 56};
    int x = 35;
    int k = 4;
    vector<int> ans = FindclosestElemet_UsingTwoPoinetr(arr, k, x);
    for (auto val : ans)
    {
        cout << val << " ";
    }
    return 0;
}