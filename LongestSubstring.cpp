#include <bits/stdc++.h>
using namespace std;
bool hasUniQueCharacters(string &s, int i, int j)
{
    int visited[256];
    for (int i = 0; i < 256; i++)
    {
        visited[i] = 0;
    }
    for (int k = i; k <= j; k++)
    {
        if (visited[s[k]])
        {
            return false;
        }
        visited[s[k]] = 1;
    }
    return true;
}
void substr1(string str)
{
    int n = str.length();
    int max_len = 0;
    int left = 0, right = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (hasUniQueCharacters(str, i, j))
            {
                int length = j - i + 1;
                if (length > max_len)
                {
                    max_len = length;
                    left = i;
                    right = j;
                }
            }
        }
    }
    cout << max_len << endl;
    for (int k = left; k <= right; k++)
    {
        cout << str[k] << " ";
    }
    cout << endl;
}
void substr2(string str)
{
    int n = str.length();
    int max_len = 0;
    ;
    int left = 0;
    int right = 0;
    for (int i = 0; i < n; i++)
    {
        int visited[256];
        for (int k = 0; k < 256; k++)
        {
            visited[k] = 0;
        }
        for (int j = i; j < n; j++)
        {
            if (visited[str[j]])
            {
                break;
            }
            else
            {
                int length = j - i + 1;
                if (length > max_len)
                {
                    max_len = length;
                    left = i;
                    right = j;
                }
                visited[str[j]] = 1;
            }
        }
    }
    cout << max_len << endl;
    for (int k = left; k <= right; k++)
    {
        cout << str[k] << " ";
    }
    cout << endl;
}
void substr3(string str)
{
    int visited[256];
    for (int i = 0; i < 256; i++)
    {
        visited[i] = 0;
    }
    visited[str[0]] = 0;
    int cur_len = 1;
    int max_len = 1;

    int n = str.size();

    for (int i = 1; i < n; i++)
    {
        int last_occurence = visited[str[i]];
        if (last_occurence == -1 || last_occurence < i - cur_len)
        {
            cur_len++;
        }
        else
        {
            cur_len = i - last_occurence;
        }
        visited[str[i]] = i;
        max_len = max(max_len, cur_len);
    }
    cout << max_len << endl;
}
int main()
{
    string str;
    cin >> str;
    substr1(str);
    substr2(str);
    substr3(str);
    return 0;
}