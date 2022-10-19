/*
Examples:

Input : arr[] = {2, 5, -1, 7, -3, -1, -2}
        K = 4
Output : 18
Explanation : Subarrays of size 4 are :
     {2, 5, -1, 7},   min + max = -1 + 7 = 6
     {5, -1, 7, -3},  min + max = -3 + 7 = 4
     {-1, 7, -3, -1}, min + max = -3 + 7 = 4
     {7, -3, -1, -2}, min + max = -3 + 7 = 4

*/

#include <bits/stdc++.h>
using namespace std;

int sumOfMin_and_max_element(vector<int> &arr, int n, int k)
{
    deque<int> maxi(k);
    deque<int> mini(k);

    // Addition of first k size window

    for (int i = 0; i < k; i++)
    {

        while (!maxi.empty() && arr[maxi.back()] <= arr[i])
            maxi.pop_back();

        while (!mini.empty() && arr[mini.back()] >= arr[i])
            mini.pop_back();

        maxi.push_back(i);
        mini.push_back(i);
    }
    int ans = 0;

    ans += arr[maxi.front()] + arr[mini.front()];

    // remaining windows ko process karlo
    for (int i = k; i < n; i++)
    {

        // next window

        // removal
        while (!maxi.empty() && i - maxi.front() >= k)
        {
            maxi.pop_front();
        }

        while (!mini.empty() && i - mini.front() >= k)
        {
            mini.pop_front();
        }

        // addition

        while (!maxi.empty() && arr[maxi.back()] <= arr[i])
            maxi.pop_back();

        while (!mini.empty() && arr[mini.back()] >= arr[i])
            mini.pop_back();

        maxi.push_back(i);
        mini.push_back(i);

        ans += arr[maxi.front()] + arr[mini.front()];
    }
    return ans;
}

int main()
{
    vector<int> arr = {2, 5, -1, 7, -3, -1, -2};
    int n = arr.size();
    int k = 3;
    int ans = sumOfMin_and_max_element(arr, n, k);
    cout << ans << endl;
    return 0;
}