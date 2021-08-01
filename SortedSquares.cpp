#include <bits/stdc++.h>
using namespace std;
vector<int> sortedSquares(vector<int> &nums)
{
    int i = 0;
    int j = nums.size() - 1;
    vector<int> out(nums.size());
    int k = out.size() - 1;
    while (i <= j)
    {
        if (abs(nums[i]) > abs(nums[j]))
        {
            out[k] = nums[i] * nums[i];
            i++;
        }
        else
        {
            out[k] = nums[j] * nums[j];
            j--;
        }
        k--;
    }
    return out;
}
int main()
{
    vector<int> nums{-7, -3, 2, 3, 11};
    vector<int> out = sortedSquares(nums);
    for (int x : out)
        cout << x << " ";
    return 0;
}