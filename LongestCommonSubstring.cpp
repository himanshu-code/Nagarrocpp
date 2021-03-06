#include <bits/stdc++.h>
using namespace std;
int LCS(string &s1, string &s2, int i, int j)
{
    if (i == s1.length() or j == s2.length())
    {
        return 0;
    }
    if (s1[i] == s2[j])
    {
        return 1 + LCS(s1, s2, i + 1, j + 1);
    }
    return max(LCS(s1, s2, i + 1, j), LCS(s1, s2, i, j + 1));
}
int LCSTopDown(string &s1, string &s2, int i, int j, vector<vector<int>> &memo)
{
    if (i == s1.length() or j == s2.length())
        return 0;

    if (memo[i][j] != -1)
        return memo[i][j];

    if (s1[i] == s2[j])
        return memo[i][j] = 1 + LCSTopDown(s1, s2, i + 1, j + 1, memo);

    return memo[i][j] = max(LCSTopDown(s1, s2, i + 1, j, memo), LCSTopDown(s1, s2, i, j + 1, memo));
}
int LCSBottomUp(string &s1, string &s2)
{
    int n1 = s1.length();
    int n2 = s2.length();

    vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));
    for (int i = n1 - 1; i >= 0; i--)
    {
        for (int j = n2 - 1; j >= 0; j--)
        {
            if (s1[i] == s2[j])
            {
                dp[i][j] = 1 + dp[i + 1][j + 1];
            }
            else
                dp[i][j] = max(dp[i + 1][j], dp[i][j + 1]);
        }
    }
    return dp[0][0];
}
int main()
{
    string s1;
    cin >> s1;
    string s2;
    cin >> s2;
    cout << LCS(s1, s2, 0, 0) << endl;
    vector<vector<int>> memo(s1.length(), vector<int>(s2.length(), -1));
    cout << LCSTopDown(s1, s2, 0, 0, memo) << endl;
    cout << LCSBottomUp(s1, s2) << endl;
}