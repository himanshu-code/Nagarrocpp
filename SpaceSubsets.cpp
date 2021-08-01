#include <bits/stdc++.h>
using namespace std;
void generateSpaceSubsets(char *inp, char *out, int i, int j)
{
    if (inp[i] == '\0')
    {
        out[j] = '\0';
        cout << out << endl;
        return;
    }
    out[j] = ' ';
    out[j + 1] = inp[i];
    generateSpaceSubsets(inp, out, i + 1, j + 2);

    out[j] = inp[i];
    generateSpaceSubsets(inp, out, i + 1, j + 1);
    return;
}
int main()
{
    char inp[10];
    cin >> inp;

    char out[20];
    out[0] = inp[0];
    generateSpaceSubsets(inp, out, 1, 1);
    return 0;
}