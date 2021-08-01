#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
void RotateString(string &s)
{
    s = s.substr(1) + s[0];
}
void RotateString1(string &s, int k, int len)
{
    s += s;
    s = s.substr(k, len);
}
int main()
{
    string s = "Hello lol wor aaa";
    int k = 3;
    vector<string> v;
    char a[100005];
    strcpy(a, s.c_str());

    char *ptr = strtok(a, " ");
    while (ptr != NULL)
    {
        string x(ptr);
        v.push_back(x);
        ptr = strtok(NULL, " ");
    }
    vector<string> v1(v);
    for (int i = 0; i < v1.size(); i++)
    {
        RotateString1(v[i], k % v[i].length(), v[i].length());
    }
    int ans = 0;
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] == v1[i])
        {
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}