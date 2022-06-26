#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

void traverse(struct Node *head)
{
    struct Node *curr;
    curr = head;
    while(curr){
        cout << curr->data << " ";
        curr=curr->next;
    }
    cout << endl;
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n, num;
        cin >> n;
        Node *head, *tail;
        cin >> num;
        head = tail = new Node(num);
        for(int i=1;i<n;i++){
            cin >> num;
            tail->next = new Node(num);
            tail = tail->next;
        }
        traverse(head);
    }
    return 0;
}
