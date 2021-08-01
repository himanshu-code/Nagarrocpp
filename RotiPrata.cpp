#include <bits/stdc++.h>
using namespace std;
int numPratasByACook(int rank, int timeLimit)
{
    int cnt = 0;
    int i = 1;
    int time = 0;
    while (time <= timeLimit)
    {
        time += i * rank;
        if (time > timeLimit)
        {
            break;
        }
        cnt++;
        i++;
    }
    return cnt;
}
int numPrataCooked(int L, int *ranks, int timeLimit)
{
    int numPratas = 0;
    for (int i = 0; i < L; i++)
    {
        numPratas += numPratasByACook(ranks[i], timeLimit);
    }
    return numPratas;
}
int minTimetoGetOrder(int P, int L, int *ranks)
{
    int s = 0;
    int e = INT_MAX;
    int ans;
    while (s <= e)
    {
        int m = s + (e - s) / 2;
        if (numPrataCooked(L, ranks, m) >= P)
        {
            ans = m;
            e = m - 1;
        }
        else
        {
            s = m + 1;
        }
    }
    return ans;
}
int main()
{
    int t;
    cin >> t;
    int P, L;
    while (t--)
    {
        cin >> P >> L;
        int *ranks = new int[L];
        for (int i = 0; i < L; i++)
        {
            cin >> ranks[i];
        }
        cout << minTimetoGetOrder(P, L, ranks) << endl;
    }
    return 0;
}