#include<stdio.h>
#include<stdlib.h>

//Queue -FIFO
struct Node{
    int data;
    struct Node *prev;
    struct Node *next;
};
struct Node *head;
struct Node *tail;

void enqueue(int data){
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

void dequeue(){
    if (head == NULL) {
        printf("Queue is Empty\n");
    } else {
        struct Node *temp=head;
        head=head->next;
        if (head != NULL) {
            head->prev=NULL;
        } else {
            tail=NULL; // Queue is now empty
        }
        free(temp);
    }
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
    enqueue(5);
    enqueue(6);
    enqueue(7);
    printf("enqueue 5,6,7\n");
    display();
    dequeue();
    printf("dequeue 5\n");
    display();
}
