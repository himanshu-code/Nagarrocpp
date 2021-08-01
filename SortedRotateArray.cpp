#include <bits/stdc++.h>
using namespace std;
int search(int n, int *a, int t)
{
    int s = 0;
    int e = n - 1;
    while (s <= e)
    {
        int m = s + (e - s) / 2;
        if (a[m] == t)
        {
            return m;
        }
        if (a[s] <= a[m])
        {
            if (t >= a[s] && t < a[m])
            {
                e = m - 1;
            }
            else
            {
                s = m + 1;
            }
        }
        else
        {
            if (t <= a[e] && t > a[m])
            {
                s = m + 1;
            }
            else
            {
                e = m - 1;
            }
        }
    }
    return -1;
}
int main()
{
    int n;
    cin >> n;
    int *a = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int t;
    cin >> t;
    cout << search(n, a, t) << endl;
    return 0;
}