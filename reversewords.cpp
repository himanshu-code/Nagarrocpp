#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
int main()
{
    string s;
    s = " Welcome to No Chill Nagar";
    string ans;
    vector<string> v;
    char a[100005];
    strcpy(a, s.c_str());
    cout << a << endl;

    char *ptr = strtok(a, " ");
    cout << ptr << endl;
    while (ptr != NULL)
    {
        cout << ptr << endl;
        string x(ptr);
        v.push_back(x);
        ptr = strtok(NULL, " ");
    }
    int i = 0, j = v.size() - 1;
    while (i < j)
    {
        swap(v[i++], v[j--]);
    }
    for (int i = 0; i < v.size(); i++)
    {
        if (i != v.size() - 1)
        {
            ans += v[i] + ' ';
        }
        else
        {
            ans += v[i];
        }
    }
    cout << ans << endl;
    return 0;
}
