#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Node{
    char name[100];
    struct Node *next;
};

struct Node *head=NULL;
struct Node *newNode;

void createNode(char name[]){
    newNode = (struct Node *)malloc(sizeof(struct Node));
    strcpy(newNode->name, name);
    newNode->next=NULL;
}

void addToCongo(char name[]){
    createNode(name);
    if(head==NULL){
        head=newNode;
    }
    else{
        newNode->next=head;
        head=newNode;
    }
    printf("---Person Added---\n");
}

void display(){
    struct Node *temp=head;
    if(head==NULL){
        printf("---No congo line---\n");
        return;
    }
    while(temp!=NULL){
        printf("%s", temp->name);
        if(temp->next!=NULL)
            printf(" -> ");
        temp=temp->next;
    }
    printf("\n");
}

int main(){
    int n;
    char name[100];
    printf("Enter the size of the line\n");
    scanf("%d",&n);
    getchar();
    for(int i=0;i<n;i++){
        fgets(name, sizeof(name), stdin);
        name[strcspn(name, "\n")]=0;
        addToCongo(name);
    }
    display();
}