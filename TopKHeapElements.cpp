#include <bits/stdc++.h>
using namespace std;
class comparator
{
public:
    int operator()(int a, int b)
    {
        return a > b;
    }
};
void printHeap(priority_queue<int, vector<int>, comparator> h)
{
    while (!h.empty())
    {
        cout << h.top() << " ";
        h.pop();
    }
    cout << endl;
}
int main()
{
    priority_queue<int, vector<int>, comparator> h;
    int data;
    int cs = 0;
    int k = 3;
    while (1)
    {
        cin >> data;
        if (data == -1)
        {
            printHeap(h);
            break;
        }
        else
        {
            if (cs < k)
            {
                h.push(data);
                cs++;
            }
            else
            {
                if (h.top() < data)
                {
                    h.pop();
                    h.push(data);
                }
            }
        }
    }
    return 0;
}