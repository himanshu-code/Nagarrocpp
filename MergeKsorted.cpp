#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    vector<vector<int>> v{{1, 4, 8}, {3, 7, 9}, {2, 5, 9}};
    vector<int> out(9);
    int c = 0;
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < v[i].size(); j++)
        {
            out[c++] = v[i][j];
        }
    }
    sort(out.begin(), out.end());
    for (int i = 0; i < 9; i++)
    {
        cout << out[i] << " ";
    }
    cout << endl;
    return 0;
}