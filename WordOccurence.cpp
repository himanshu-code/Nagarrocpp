#include <bits/stdc++.h>
using namespace std;
int main()
{
    string str;
    getline(cin, str);
    string word;
    cin >> word;
    int cnt = 0;
    char *p = strtok((char *)str.c_str(), " ");
    while (p != NULL)
    {
        string token(p);
        if (token == word)
        {
            cnt++;
        }
        p = strtok(NULL, " ");
    }
    cout << cnt << endl;
    return 0;
}