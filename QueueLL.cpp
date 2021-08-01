#include <bits/stdc++.h>
using namespace std;
class node
{
public:
    int data;
    node *next;
    node(int d) : data(d), next(NULL) {}
};
class Queue
{
    node *f;
    node *e;
    int cs;

public:
    Queue()
    {
        f = e = NULL;
        cs = 0;
    }

    void push(int data)
    {
        if (f == NULL)
        {
            f = e = new node(data);
            cs++;
            return;
        }
        node *n = new node(data);
        e->next = n;
        e = n;
        cs++;
    }
    void pop()
    {
        if (f == NULL)
        {
            cout << "Queue Underflow" << endl;
            return;
        }
        else if (f->next == NULL)
        {
            delete f;
            f = e = NULL;
            cs--;
            return;
        }
        node *temp = f;
        f = f->next;
        delete temp;
        cs--;
    }
    int front()
    {
        return f->data;
    }
    bool empty()
    {
        return cs == 0;
    }
    int size()
    {
        return cs;
    }
};
void printQueue(Queue q)
{
    int size_q = q.size();
    while (size_q--)
    {
        int frontElement = q.front();
        cout << frontElement << " ";
        q.pop();
        q.push(frontElement);
    }
    cout << endl;
}
int main()
{
    Queue q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(6);
    q.push(7);
    q.push(8);

    printQueue(q);
    printQueue(q);
}