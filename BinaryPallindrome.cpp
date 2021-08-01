#include <bits/stdc++.h>
using namespace std;
bool isKthBitSet(unsigned int x, unsigned int k)
{
    return x & (1 << k);
}
bool isPalindrome(unsigned int x)
{
    unsigned int left = sizeof(unsigned int) * 8 - 1;
    unsigned int right = 0;
    while (left > right)
    {
        if (isKthBitSet(x, left) != isKthBitSet(x, right))
        {
            return false;
        }
        left--;
        right++;
    }
    return true;
}
int main()
{
    unsigned int x = 1 << 31;
    unsigned int y = 1 << 30;
    cout << isPalindrome(x) << endl;
    cout << isPalindrome(y) << endl;
    x += 1;
    y += 2;
    cout << isPalindrome(x) << endl;
    cout << isPalindrome(y) << endl;
}