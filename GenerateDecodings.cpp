#include <bits/stdc++.h>
using namespace std;

void generateDecodings(char *inp, char *out, int i, int j)
{
    if (inp[i] == '\0')
    {
        out[j] = '\0';
        cout << out << endl;
        return;
    }

    int digit = inp[i] - '0';

    if (digit != 0)
    {
        char ch = digit + 'A' - 1;
        out[j] = ch;

        generateDecodings(inp, out, i + 1, j + 1);
        if (inp[i + 1] != '\0')
        {
            int next_digit = inp[i + 1] - '0';
            int number = digit * 10 + next_digit;
            if (number <= 26)
            {
                ch = number + 'A' - 1;
                out[j] = ch;
                generateDecodings(inp, out, i + 2, j + 1);
            }
        }
    }
    return;
}
int main()
{
    char inp[100];
    cin >> inp;

    char out[100];
    generateDecodings(inp, out, 0, 0);
    return 0;
}