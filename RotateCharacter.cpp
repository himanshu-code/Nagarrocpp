#include <iostream>
using namespace std;
int main()
{
    int t;
    cin >> t;
    string s = "abcde";
    int n = s.length();
    int i = 0;
    while (t--)
    {
        char ch;
        int u;
        cin >> ch >> u;
        if (ch == 'r')
        {
            i = (i + u) % n;
        }
        else
        {
            int pos = (i + u - 1) % n;
            cout << s[pos] << endl;
        }
    }
    return 0;
}