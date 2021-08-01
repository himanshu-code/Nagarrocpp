#include <bits/stdc++.h>
using namespace std;
int findShortestSubArray(vector<int> &nums)
{
    int degree = 0;
    unordered_map<int, pair<int, pair<int, int>>> map;
    for (int i = 0; i < nums.size(); i++)
    {
        if (map.find(nums[i]) == map.end())
        {
            map[nums[i]].first = 1;
            map[nums[i]].second.first = i;
            map[nums[i]].second.second = i;
        }
        else
        {
            map[nums[i]].first++;
            map[nums[i]].second.second = i;
        }
        degree = max(degree, map[nums[i]].first);
    }
    int minLen = nums.size();
    for (auto p : map)
    {
        if (p.second.first == degree)
        {
            minLen = min(minLen, p.second.second.second - p.second.second.first + 1);
        }
    }
    return minLen;
}
int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    cout << findShortestSubArray(nums) << endl;
}