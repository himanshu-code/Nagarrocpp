#include <bits/stdc++.h>
using namespace std;
int maxWineProfit(int n, int *wines, int i, int j, int y)
{
    if (i > j)
    {
        return 0;
    }
    int op1 = wines[i] * y + maxWineProfit(n, wines, i + 1, j, y + 1);
    int op2 = wines[j] * y + maxWineProfit(n, wines, i, j - 1, y + 1);
    return max(op1, op2);
}
int maxWineProfitTopDown(int n, int *wines, int i, int j, int y, vector<vector<int>> &memo)
{
    if (i > j)
    {
        return 0;
    }
    if (memo[i][j] != -1)
    {
        return memo[i][j];
    }
    int op1 = wines[i] * y + maxWineProfitTopDown(n, wines, i + 1, j, y + 1, memo);
    int op2 = wines[j] * y + maxWineProfitTopDown(n, wines, i, j - 1, y + 1, memo);

    return memo[i][j] = max(op1, op2);
}
int maxWineProfitBottomUp(int n, int *wines)
{
    vector<vector<int>> dp(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
    {
        dp[i][i] = wines[i] * n;
    }
    int it = 1;
    while (it < n)
    {
        int y = n - it;
        for (int i = 0; i < y; i++)
        {
            int j = it + i;
            int op1 = wines[i] * y + dp[i + 1][j];
            int op2 = wines[j] * y + dp[i][j - 1];
            dp[i][j] = max(op1, op2);
        }
        it++;
    }
    return dp[0][n - 1];
}

int main()
{
    int n;
    cin >> n;
    int *wines = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> wines[i];
    }
    cout << maxWineProfit(n, wines, 0, n - 1, 1) << endl;
    vector<vector<int>> memo(n, vector<int>(n, -1));
    cout << maxWineProfitTopDown(n, wines, 0, n - 1, 1, memo) << endl;
    cout << maxWineProfitBottomUp(n, wines) << endl;
    return 0;
}