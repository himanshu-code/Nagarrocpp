#include <bits/stdc++.h>
using namespace std;
void nDigitNumberGenerator(int n, char *out, int j, int x)
{
    if (n == 0)
    {
        out[j] = '\0';
        cout << out << endl;
        return;
    }
    for (int i = x; i <= 9; i++)
    {
        out[j] = i + '0';
        nDigitNumberGenerator(n - 1, out, j + 1, i + 1);
    }
}
int main()
{
    int n;
    cin >> n;
    char out[n + 1];

    nDigitNumberGenerator(n, out, 0, 0);
}