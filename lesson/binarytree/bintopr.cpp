#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

Node* createNode(int data)
{
    Node *newnode = new Node();
    newnode->data = data;
    newnode->left = newnode->right = NULL;
    return newNode;
}

Node* insertNode(Node* root, int data)
{
    if(root==NULL)
    {
        root = createNode(data);
        return root;
    }

    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        Node* temp = q.front();
        q.pop();
    }
}
int main()
{

    return 0;
}
