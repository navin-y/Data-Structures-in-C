//Josephus problem

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
    newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data=data;
    newNode->prev=newNode->next=NULL;
}

void insertAtEnd(int data){
    createNode(data);
    if(head==NULL){
        head=tail=newNode;
    }
    else{
        tail->next=newNode;
        newNode->prev=tail;
        tail=newNode;
    }
}

void makeCircle(){
    head->prev=tail;
    tail->next=head;
}

void display(){
    struct Node *temp=head;
    do{
        printf("%d ",temp->data);
        temp=temp->next;
    }while(temp!=head);
    printf("\n");
}

void deleteAtPos(struct Node *temp){
    if(temp==head && temp==tail){
        head = tail = NULL;
    }
    else if(temp==head){
        head=head->next;
        head->prev=tail;
        tail->next=head;
    }
    else if(temp==tail){
        tail=tail->prev;
        tail->next=head;
        head->prev=tail;
    }
    else{
        temp->prev->next=temp->next;
        temp->next->prev=temp->prev;
    }
    //display();
    free(temp);
}

void gameStart(int key){
    struct Node *temp=head;
    while(temp->next!=temp){
        for(int i=1;i<key;i++){
            temp=temp->next;
        }
        struct Node *toDelete = temp;
        temp=temp->next;
        deleteAtPos(toDelete);
    }
    printf("Winner: %d", head->data);
}

int main(){
    for(int i=1;i<=10;i++){
        insertAtEnd(i);
    }
    makeCircle();
    display();
    gameStart(4);
}