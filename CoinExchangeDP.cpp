#include <bits/stdc++.h>
using namespace std;
int coinExchange(int amount, int *deno, int n)
{
    if (amount == 0)
    {
        return 0;
    }
    int ans = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        if (amount >= deno[i])
        {
            int sa = coinExchange(amount - deno[i], deno, n);
            if (sa != INT_MAX)
            {
                ans = min(sa + 1, ans);
            }
        }
    }
    return ans;
}
int topDown(int amount, int *deno, int n, int *dp)
{
    if (amount == 0)
    {
        return dp[amount] = 0;
    }
    if (dp[amount] != -1)
    {
        return dp[amount];
    }
    int ans = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        if (amount >= deno[i])
        {
            int sa = topDown(amount - deno[i], deno, n, dp);
            if (sa != INT_MAX)
            {
                ans = min(sa + 1, ans);
            }
        }
    }
    return dp[amount] = ans;
}
int bottomUp(int amount, int *deno, int m)
{
    int *dp = new int[amount + 1];
    for (int i = 0; i <= amount; i++)
    {
        dp[i] = INT_MAX;
    }

    dp[0] = 0;
    for (int rupay = 1; rupay <= amount; rupay++)
    {
        for (int i = 0; i < m; i++)
        {
            if (rupay >= deno[i])
            {
                dp[rupay] = min(1 + dp[rupay - deno[i]], dp[rupay]);
            }
        }
    }
    for (int i = 0; i < amount; i++)
    {
        cout << dp[i] << " ";
    }
    cout << endl;
    return dp[amount];
}
int main()
{
    int deno[4] = {1, 2, 5, 10};
    int amount;
    cin >> amount;
    int *dp = new int[amount + 1];
    for (int i = 0; i <= amount; i++)
    {
        dp[i] = -1;
    }
    cout << topDown(amount, deno, 4, dp) << endl;
    cout << bottomUp(amount, deno, 4) << endl;
    cout << coinExchange(amount, deno, 4) << endl;
    return 0;
}