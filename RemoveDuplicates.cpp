#include <bits/stdc++.h>
using namespace std;
int removeDuplicates(vector<int> &nums)
{
    int i = -1;
    for (int j = 0; j < nums.size(); j++)
    {
        nums[++i] = nums[j];
        while (j < nums.size() && nums[j] == nums[j + 1])
        {
            j++;
        }
    }
    return i + 1;
}
int main()
{
    vector<int> nums{1, 1, 1, 2, 2, 2, 2, 3, 3, 4, 5, 6, 7};
    int len = removeDuplicates(nums);
    for (int i = 0; i < len; i++)
    {
        cout << nums[i] << " ";
    }
    cout << endl;
    return 0;
}