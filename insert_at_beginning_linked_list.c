#include<stdio.h>
#include<stdlib.h>

struct Node{//create user defined datatype with data and addrs.
    int data;
    struct Node *next;
};
struct Node *head=NULL;//global

void insertAtBeg(int data){//insert at beginning
    struct Node *newNode=(struct Node *)malloc(sizeof(struct Node));//create newNode
    newNode->data=data;//newNode data=data
    newNode->next=head;//newNode points to addr of curr node (1000)
    head=newNode;//head points newNode
}

int main(){
    insertAtBeg(5);
    insertAtBeg(6);
    return 0;
}

