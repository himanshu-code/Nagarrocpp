#include <bits/stdc++.h>
using namespace std;
string say(string str)
{
    string ans = "";
    for (int i = 0; i < str.size(); i++)
    {
        char ch = str[i];
        int count = 1;
        while (i < str.size() - 1 && str[i] == str[i + 1])
        {
            count++;
            i++;
        }
        ans += count + '0';
        ans += ch;
    }
    return ans;
}
string CountAndSay(int n)
{
    if (n == 1)
        return "1";
    return say(CountAndSay(n - 1));
}
int main()
{
    for (int i = 1; i < 10; i++)
    {
        cout << CountAndSay(i) << endl;
    }
    return 0;
}
