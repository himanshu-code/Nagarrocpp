#include <bits/stdc++.h>
using namespace std;
bool isRedundant(string expr)
{
    stack<char> stack;
    for (char ch : expr)
    {
        if (ch == ')')
        {
            bool opFound = false;
            while (stack.top() != '(')
            {
                char top = stack.top();
                stack.pop();
                if (top == '+' || top == '-' || top == '*' || top == '/')
                {
                    opFound = true;
                }
            }
            stack.pop();
            if (!opFound)
                return true;
        }
        else
        {
            stack.push(ch);
        }
    }
    return false;
}
int main()
{
    string expr("(a + b *(c-d))");
    cout << expr << endl;
    expr.erase(remove(expr.begin(), expr.end(), ' '), expr.end());
    cout << expr << endl;
    isRedundant(expr) ? cout << "Yes" << endl : cout << "No" << endl;
    return 0;
}