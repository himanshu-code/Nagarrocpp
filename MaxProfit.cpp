#include <bits/stdc++.h>
using namespace std;
int maxProfit(int *nums, int n, int i)
{
    if (i >= n)
        return 0;

    int x = maxProfit(nums, n, i + 2);
    int y = maxProfit(nums, n, i + 1);
    return max(nums[i] + x, y);
}
int maxProfitTopDown(int *nums, int n, int i, vector<int> &memo)
{
    if (i >= n)
        return 0;
    if (memo[i] != -1)
        return memo[i];

    return memo[i] = max(nums[i] + maxProfitTopDown(nums, n, i + 2, memo), maxProfitTopDown(nums, n, i + 1, memo));
}

int maxProfitBottomUp(int *nums, int n)
{
    vector<int> dp(n + 1);

    dp[n] = 0;
    dp[n - 1] = nums[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        dp[i] = max(nums[i] + dp[i + 2], dp[i + 1]);
    }
    return dp[0];
}
int maxProfitBottomUpSpaceOptimised(int *nums, int n)
{
    int first = 0;
    int second = nums[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        int third = max(nums[i] + first, second);
        first = second;
        second = third;
    }
    return second;
}
int main()
{
    int n;
    cin >> n;
    int *nums = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    cout << maxProfit(nums, n, 0) << endl;
    vector<int> memo(n, -1);
    cout << maxProfitTopDown(nums, n, 0, memo) << endl;
    cout << maxProfitBottomUp(nums, n) << endl;
    cout << maxProfitBottomUpSpaceOptimised(nums, n) << endl;
    return 0;
}