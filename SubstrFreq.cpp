#include <bits/stdc++.h>
using namespace std;
int main()
{
    string txt;
    cin >> txt;
    string pat;
    cin >> pat;

    int N = txt.length();
    int M = pat.length();
    int freq = 0;
    for (int i = 0; i <= N - M; i++)
    {
        int j;
        for (j = 0; j < M; j++)
        {
            if (txt[i + j] != pat[j])
            {
                break;
            }
        }
        if (j == M)
        {
            freq++;
        }
    }
    cout << freq << endl;
    return 0;
}