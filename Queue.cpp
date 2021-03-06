#include <bits/stdc++.h>
using namespace std;
class Queue
{
    int *arr;
    int n;
    int cs;
    int f;
    int e;

public:
    Queue(int s = 5)
    {
        arr = new int[s];
        n = s;
        cs = 0;
        f = 0;
        e = n - 1;
    }
    int front()
    {
        return arr[f];
    }
    void push(int data)
    {
        if (cs == n)
        {
            cout << "Queue Overflow" << endl;
            return;
        }
        e = (e + 1) % n;
        arr[e] = data;
        cs++;
    }

    void pop()
    {
        if (cs == 0)
        {
            cout << "Queue Underflow" << endl;
            return;
        }
        f = (f + 1) % n;
        cs--;
    }
    int size()
    {
        return cs;
    }
    bool empty()
    {
        return cs == 0;
    }
};
int main()
{
    Queue q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    while (!q.empty())
    {
        cout << q.front() << endl;
        q.pop();
    }
    return 0;
}