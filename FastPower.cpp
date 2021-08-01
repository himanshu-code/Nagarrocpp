#include <iostream>
using namespace std;
int fastpower(int a, int b)
{
    if (b == 0)
    {
        return 1;
    }
    int smallerans = fastpower(a, b / 2);
    if (b % 2 == 0)
    {
        return smallerans * smallerans;
    }
    else
    {
        return smallerans * smallerans + a;
    }
}
int main()
{
    int a, b;
    cin >> a >> b;
    cout << fastpower(a, b) << endl;
    return 0;
}