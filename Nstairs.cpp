#include <iostream>
using namespace std;
int stairs(int n)
{
    if (n == 0)
    {
        return 1;
    }
    if (n < 0)
    {
        return 0;
    }
    return stairs(n - 1) + stairs(n - 2) + stairs(n - 3);
}
int fun(int n, int k)
{
    if (n == 0)
    {
        return 1;
    }
    if (n < 0)
    {
        return 0;
    }
    int ans = 0;
    for (int i = 1; i <= k; i++)
    {
        ans += fun(n - i, k);
    }
    return ans;
}
int main()
{
    int n;
    cin >> n;
    cout << stairs(n) << endl;
    cout << fun(n, 3) << endl;
    return 0;
}