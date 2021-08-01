#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *right;
    Node *left;
    Node(int d)
    {
        data = d;
        right = left = NULL;
    }
};
Node *InsertInBst(Node *root, int data)
{
    if (root == NULL)
    {
        root = new Node(data);
        return root;
    }
    if (root->data >= data)
    {
        root->left = InsertInBst(root->left, data);
    }
    else
    {
        root->right = InsertInBst(root->right, data);
    }
    return root;
}
Node *createBST()
{
    int data;
    cin >> data;
    Node *root = NULL;
    while (data != -1)
    {
        root = InsertInBst(root, data);
        cin >> data;
    }
    return root;
}

void PreOrder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    PreOrder(root->left);
    PreOrder(root->right);
}
void levelOrder(Node *root)
{
    queue<Node *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        Node *x = q.front();
        q.pop();
        if (x == NULL)
        {
            cout << endl;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << x->data << " ";
            if (x->left)
            {
                q.push(x->left);
            }
            if (x->right)
            {
                q.push(x->right);
            }
        }
    }
}

bool checkBST(Node *root, int l = INT_MIN, int r = INT_MAX)
{
    if (root == NULL)
    {
        return true;
    }
    if (root->data >= 1 and root->data <= r and checkBST(root->left, l, root->data) and checkBST(root->right, root->data, r))
    {
        return true;
    }
    else
    {
        return false;
    }
}
class LinkedList
{
public:
    Node *head, *tail;
    LinkedList()
    {
        head = tail = NULL;
    }
};
LinkedList BSTtoLL(Node *root)
{
    LinkedList l;
    if (root == NULL)
        return l;

    if (root->left == NULL and root->right == NULL)
    {
        l.head = l.tail = root;
    }
    else if (root->left == NULL and root->right != NULL)
    {
        LinkedList right = BSTtoLL(root->right);
        root->right = right.head;
        l.head = root;
        l.tail = root;
    }
    else if (root->left != NULL and root->right != NULL)
    {
        LinkedList left = BSTtoLL(root->left);
        left.tail->right = root;
        l.head = left.head;
        l.tail = root;
    }
    else
    {
        LinkedList left = BSTtoLL(root->left);
        LinkedList right = BSTtoLL(root->right);
        left.tail->right = root;
        root->right = right.head;
        l.head = left.head;
        l.tail = right.tail;
    }
    return l;
}
void printLL(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << "-->";
        head = head->right;
    }
    cout << endl;
}
int main()
{
    Node *root = NULL;
    root = createBST();
    levelOrder(root);
    if (checkBST(root))
    {
        cout << "BST" << endl;
    }
    else
    {
        cout << "Not a BST" << endl;
    }
    PreOrder(root);
    cout << endl;
    LinkedList ans = BSTtoLL(root);
    printLL(ans.head);
    return 0;
}