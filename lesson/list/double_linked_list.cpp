#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int item;
    struct Node *precede;
    struct Node *next;
};

struct Node *createNode(int item, struct Node *precedeNode, struct Node *nextNode)
{
    struct Node *newNode;
    newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->item=item;
    newNode->next=nextNode;
    newNode->precede=precedeNode;
    return newNode;
};

struct Node *newNode;
struct Node *head;
struct Node *last;
struct Node *curr;
struct Node *prev1;
struct Node *prev2;

void add(int newItem)
{
    if(head=NULL)
    {
        newNode=createNode(newItem,NULL,NULL);
    }
    else
    {
        newNode=createNode(newItem,NULL,head);
    }
    head=newNode;
}

bool searchItem(int item)
{
    curr=head;
    prev=NULL;
    while(curr!=NULL){
        if(item == curr->item){
            return 1;
        }
        prev=curr;
        curr=curr->next;
    }
    return 0;
}

void deleteNode(int item)
{
    if(searchItem(item)){
        if(prev==NULL){

        }
    }
}

int main()
{
    add(9);
    return 0;
}
