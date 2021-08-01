#include <bits/stdc++.h>
using namespace std;
bool zeroSumSubarray(vector<int> &v)
{
    int prefixSum = 0;
    unordered_set<int> set;
    for (int i = 0; i < v.size(); i++)
    {
        prefixSum += v[i];
        if (prefixSum == 0 || set.find(prefixSum) != set.end())
        {
            return true;
        }
        set.insert(prefixSum);
    }
    return false;
}
int main()
{
    vector<int> v{-3, 2, 3, 1, 6};
    cout << zeroSumSubarray(v) << endl;
    return 0;
}