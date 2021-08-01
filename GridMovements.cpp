#include <iostream>
using namespace std;
int grid(int i, int j)
{
    if (i == 0 && j == 0)
    {
        return 1;
    }
    if (i < 0 || j < 0)
    {
        return 0;
    }
    return grid(i - 1, j) + grid(i, j - 1);
}
int main()
{
    int i, j;
    cin >> i >> j;
    cout << grid(i, j) << endl;
}