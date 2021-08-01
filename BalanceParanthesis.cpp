#include <bits/stdc++.h>
using namespace std;

bool isBalanced(char *a)
{
    stack<char> s;
    for (int i = 0; a[i]; i++)
    {
        char ch = a[i];
        switch (ch)
        {
        case '(':
        case '{':
        case '[':
            s.push(ch);
            break;
        case ')':
            if (s.empty() == true or s.top() != '(')
            {
                return false;
            }
            s.pop();
            break;

        case '}':
            if (s.empty() == true || s.top() != '{')
            {
                return false;
            }
            s.pop();
            break;

        case ']':
            if (s.empty() == true || s.top() != '[')
            {
                return false;
            }
            s.pop();
            break;
        }
    }
    if (s.empty() == true)
    {
        return true;
    }
    else
    {
        return false;
    }
}
int main()
{
    char a[] = "{{a+b*(c+d)+[e+f]*x}}";
    if (isBalanced(a))
    {
        cout << "Balanced " << endl;
    }
    else
    {
        cout << "Not Balanced" << endl;
    }
    return 0;
}