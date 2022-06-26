#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

void printPreorder(struct Node *node)
{
    if(node==NULL){
        return;
    }
    cout << node->data << " ";
    printPreorder(node->left);
    printPreorder(node->right);
}

void printInorder(struct Node *node)
{
    if(node==NULL)
    {
        return;
    }
    printInorder(node->left);
    cout << node->data << " ";
    printInorder(node->right);
}

void printPostorder(struct Node *node)
{
    if(node==NULL){
        return;
    }
    printPostorder(node->left);
    printPostorder(node->right);
    cout << node->data << " ";
}

int main()
{
    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    cout << "\nPreorder traversal of binary tree is" <<endl;
    printPreorder(root);
    cout << "\nInorder traversal of binary tree is" << endl;
    printInorder(root);
    cout << "\nPostorder traversal of binary tree is" << endl;
    printPostorder(root);
    return 0;
}
