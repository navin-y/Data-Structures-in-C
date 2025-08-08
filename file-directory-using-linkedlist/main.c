#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Node{
    char path[500];
    struct Node *prev;
    struct Node *next;
};
struct Node *head=NULL;
struct Node *tail=NULL;

void visitDirectory(char path[]){
    struct Node *newNode=(struct Node *)malloc(sizeof(struct Node));
    strcpy(newNode->path,path);
    newNode->prev=NULL;
    newNode->next=head;
    if(head!=NULL)
        head->prev=newNode;
    else
        tail=newNode;
    head=newNode;
}
//struct Node *curr=head;

void moveForward(){
    struct Node *curr=head;
    if(curr && curr->next){
        curr=curr->next;
        printf("%s",curr->path);
    }
    else{
        printf("No next directory\n");   
    }
}

void moveBack(){
    struct Node *curr=head;
    if(curr && curr->prev){
        curr=curr->prev;
        printf("%s",curr->path);
    }
    else{
        printf("No prev directory\n");   
    }
}

void deleteAtPos(int pos){
    struct Node *temp=head;
    for(int i=1;i<pos-1;i++){//1
        temp=temp->next;
    }
    temp->prev->next=temp->next;
    temp->next->prev=temp->prev;
    free(temp);
}

void display(){
    struct Node *temp=head;
    while(temp!=NULL){
        printf("%s\n",temp->path);
        temp=temp->next;
    }
    printf("\n");
}

int main(){
    char path[500];
    printf("Enter the directory to be visited\n");
    visitDirectory("c:user/dell/batteryreport.html");
    visitDirectory("d:folder1/hello.txt");
    display();
    //moveForward();
    //moveBack();
}