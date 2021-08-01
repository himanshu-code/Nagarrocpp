#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> A{10, 5, 40};
    vector<int> B{50, 90, 80};
    sort(B.begin(), B.end());
    int minAbsDiff = INT_MAX;
    for (int i = 0; i < A.size(); i++)
    {
        auto lb = lower_bound(B.begin(), B.end(), A[i]);
        if (lb != B.end())
        {
            int j = lb - B.begin();
            minAbsDiff = min(minAbsDiff, abs(A[i] - B[j]));
            if (j > 0)
                minAbsDiff = min(minAbsDiff, abs(A[i] - B[j - 1]));
        }
        else
        {
            minAbsDiff = min(minAbsDiff, abs(A[i] - B[B.size() - 1]));
        }
    }
    cout << minAbsDiff << endl;
    return 0;
}