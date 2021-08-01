#include <bits/stdc++.h>
using namespace std;
int numberOfWaysToTop(int n, int k)
{
    if (n == 0)
    {
        return 1;
    }
    int ways = 0;
    for (int i = 1; i <= k; i++)
    {

        if (n - i >= 0)
        {
            ways += numberOfWaysToTop(n - i, k);
        }
    }
    return ways;
}
int numberOfWaysToTopTopDown(int n, int k, vector<int> &memo)
{
    if (n == 0)
    {
        return 1;
    }
    if (memo[n] != 0)
    {
        return memo[n];
    }
    int ways = 0;
    for (int i = 1; i <= k; i++)
    {
        if (n - i >= 0)
        {
            ways += numberOfWaysToTopTopDown(n - i, k, memo);
        }
    }
    return memo[n] = ways;
}
int numberOfWaysToTopBottomUp(int n, int k)
{
    vector<int> dp(n + 1, 0);
    dp[0] = 1;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= k; j++)
        {
            if (i - j >= 0)
            {
                dp[i] += dp[i - j];
            }
        }
    }
    return dp[n];
}
int numberOfWaysToTopBottomUpSpaceOptimised(int n, int k)
{
    vector<int> dp(n + 1, 0);
    dp[0] = 1;
    dp[1] = 1;

    for (int i = 2; i <= k; i++)
    {
        dp[i] = 2 * dp[i - 1];
    }
    for (int i = k + 1; i <= n; i++)
    {
        dp[i] = 2 * dp[i - 1] - dp[i - k - 1];
    }
    return dp[n];
}
int main()
{
    int n;
    cin >> n;
    int k;
    cin >> k;
    cout << numberOfWaysToTop(n, k) << endl;
    vector<int> memo(n + 1, 0);
    cout << numberOfWaysToTopTopDown(n, k, memo) << endl;
    cout << numberOfWaysToTopBottomUp(n, k) << endl;
    cout << numberOfWaysToTopBottomUpSpaceOptimised(n, k) << endl;
}