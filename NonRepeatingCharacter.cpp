#include <bits/stdc++.h>
using namespace std;
int main()
{
    queue<char> queue;
    int freqMap[26] = {0};
    char ch;
    cin >> ch;
    while (ch != '.')
    {
        queue.push(ch);
        freqMap[ch - 'a']++;
        while (!queue.empty() and freqMap[queue.front() - 'a'] > 1)
        {
            queue.pop();
        }
        if (queue.empty())
        {
            cout << -1 << " ";
        }
        else
            cout << queue.front();
        cin >> ch;
    }
    return 0;
}