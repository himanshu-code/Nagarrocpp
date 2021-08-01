#include <bits/stdc++.h>
using namespace std;
int largestUniqueNumberOne(int n, int *A)
{
    sort(A, A + n, greater<int>());
    for (int i = 0; i < n; i++)
    {
        if (i == n - 1 || A[i] != A[i + 1])
        {
            return A[i];
        }
        else
        {
            while (i < n - 1 && A[i] == A[i + 1])
            {
                i++;
            }
        }
    }
    return -1;
}
int largestUniqueNumberTwo(int n, int *A)
{
    unordered_map<int, int> map;
    for (int i = 0; i < n; i++)
    {
        map[A[i]]++;
    }

    int ans = -1;
    for (auto p : map)
    {
        if (p.second == 1)
        {
            ans = max(ans, p.first);
        }
    }
    return ans;
}
int main()
{
    int n;
    cin >> n;
    int *A = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }
    cout << largestUniqueNumberOne(n, A) << endl;
    cout << largestUniqueNumberTwo(n, A) << endl;
}