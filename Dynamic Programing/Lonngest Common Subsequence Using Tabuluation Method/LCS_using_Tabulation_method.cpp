#include <bits/stdc++.h>
using namespace std;
/*
Algorithm:
step 1: Compute m and n
m -> length(string 1);
n -> length(string 2);
step 2: Inialize Boundary By zero
for(i-> 1 to i<=m)
    lcs_table[i][0] = 0
for(j-> 1 to <=m)
    lcs_table[0][j] = 0
step 3 : Compute matrix
for(i-> 1 to i<=m)
    for(j->1 to j<=n)
        do if(string1[i] == string2[j])
            lcs_table[i][j] = lcs_table[i-1][j-1]+1
            else
                lcs[i][j] = max(lcs_table[i-1][j],lcs_table[i][j-1])
// Step 4 : Compute LCS Length
LCS_length = lcs_table[m][n]
*/

int longestCommonSubsequence(string text1, string text2)
{
    int m = text1.length();
    int n = text2.length();
    int dp[m + 1][n + 1];
    for (int i = 0; i <= m; i++)
    {
        dp[i][0] = 0;
    }
    for (int j = 0; j <= n; j++)
    {
        dp[0][j] = 0;
    }
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (text1[i - 1] == text2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    // for printing longest common subsequence
    string s;
    int i = n, j = m;
    while (i > 0 && j > 0)
    { // if any of this i and j becomes 0 means one string is empty
        if (text1[i - 1] == text2[j - 1])
        {
            s += text1[i - 1]; // if character matches then add that to result string and move diagonally up
            i--;
            j--;
        }
        else
        {
            if (dp[i][j - 1] > dp[i - 1][j])
                j--; // else find the max of up and right position of dp table and move accordingly to up or left
            else
                i--;
        }
    }
    reverse(s.begin(), s.end()); // reverse the string as we started from last
    cout << s;
    return dp[m][n];
}
int main()
{
    string text1 = "abcde";
    string text2 = "ace";
    int lcsLength = longestCommonSubsequence(text1, text2);
    cout << "The longest common subsequence length is " << lcsLength << endl;
    return 0;
}