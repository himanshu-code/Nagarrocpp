#include <bits/stdc++.h>
using namespace std;
int lengthOfLongestZeroSumSubarray(vector<int> &v)
{
    int prefixSum = 0;
    int max_len = 0;
    unordered_map<int, int> map;
    for (int j = 0; j < v.size(); j++)
    {
        prefixSum += v[j];
        if (prefixSum == 0)
        {
            max_len = max(max_len, j + 1);
        }
        if (map.find(prefixSum) != map.end())
        {
            int i = map[prefixSum];
            max_len = max(max_len, j - 1);
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
    vector<int> v{-3, 2, 3, 1, 6};
    cout << lengthOfLongestZeroSumSubarray(v) << endl;
    return 0;
}