#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *prev;
    struct Node *next;
};

struct Node *head1;
struct Node *head2;
struct Node *tail1;
struct Node *tail2;

void push(int data){
    struct Node *newNode=(struct Node *)malloc(sizeof(struct Node));
    newNode->data=data;
    newNode->prev=NULL;
    newNode->next=head1;
    if(head1!=NULL)
        head1->prev=newNode;
    else
        tail1=newNode;
    head1=newNode;
}

void pushUndo(int data){
    struct Node *newNode=(struct Node *)malloc(sizeof(struct Node));
    newNode->data=data;
    newNode->prev=NULL;
    newNode->next=head2;
    if(head2!=NULL)
        head2->prev=newNode;
    else
        tail2=newNode;
    head2=newNode;
}

void undo(){
    struct Node *temp=head2;
    head2=temp->next;
    temp->next=NULL;
    head2->prev=NULL;
    push(temp->data);
}

void pop(){
    struct Node *temp=head1;
    head1=temp->next;
    temp->next=NULL;
    head1->prev=NULL;
    pushUndo(temp->data);
}

void displayUndo(){
    struct Node *temp=head2;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}

void display(){
    struct Node *temp=head1;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}

int main(){
    push(5);
    push(6);
    push(7);
    push(8);
    display();
    pop();
    display();
    undo();
    display();
}