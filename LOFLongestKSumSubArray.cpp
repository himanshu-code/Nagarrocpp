#include <bits/stdc++.h>
using namespace std;
int lengthOfLongestKSumSubarray(vector<int> &v, int k)
{
    int prefixSum = 0;
    int max_len = 0;
    unordered_map<int, int> map;
    for (int j = 0; j < v.size(); j++)
    {
        prefixSum += v[j];
        if (prefixSum == k)
        {
            max_len = max(max_len, j + 1);
        }
        if (map.find(prefixSum - k) != map.end())
        {
            int i = map[prefixSum - k];
            max_len = max(max_len, j - i);
        }
        else
        {
            map[prefixSum] = j;
        }
    }
    return max_len;
}
int main()
{
    vector<int> v{-3, 2, 3, 1, 6, 2};
    cout << lengthOfLongestKSumSubarray(v, 6) << endl;
    return 0;
}