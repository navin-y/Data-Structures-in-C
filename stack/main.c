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
    printf("push 5,6\n");
    display();
    pop();
    printf("pop 7\n");
    display();
    printf("Peek is %d\n",peek());
    isEmpty();
    push(8);
    //push(9);
    printf("push 8,9\n");
    display();
    printf("Reverse Stack\n");
    reverseStack();
    
    return 0;
}