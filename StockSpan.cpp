#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> price(n);
    for (int i = 0; i < n; i++)
    {
        cin >> price[i];
    }
    stack<int> stack;
    vector<int> out(n);
    for (int i = 0; i < price.size(); i++)
    {
        while (!stack.empty() and price[stack.top()] <= price[i])
        {
            stack.pop();
        }
        out[i] = stack.empty() ? i + 1 : i - stack.top();
        stack.push(i);
    }
    for (int i = 0; i < out.size(); i++)
    {
        cout << out[i] << " ";
    }
    cout << "END";
    return 0;
}