#include<stdio.h>
#include<stdlib.h>

struct Node{  //create user defined datatype with data and addrs.
    int data;
    struct Node *next;
};
struct Node *head=NULL;  //global

void insertAtBeg(int data){  //insert at beginning
    struct Node *newNode=(struct Node *)malloc(sizeof(struct Node));  //create newNode
    newNode->data=data;  //newNode data=data
    newNode->next=head;  //newNode points to addr of curr node (1000)
    head=newNode;  //head points newNode
}

void insertAtEnd(int data){//insert at end

    struct Node *newNode=(struct Node *)malloc(sizeof(struct Node));  //create new node
    newNode->data=data;  //take care of data;
    newNode->next=NULL;  //new node is last to next is null
    struct Node *temp=head;  //temp pointer to tranverse
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=newNode;
}

void display(){
    struct Node *temp=head;  //temp to traverse the linkedlist
    
    while(temp!=NULL){  //temp!=null to also print the data of the last node
        printf("%d ",temp->data);  //print data of each node
        temp=temp->next;  //changing node
    } 
    printf("\n");
}

void insertAtPos(int data,int pos){
    struct Node *newNode=(struct Node *)malloc(sizeof(struct Node));  //create new Node
    newNode->data=data;  //take care of data
    struct Node *temp=head;  //temp variable to traverse to the pos-1
    for(int i=1;i<pos-1;i++){
        temp=temp->next;  //temp will be in 2000
    }
    newNode->next=temp->next; //6000->next=1000
    temp->next=newNode;  //2000->next=6000
}

void deleteAtBeg(){
    struct Node *temp=head;
    head=temp->next; //head-->2000
    temp->next=NULL;  //3000->next=NULL
    free(temp);
}

void deleteAtEnd(){
    struct Node *temp=head;
    while((temp->next)->next!=NULL){ 
        temp=temp->next;
    }
    free(temp->next); 
    temp->next=NULL;
    
}

void deleteAtPos(int pos){
    struct Node *temp=head;
    for(int i=1;i<pos-1;i++){ //1 time iterate
        temp=temp->next;
    }
    temp->next=(temp->next)->next;  //6000->next=3000
    (temp->next)->next=NULL; //1000->next=NULL
    free(temp->next);  //(6000->next)--->free
}

int main(){
    insertAtBeg(5); //atleast 1 insertAtBeg
    insertAtEnd(6);
    insertAtEnd(7);
    printf("Initial\n");
    display();
    insertAtPos(9,3);
    printf("Insert pos 3\n");
    display();
    deleteAtBeg();
    printf("delete beg\n");
    display();
    deleteAtEnd();
    printf("delete end\n");
    display();
    insertAtEnd(7);
    insertAtEnd(10);
    printf("insert end 7,10\n");
    display();
    deleteAtPos(3);
    printf("delete 7\n");
    display();
    return 0;
}
