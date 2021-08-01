#include <iostream>
using namespace std;
int main()
{
    string s = "aaaaa";
    string s_copy = s;
    int len = s.length();
    s += s;
    for (int i = 1; i < len; i++)
    {
        string x = s.substr(i, len);
        if (x == s_copy)
        {
            cout << "Rotate it " << i << " times" << endl;
            break;
        }
    }
    return 0;
}