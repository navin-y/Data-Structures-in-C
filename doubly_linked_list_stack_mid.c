#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *prev;
    struct Node *next;
};
struct Node *head=NULL;
struct Node *tail=NULL;

void push(int data){
    struct Node *newNode=(struct Node *)malloc(sizeof(struct Node));
    newNode->data=data;
    newNode->prev=NULL;
    newNode->next=head;
    if(head!=NULL)
        head->prev=newNode;
    else
        tail=newNode;
    head=newNode;
}

void pop(){
    if(head==NULL){
        printf("Stack is Empty");
    }
    else{
        struct Node *temp=head;
        head=temp->next;
        temp->next=NULL;
        head->prev=NULL;
        free(temp);
    }
}

int peek(){
    return head->data;
}

void isEmpty(){
    if(head==NULL)
        printf("Stack is Empty\n");
    else
        printf("Stack is not Empty\n");
}

void reverseStack(){
    struct Node *temp=tail;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->prev;
    }
    printf("\n");
}

void midUsingHeadTail(){
    struct Node *temp1=head;
    struct Node *temp2=tail;
    while(temp1!=temp2 && temp1->next!=temp2){
        temp1=temp1->next;
        temp2=temp2->prev;
    }
    printf("%d\n",temp1->data);
}

void midUsingHeads(){
    struct Node *temp1=head;
    struct Node *temp2=head;
    while(temp2->next->next!=NULL && temp2->next!=NULL){
        temp1=temp1->next;
        temp2=temp2->next->next;
    }
    printf("%d\n",temp1->data);
}

void display(){
    struct Node *temp=head;
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
    push(9);
    push(1);
    display();
    midUsingHeadTail();
    midUsingHeads();
    return 0;
}