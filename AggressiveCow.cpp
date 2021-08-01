#include <bits/stdc++.h>
using namespace std;
bool canPlaceCows(int N, int C, int *stalls, int m)
{
    int prevCowPosition = stalls[0];
    int numCowsPlaced = 1;
    for (int i = 1; i < N; i++)
    {
        if (stalls[i] - prevCowPosition >= m)
        {
            prevCowPosition = stalls[i];
            numCowsPlaced++;
            if (numCowsPlaced == C)
            {
                return true;
            }
        }
    }
    return false;
}
int findMaxMinDist(int N, int C, int *stalls)
{
    int s = 0;
    int e = INT_MAX;
    int ans;
    while (s <= e)
    {
        int m = s + (e - s) / 2;
        if (canPlaceCows(N, C, stalls, m))
        {
            ans = m;
            s = m + 1;
        }
        else
        {
            e = m - 1;
        }
    }
    return ans;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;
        int C;
        cin >> C;
        int *stalls = new int[N];
        for (int i = 0; i < N; i++)
        {
            cin >> stalls[i];
        }
        sort(stalls, stalls + N);
        cout << findMaxMinDist(N, C, stalls) << endl;
    }
    return 0;
}