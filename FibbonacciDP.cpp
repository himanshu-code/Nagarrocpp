#include <bits/stdc++.h>
using namespace std;
int fibo(int n, int *dp)
{
    if (n == 0 || n == 1)
    {
        dp[n] = n;
        return n;
    }
    if (dp[n] != -1)
    {
        return dp[n];
    }
    return dp[n] = fibo(n - 1, dp) + fibo(n - 2, dp);
}
int bottomUp(int n)
{
    int dp[1000] = {0};
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}
int main()
{
    int n;
    cin >> n;
    int *dp = new int[n + 1];
    for (int i = 0; i <= n; i++)
    {
        dp[i] = -1;
    }
    cout << fibo(n, dp) << endl;
    cout << bottomUp(n) << endl;
    return 0;
}