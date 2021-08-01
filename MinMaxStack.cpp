#include <bits/stdc++.h>
using namespace std;
class MinMaxstack
{
    vector<int> stack;
    vector<int> minstack;
    vector<int> maxstack;

public:
    void push(int data)
    {
        int curr_min = data;
        int curr_max = data;
        if (!empty())
        {
            curr_min = min(curr_min, minstack[minstack.size() - 1]);
        }
        if (!empty())
        {
            curr_max = max(curr_max, maxstack[maxstack.size() - 1]);
        }
        stack.push_back(data);
        minstack.push_back(curr_min);
        maxstack.push_back(curr_max);
    }
    void pop()
    {
        stack.pop_back();
        minstack.pop_back();
        maxstack.pop_back();
    }
    int top()
    {
        return stack[stack.size() - 1];
    }
    int getMin()
    {
        return minstack[minstack.size() - 1];
    }
    int getMax()
    {
        return maxstack[maxstack.size() - 1];
    }
    bool empty()
    {
        return stack.size() == 0;
    }
};
int main()
{
    MinMaxstack s;
    int n;
    cin >> n;
    int x;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        s.push(x);
    }
    cout << s.getMin() << endl;
    cout << s.getMax() << endl;
    cout << s.top() << endl;
    s.pop();
    cout << s.getMin() << endl;
    cout << s.getMax() << endl;
}