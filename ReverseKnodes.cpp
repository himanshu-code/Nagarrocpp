#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};
Node *buildLinkedList()
{
    int x;
    cin >> x;
    Node *head = new Node(x);
    Node *curr = head;
    while (x != -1)
    {
        cin >> x;

        if (x == -1)
            break;

        Node *n = new Node(x);
        curr->next = n;
        curr = n;
        }
    return head;
}
void printLinkedList(Node *head)
{
    while (head != NULL)
    {
        cout << head->data;
        head = head->next;
        if (head)
            cout << "->";
    }
    cout << endl;
}
Node *Kreverse(Node *head, int k)
{
    if (head == NULL)
    {
        return NULL;
    }
    Node *curr = head;
    Node *next = NULL;
    Node *prev = NULL;
    int cnt = 0;
    while (curr != NULL && cnt != k)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        cnt++;
    }
    head->next = Kreverse(curr, k);
    return prev;
}
int main()
{
    int k;
    cin >> k;
    Node *head = buildLinkedList();

    printLinkedList(head);
    head = Kreverse(head, k);
    printLinkedList(head);
    return 0;
}