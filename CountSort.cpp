#include <iostream>
#include <climits>
using namespace std;
int main()
{

    int n, i, maxi = INT_MIN;
    cin >> n;
    int a[1000000];
    for (i = 0; i < n; i++)
    {
        cin >> a[i];
        if (a[i] > maxi)
        {
            maxi = a[i];
        }
    }

    int *freq = new int[maxi + 1];

    for (i = 0; i <= maxi; ++i)
    {
        freq[i] = 0;
    }

    for (i = 0; i < n; i++)
    {
        freq[a[i]]++;
    }

    for (i = 0; i <= maxi; i++)
    {
        while (freq[i] != 0)
        {
            cout << i << " ";
            freq[i]--;
        }
    }
    cout << endl;

    return 0;
}