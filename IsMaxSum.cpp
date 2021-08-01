#include <bits/stdc++.h>
using namespace std;
int IS_Max2D(vector<int> &nums)
{
    int n = nums.size();
    vector<vector<int>> dp(n, vector<int>(n + 1, -1));
    for (int i = 0; i < n; i++)
    {
        dp[i][n] = 0;
    }
    for (int j = n - 1; j >= 1; j--)
    {
        for (int i = 0; i < j; i++)
        {
            int skip = dp[i][j + 1];
            int take = nums[j] + dp[j][j + 1];
            if (nums[i] >= nums[j])
            {
                dp[i][j] = skip;
            }
            else
            {
                dp[i][j] = max(skip, take);
            }
        }
    }
    return dp[0][1];
}
int IS_Max(vector<int> &nums)
{
    nums.insert(nums.begin(), INT_MIN);
    return IS_Max2D(nums);
}
int main()
{
    vector<int> nums{10, 5, 4, 3};
    cout << IS_Max(nums);
}