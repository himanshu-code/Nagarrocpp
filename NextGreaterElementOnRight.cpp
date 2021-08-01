#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> nums{4, 6, 3, 2, 5, 9};
    vector<int> out(nums.size());
    stack<int> stack;
    for (int i = nums.size() - 1; i >= 0; i--)
    {
        while (!stack.empty() && nums[stack.top()] <= nums[i])
        {
            stack.pop();
        }
        out[i] = stack.empty() ? -1 : stack.top();
        stack.push(i);
    }
    for (int i = 0; i < out.size(); i++)
    {
        if (out[i] != -1)
        {
            out[i] = nums[out[i]];
        }
        cout << out[i] << " ";
    }
    cout << endl;
    return 0;
}