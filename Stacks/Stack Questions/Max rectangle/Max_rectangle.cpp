#include <bits/stdc++.h>
using namespace std;
/*
Input:
n = 4, m = 4
M[][] = {{0 1 1 0},
         {1 1 1 1},
         {1 1 1 1},
         {1 1 0 0}}
Output: 8
Explanation: For the above test case the
matrix will look like
0 1 1 0
1 1 1 1
1 1 1 1
1 1 0 0
the max size rectangle is 
1 1 1 1
1 1 1 1
and area is 4 *2 = 8.
*/
vector<int> nextPrevValue(int *heights, int n)
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
vector<int> nextSmallerValue(int *heights, int n)
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

int largestRectangleArea(int *heights, int n)
{
    // int n = heights.size();
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
// T(n) =  O(n*m) and S(n) = O(m)
int maxArea(int M[][4], int n, int m)
{
    int area = largestRectangleArea(M[0], m);
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {

            if (M[i][j] != 0)
            {
                M[i][j] = M[i][j] + M[i - 1][j];
            }
            else
            {
                M[i][j] = 0;
            }
        }
        int newArea = largestRectangleArea(M[i], m);
        area = max(area, newArea);
    }
    return area;
}


int main(){
    int M[4][4] = {{0 ,1 ,1 ,0},
         {1 ,1 ,1 ,1},
         {1 ,1 ,1 ,1},
         {1 ,1 ,0 ,0}};
    int n = 4;
    int m = 4;
    int maxRectangle = maxArea(M,n,m);
    cout<<"Max Rectangle is : "<<maxRectangle<<endl;
    return 0;
}