#include <bits/stdc++.h>
using namespace std;
vector<int> getRepresentation(string &s)
{
    vector<int> repr(23, 0);
    for (char ch : s)
    {
        repr[ch - 'a']++;
    }
    return repr;
}
int main()
{
    string s("anagram");
    string t("nagaram");
    vector<int> sRepr = getRepresentation(s);
    vector<int> tRepr = getRepresentation(t);
    cout << (sRepr == tRepr) << endl;
    return 0;
}