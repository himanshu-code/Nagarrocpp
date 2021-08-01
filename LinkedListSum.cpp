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
void printLinkedList(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}
Node *buildLinkedList(int n)
{
    Node *head = NULL;
    int x;
    while (n--)
    {
        cin >> x;
        Node *node = new Node(x);
        if (head == NULL)
        {
            head = node;
        }
        else
        {
            node->next = head;
            head = node;
        }
    }
    return head;
}
Node *add(Node *head1, Node *head2)
{
    Node *head = NULL;
    int carry = 0;

    while (head1 != NULL && head2 != NULL)
    {
        int data = head1->data + head2->data + carry;
        Node *node = new Node(data % 10);
        if (head == NULL)
        {
            head = node;
        }
        else
        {
            node->next = head;
            head = node;
        }
        head1 = head1->next;
        head2 = head2->next;

        carry = data / 10;
    }

    while (head1 != NULL)
    {
        int data = head1->data + carry;

        Node *node = new Node(data % 10);
        node->next = head;
        head = node;
        head1 = head1->next;

        carry = data / 10;
    }
    while (head2 != NULL)
    {
        int data = head2->data + carry;
        Node *node = new Node(data);
        node->next = head;
        head = node;
        head2 = head2->next;
        carry = data / 10;
    }
    if (carry != 0)
    {
        Node *node = new Node(carry);
        node->next = head;
        head = node;
    }
    return head;
}
int main()
{
    int n;
    cin >> n;
    int m;
    cin >> m;
    Node *head1 = buildLinkedList(n);
    Node *head2 = buildLinkedList(m);
    printLinkedList(head1);
    printLinkedList(head2);
    Node *head = add(head1, head2);
    printLinkedList(head);
    return 0;
}