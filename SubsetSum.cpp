#include <bits/stdc++.h>
using namespace std;
void generateSubsetSum(int *inp, int n, int i, int sum, multiset<int> &s)
{
    if (i == n)
    {
        cout << "{";
        for (auto it = s.begin(); it != s.end(); it++)
        {
            cout << *it << " ";
        }
        cout << "}= " << sum << endl;
        return;
    }
    s.insert(inp[i]);
    generateSubsetSum(inp, n, i + 1, sum + inp[i], s);

    s.erase(s.lower_bound(inp[i]));
    generateSubsetSum(inp, n, i + 1, sum, s);
}
int main()
{
    int n;
    cin >> n;
    int *inp = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> inp[i];
    }
    multiset<int> s;
    generateSubsetSum(inp, n, 0, 0, s);
}