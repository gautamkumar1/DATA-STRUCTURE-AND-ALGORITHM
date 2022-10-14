#include <iostream>
#include <stack>
#include <vector>
using namespace std;

bool isKnows(vector<vector<int>> &arr, int a, int b)
{
    if (arr[a][b] == 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
// T(n) : O(n) and S(n) = O(n)
int GetCelebrityNumber(vector<vector<int>> &arr, int size)
{
    // Step 1 : push all elemnt in size-1 tak
    stack<int> st;
    for (int i = 0; i < size; i++)
    {
        st.push(i);
    }
    while (st.size() > 1)
    {
        // Step 2 : pop two top value
        int a = st.top();
        st.pop();
        int b = st.top();
        st.pop();
        // a knows b then discard a and b push in stack
        if (isKnows(arr, a, b))
        {
            st.push(b);
        }
        // b knows  a then discard b and a push in stack
        else
        {
            st.push(a);
        }
    }
    int celebrityNumber = st.top(); // outside loop we get know celebrity , or woh stack ka top value hoga
                                    // now we verifiying celebrity so if all row are zero and all colmuns are 1 expect digonal element then it is corrent celebritiy number
    int zeroCount = 0;
    for (int i = 0; i < size; i++)
    {
        if (arr[celebrityNumber][i] == 0)
        {
            zeroCount++;
        }
    }
    if (zeroCount != size)
    {
        return -1;
    }
    int oneCount = 0;
    for (int i = 0; i < size; i++)
    {
        if (arr[i][celebrityNumber] == 1)
        {
            oneCount++;
        }
    }
    if (oneCount != size - 1)
    {
        return -1;
    }
    return celebrityNumber;
}

int main()
{
    vector<vector<int>> arr = {{0, 1, 0},
                               {0, 0, 0},
                               {0, 1, 0}};
    int size = arr.size();
    int celebrityNumber = GetCelebrityNumber(arr, size);
    cout << "Celebrity Number is : " << celebrityNumber << endl;
    return 0;
}