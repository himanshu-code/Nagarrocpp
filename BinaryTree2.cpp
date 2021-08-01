#include <bits/stdc++.h>
using namespace std;
//10 2 6 -1 -1 -1 5 8 -1 -1 7 9 -1 -1 -1

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
Node *createTree()
{
    int data;
    cin >> data;
    if (data == -1)
    {
        return NULL;
    }
    Node *root = new Node(data);
    root->left = createTree();
    root->right = createTree();
    return root;
}
Node* lca(Node* root,int a,int b){
    if(!root){
        return NULL;
    }
    if(root->data==a|| root->data==b){
        return root;
    }
    Node* left=lca(root->left,a,b);
    Node* right=lca(root->right,a,b);
    if(left!=NULL and right!=NULL){
        return root;
    }

    if(right==NULL){
        return left;
    }
    return right;
}
int printRightView(Node* root,int level,int &max_level){
    if(!root){
        return 0;
    }
    if(level>max_level){
        cout<<root->data<<" ";
        max_level=level;
    }
    printRightView(root->right,level+1,max_level);
    printRightView(root->left,level+1,max_level);
}
int main(){
    Node* root;
    root=createTree();
    Node* ans=lca(root,8,9);
    if(ans){
        cout<<ans->data<<endl;
    }
    else{
        cout<<"LCA is not Present"<<endl;
    }
    int max_level=-1;
    printRightView(root,0,max_level);
    return 0;

}