#include <bits/stdc++.h>
using namespace std;
int compareVersion(string version1, string version2)
{
    int n1 = version1.length();
    int n2 = version2.length();
    int i = 0;
    int j = 0;
    int rev1 = 0;
    int rev2 = 0;

    while (i < n1 || j < n2)
    {
        while (i < n1 && version1[i] != '.')
        {
            rev1 = rev1 * 10 + (version1[i] - '0');
            i++;
        }
        while (j < n2 && version2[j] != '.')
        {
            rev2 = rev2 * 10 + (version2[j] - '0');
            j++;
        }
        if (rev1 < rev2)
            return -1;
        else if (rev1 > rev2)
            return 1;

        i++;
        j++;
        rev1 = 0;
        rev2 = 0;
    }
    return 0;
}
int main()
{
    string version1("7.5.2.4");
    string version2("7.5.3");

    cout << compareVersion(version1, version2) << endl;
    return 0;
}