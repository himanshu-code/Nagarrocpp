#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int W;
    cin >> W;

    vector<int> weights(n);
    for (int i = 0; i < n; i++)
    {
        cin >> weights[i];
    }
    vector<int> prices(n);
    for (int i = 0; i < n; i++)
    {
        cin >> prices[i];
    }
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, -1));
    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = 0;
    }
    for (int j = 0; j <= W; j++)
    {
        dp[n][j] = 0;
    }
    for (int i = n - 1; i >= 0; i--)
    {
        for (int w = 1; w <= W; w++)
        {
            if (weights[i] > w)
            {
                dp[i][w] = dp[i + 1][w];
            }
            else
            {
                dp[i][w] = max(prices[i] + dp[i + 1][w - weights[i]], dp[i + 1][w]);
            }
        }
    }
    cout << dp[0][W] << endl;
    return 0;
}