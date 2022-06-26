#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
    Node(int x){
        data=x;
        next=NULL;
    }
};

int intersectPoint(Node* head1, Node* head2)
{
    int n1=0, n2=0;
    Node* temp;
    for(temp=head1;temp;temp=temp->next){
        n1++;
    }
    for(temp=head2;temp;temp=temp->next){
        n2++;
    }
    for(;n1>n2;n1--){
        head1=head1->next;
    }
    for(;n2>n1;n2--){
        head2=head2->next;
    }
    while(head1!=head2){
        head1=head1->next;
        head2=head2->next;
    }
    if(head1)P
        return head1->data;
    return -1
}

int main()
{

    return 0;
}
