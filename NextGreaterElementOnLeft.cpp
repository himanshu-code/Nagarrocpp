#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> nums = {8, 2, 7, 4, 3, 6};
    vector<int> out(nums.size());
    stack<int> stack;
    for (int i = 0; i < nums.size(); i++)
    {
        while (!stack.empty() and nums[stack.top()] <= nums[i])
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
            cout << nums[out[i]] << " ";
        }
        else
            cout << -1 << " ";
    }
    cout << endl;
    return 0;
}