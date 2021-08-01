#include <bits/stdc++.h>
using namespace std;

int countPathsTL2BR(int i, int j, int n, int m) //TopLeftToBottomRight
{
    if (i == n - 1 && j == m - 1)
    {
        return 1;
    }
    if (i == n or j == m)
    {
        return 0;
    }
    int X = countPathsTL2BR(i, i + 1, n, m);
    int Y = countPathsTL2BR(i + 1, j, n, m);
    return X + Y;
}
int countPathsBR2TL(int n, int m) //BottomRightToTopLeft
{
    if (n == 0 && m == 0)
    {
        return 1;
    }
    if (n < 0 or m < 0)
    {
        return 0;
    }
    int X = countPathsBR2TL(n, m - 1);
    int Y = countPathsBR2TL(n - 1, m);
    return X + Y;
}
int main()
{
    int n;
    cin >> n;
    int m;
    cin >> m;

    int count = countPathsBR2TL(n - 1, m - 1);
    cout << count << endl;
    return 0;
}