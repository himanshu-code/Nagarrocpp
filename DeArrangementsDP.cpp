#include <bits/stdc++.h>
using namespace std;
int countDerangements(int n)
{
    if (n == 1)
        return 0;
    if (n == 2)
        return 1;

    return (n - 1) * (countDerangements(n - 1) + countDerangements(n - 2));
}
int countDearrangementsTopDown(int n, int *memo)
{
    if (n == 1)
        return 0;
    if (n == 2)
        return 1;

    if (memo[n] != -1)
    {
        return memo[n];
    }
    return memo[n] = (n - 1) * (countDearrangementsTopDown(n - 1, memo) + countDearrangementsTopDown(n - 2, memo));
}
int countDearrangementsBottomUp(int n)
{
    if (n == 1)
        return 0;
    if (n == 2)
        return 1;
    int *dp = new int[n + 1];
    dp[1] = 0;
    dp[2] = 1;

    for (int i = 3; i <= n; i++)
    {
        dp[i] = (i - 1) * (dp[i - 1] + dp[i - 2]);
    }
    return dp[n];
}
int countDearrangementsBottomUpSpaceOptimised(int n)
{
    if (n == 1)
        return 0;
    if (n == 2)
        return 1;
    int first = 0;
    int second = 1;
    for (int i = 3; i <= n; i++)
    {
        int third = (i - 1) * (second + first);
        first = second;
        second = third;
    }
    return second;
}
int main()
{
    int n;
    cin >> n;
    cout << countDerangements(n) << endl;
    int *memo = new int[n + 1];
    for (int i = 0; i <= n; i++)
    {
        memo[i] = -1;
    }
    cout << countDearrangementsTopDown(n, memo) << endl;
    cout << countDearrangementsBottomUp(n) << endl;
    cout << countDearrangementsBottomUpSpaceOptimised(n) << endl;
    return 0;
}