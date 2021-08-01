#include <iostream>
using namespace std;
bool isPallindromic(string x)
{
    int i = 0;
    int j = x.length() - 1;
    while (i < j)
    {
        if (x[i] != x[j])
        {
            return false;
        }
        i++;
        j--;
    }
    return true;
}
int main()
{
    string s = "xxabcbax";
    string ans;
    cout << s.substr(1) << endl;
    cout << s.substr(2) << endl;
    cout << s.substr(2, 3) << endl;
    for (int i = 0; i < s.length(); i++)
    {
        for (int j = i; j < s.length(); j++)
        {
            string x;
            for (int k = i; k <= j; k++)
            {
                x.push_back(s[k]);
            }
            if (isPallindromic(x) == true)
            {
                if (x.length() > ans.length())
                {
                    ans = x;
                }
            }
        }
    }
    cout << "Longest Pallindormic Substring: " << ans << endl;
}