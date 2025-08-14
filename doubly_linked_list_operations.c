#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *prev;
    struct Node *next;
};
struct Node *head;
struct Node *tail;

void insertAtBeg(int data){
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

void insertAtEnd(int data){
    struct Node *newNode=(struct Node *)malloc(sizeof(struct Node));
    newNode->data=data;
    newNode->next=NULL;
    newNode->prev=tail;
    if(tail!=NULL)
        tail->next=newNode;
    else
        head=newNode;
    tail=newNode;
}

void insertAtPos(int data,int pos){
    struct Node *newNode=(struct Node *)malloc(sizeof(struct Node));
    newNode->data=data;
    struct Node *temp=head;
    for(int i=1;i<pos-1;i++){
        temp=temp->next;
    }
    newNode->next=temp->next;
    newNode->prev=(temp->next)->prev;
    temp->next=(temp->next)->prev=newNode;
}

void deleteAtBeg(){
    struct Node *temp=head;
    head=temp->next;
    temp->next=NULL;
    free(temp);
}

void deleteAtEnd(){
    struct Node *temp=tail;
    tail=temp->prev;
    temp->prev=NULL;
    tail->next=NULL;
    free(temp);
}

void deleteAtPos(int pos){
    struct Node *temp=head;
    for(int i=1;i<pos-1;i++){
        temp=temp->next;
    }
    (temp->prev)->next=temp->next;
    (temp->next)->prev=temp->prev;
    free(temp);
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
    insertAtBeg(5);
    insertAtBeg(6);
    printf("insert beg 5,6\n");
    display();
    insertAtEnd(7);
    insertAtEnd(8);
    printf("insert end 7,8\n");
    display();
    insertAtPos(9,3);
    printf("insert 9 at 3\n");
    display();
    deleteAtBeg();
    printf("delete 6\n");
    display();
    deleteAtEnd();
    printf("delete 8\n");
    display();
    deleteAtPos(3);
    printf("delete 9\n");
    display();
    deleteAtEnd();
    display();
}