#include <bits/stdc++.h>
using namespace std;
int CoinExchange(int amount, int *denominations, int n)
{
    if (amount == 0)
    {
        return 0;
    }
    int ans = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        if (amount >= denominations[i])
        {
            int sa = CoinExchange(amount - denominations[i], denominations, n);
            if (sa != INT_MAX)
            {
                ans += min(sa + 1, ans);
            }
        }
    }
    return ans;
}
int main()
{
    int denominations[4] = {1, 7, 10};
    int amount;
    cin >> amount;
    cout << CoinExchange(amount, denominations, 3) << endl;
    return 0;
}