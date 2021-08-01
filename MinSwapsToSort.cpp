#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int a[] = {8, 4, 5, 2, 3, 1};
    int n = sizeof(a) / sizeof(int);
    pair<int, int> p[1000];
    for (int i = 0; i < n; i++)
    {
        p[i].first = a[i];
        p[i].second = i;
    }
    for (int i = 0; i < n; i++)
    {
        cout << "(" << p[i].first << "," << p[i].second << ")";
    }
    cout << endl;
    sort(p, p + n);
    for (int i = 0; i < n; i++)
    {
        cout << "(" << p[i].first << "," << p[i].second << ")";
    }
    cout << endl;

    bool visited[1000] = {0};
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (visited[i] == true || p[i].second == i)
        {
            continue;
        }
        int no = 0;
        int index = i;
        while (visited[index] == false)
        {
            no++;
            visited[index] = true;
            index = p[index].second;
        }
        if (no > 1)
        {
            ans += no - 1;
        }
    }
    cout << ans << endl;
    return 0;
}