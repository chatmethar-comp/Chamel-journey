#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int item;
    struct Node *next;
};

struct Node *createNode(int item, struct Node *nextNode)
{
    struct Node *newNode;
    newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->item = item;
    newNode->next = nextNode;
    return newNode;
};

void setItem(int newItem, struct Node *node)
{
    node->item = newItem;
}

int getItem(struct Node *node)
{
    return node->item;
}

void setNext(struct Node *newNode, struct Node *node)
{
    node->next = newNode;
}

struct Node *getNext(struct Node *node)
{
    return node->next;
};

struct Node *newNode;
struct Node *head;
struct Node *curr;
struct Node *prevv;

void add(int newItem)
{
    if(head == NULL)
    {
        newNode = createNode(newItem, NULL);
    }
    else
    {
        newNode = createNode(newItem, head);
    }
    head = newNode;
}

bool searchItem(int item)
{
    curr = head;
    prevv = NULL;
    while(curr!=NULL){
        if(item == curr->item){
            return 1;
        }
        prevv=curr;
        curr=curr->next;
    }
    return 0;
}

void deleteNode(int item)
{
    if(searchItem(item)){
        if(prevv==NULL){
            head = curr->next;
        } else {
            prevv->next = curr->next;
        }
    } else {
        cout << "Not found Item." << endl;
    }
}

void insertNode(int itemInsert, int newItem)
{
    newNode = createNode(newItem,NULL);
    if(searchItem(itemInsert))
    {
        if(prevv==NULL){
            newNode->next = curr;
            head = newNode;
        } else {
            newNode->next = curr;
            prevv->next = newNode;
        }
    }
    else
    {
        if(head==NULL){
            newNode->next=curr;
            head=newNode;
        } else if(curr==NULL) {
            prevv->next=newNode;
        }
    }
}

void traverse()
{
    curr=head;
    while(curr!=NULL){
        cout << curr->item << " ";
        curr=curr->next;
    }
    cout << endl;
}
int main()
{
    add(9);
    cout << "add 9 : ";
    traverse();

    add(10);
    cout << "add 10 : ";
    traverse();

    add(11);
    cout << "add 11 : ";
    traverse();

    add(12);
    cout << "add 12 : ";
    traverse();

    deleteNode(10);
    cout << "delete 10 : ";
    traverse();

    deleteNode(12);
    cout << "delete 12 : ";
    traverse();

    insertNode(11, 15);
    cout << "insert 15 before 11 : ";
    insertNode(22, 22);
    traverse();
    return 0;
}



