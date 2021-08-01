#include <bits/stdc++.h>
using namespace std;
vector<string> v;

void subsequences(char *inp, int i, int mv)
{
    if (i == mv)
    {
        return;
    }
    int j = i;
    int index = 0;
    string s;
    bool isThereCharacterInS = false;
    while (j != 0)
    {
        if ((j & 1) == 1)
        {
            s.push_back(inp[index]);
            isThereCharacterInS = true;
        }
        j = j >> 1;
        index++;
    }
    v.push_back(s);
    subsequences(inp, i + 1, mv);
}
void subsequences1(char *inp)
{
    int n = pow(2, strlen(inp));
    for (int i = 0; i < n; i++)
    {
        int j = i;
        int index;
        while (j != 0)
        {
            if ((j & 1) == 1)
            {
                cout << inp[index];
            }
            j = j >> 1;
        }
        cout << endl;
    }
}
int main()
{
    char inp[4] = "abc";
    int max_val = pow(2, strlen(inp));
    subsequences(inp, 0, max_val);
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << endl;
    }
    return 0;
}