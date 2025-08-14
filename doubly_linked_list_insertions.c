#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *prev;
    struct Node *next;
};

struct Node *head=NULL;
struct Node *tail=NULL;
struct Node *newNode;

void createNode(int data){
    newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->prev=newNode->next=NULL;
    newNode->data=data;
    //return newNode;
}

void insertAtBeg(int data){
    //struct Node *newNode=
    createNode(data);
    newNode->prev=NULL;
    newNode->data=data;
    if(head==NULL){
        head=newNode;
        tail=newNode;
        newNode->next=NULL;
    }
    else{
        head->prev=newNode;
        newNode->next=head;
        head=newNode;
    }
}

void insertAtEnd(int data){
    //struct Node *newNode=
    createNode(data);
    newNode->next=NULL;
    newNode->data=data;
    if(head==NULL){
        head=newNode;
        tail=newNode;
        newNode->prev=NULL;
    }
    else{
        tail->next=newNode;
        newNode->prev=tail;
        tail=newNode;
    }
}

void display(){
    struct Node *temp=head;
    while(temp!=NULL){
        printf("%d ", temp->data);
        temp=temp->next;
    }
    printf("\n");
}

int main(){
    insertAtEnd(5);
    insertAtBeg(6);
    insertAtBeg(7);
    display();
}