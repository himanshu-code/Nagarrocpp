#include <bits/stdc++.h>
using namespace std;
int maxProfit(int n, int *prices)
{
    if (n == 0)
    {
        return 0;
    }
    int ans = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        ans = max(ans, prices[i] + maxProfit(n - (i + 1), prices));
    }
    return ans;
}
int maxProfitTopDown(int n, int *prices, vector<int> &memo)
{
    if (n == 0)
    {
        return 0;
    }
    if (memo[n] != -1)
    {
        return memo[n];
    }
    int ans = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        ans = max(ans, prices[i] + maxProfitTopDown(n - (i + 1), prices, memo));
    }
    return memo[n] = ans;
}
int maxProfitBottomUp(int n, int *prices)
{
    vector<int> dp(n + 1, -1);
    dp[0] = 0;

    for (int j = 1; j <= n; j++)
    {
        for (int i = 0; i < j; i++)
        {
            dp[j] = max(dp[j], prices[i] + dp[j - (i + 1)]);
        }
    }
    return dp[n];
}
int main()
{
    int n;
    cin >> n;
    int *prices = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> prices[i];
    }
    cout << maxProfit(n, prices) << endl;
    vector<int> memo(n + 1, -1);
    cout << maxProfitTopDown(n, prices, memo) << endl;
    cout << maxProfitBottomUp(n, prices) << endl;
    return 0;
}