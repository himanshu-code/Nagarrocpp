#include <iostream>
using namespace std;
int chessElephant(int i, int j)
{
    if (i == 0 and j == 0)
    {
        return 1;
    }
    int ans = 0;
    for (int k = 0; k < i; k++)
    {
        ans += chessElephant(k, j);
    }
    for (int k = 0; k < j; k++)
    {
        ans += chessElephant(i, k);
    }
    return ans;
}
int main()
{
    int n, m;
    cin >> n >> m;
    cout << chessElephant(n, m) << endl;
    return 0;
}