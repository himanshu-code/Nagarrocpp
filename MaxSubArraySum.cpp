#include <iostream>
#include <climits>
using namespace std;
int main()
{

    int t;
    cin >> t;

    int n;
    while (t--)
    {
        int cs = 0, ms = INT_MIN, n, arr[100005], i;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            cs = cs + arr[i];
            if (cs < 0)
            {
                cs = 0;
            }
            ms = max(ms, cs);
        }
        cout << ms << endl;
    }

    return 0;
}