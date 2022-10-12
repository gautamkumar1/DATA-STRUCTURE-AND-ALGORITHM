#include <bits/stdc++.h>
using namespace std;
// Formula for width findng = nextsmaller[i]-prevsmaller-1;
vector<int> nextSmallerValue(vector<int> heights, int n)
{
    stack<int> s;
    s.push(-1);
    vector<int> ans(n);
    for (int i = n - 1; i >= 0; i--)
    {
        int currentValue = heights[i];
        while (s.top() != -1 && heights[s.top()] >= currentValue)
        {
            s.pop();
        }
        ans[i] = s.top();
        s.push(i);
    }
    return ans;
}
vector<int> nextPrevValue(vector<int> heights, int n)
{
    stack<int> s;
    s.push(-1);
    vector<int> ans(n);
    for (int i = 0; i < n; i++)
    {
        int currentValue = heights[i];
        while (s.top() != -1 && heights[s.top()] >= currentValue)
        {
            s.pop();
        }
        ans[i] = s.top();
        s.push(i);
    }
    return ans;
}
int largestRectangleArea(vector<int> &heights)
{
    int n = heights.size();
    vector<int> next(n);
    next = nextSmallerValue(heights, n);
    vector<int> prev(n);
    prev = nextPrevValue(heights, n);
    int area = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        int length = heights[i];
        if (next[i] == -1)
        {
            next[i] = n;
        }
        int width = next[i] - prev[i] - 1;
        int newArea = length * width;
        area = max(area, newArea);
    }
    return area;
}

int main(){
    vector<int> heights = {2,1,5,6,2,3};
    int ans = largestRectangleArea(heights);
    cout<<"largest Rectangle area is "<<ans<<endl;
    return 0;
}