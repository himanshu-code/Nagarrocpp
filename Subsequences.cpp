#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
vector<string> v;

void subsequences(char *inp, int i, char *out, int j)
{
    if (inp[i] == '\0')
    {
        out[j] = '\0';
        cout << out << endl;
        return;
    }
    out[j] = inp[i];
    subsequences(inp, i + 1, out, j + 1);
    subsequences(inp, i + 1, out, j);
}
int main()
{
    char inp[100], out[100];
    cin >> inp;
    subsequences(inp, 0, out, 0);
    cout << "printing Vector" << endl;
}