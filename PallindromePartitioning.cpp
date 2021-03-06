#include <bits/stdc++.h>
using namespace std;
#define pb push_back
vector<vector<string>> ans;
bool ispallindrome(string &s, int start, int end)
{
    while (start < end)
    {
        if (s[start++] != s[end--])
        {
            return false;
        }
    }
    return true;
}
void solve(string &s, int start, vector<string> &ca)
{
    if (start == s.length())
    {
        ans.pb(ca);
        return;
    }
    for (int end = start; end < s.length(); end++)
    {
        if (ispallindrome(s, start, end))
        {
            string x = s.substr(start, end - start + 1);
            ca.pb(x);
            solve(s, end + 1, ca);
            ca.pop_back();
        }
    }
}
int main()
{
    string s = "aaa";
    vector<string> ca;
    solve(s, 0, ca);

    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << ' ';
        }
        cout << endl;
    }
    return 0;
}