#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_SIZE 100

struct Node{
    char dirName[MAX_SIZE];
    struct Node *prev;
    struct Node *next;
};

struct Node *head=NULL;
struct Node *current=NULL;

struct Node *createDir(char dirName[]){
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    strcpy(newNode->dirName, dirName);
    newNode->prev=newNode->next=NULL;
}

void visitDir(char dirName[]){
    struct Node * newNode=createDir(dirName);
    if(head==NULL){
        head=newNode;
        current=head;
    }
    else{
        struct Node *temp=current->next;
        //if current is not in the end, then delete all the next nodes
        while(temp!=NULL){
            struct Node *del=temp;
            temp=temp->next;
            free(del);
        }
        current->next=newNode;
        current->prev=current;
        current=newNode;
    }
    printf("Visited the dir: %s\n",dirName);
}

void goBack(){
    if(current!=NULL && current->prev!=NULL){
        current=current->prev;
        printf("Moved back Dir: %s\n",current->dirName);
    }else{
        printf("No directories found!!\n");
    }
}

void goForward(){
    if(current!=NULL && current->next!=NULL){
        current=current->next;
        printf("Moved forward Dir: %s\n",current->dirName);
    }else{
        printf("No directories found!!\n");
    }
}

void showHistory(){
    struct Node *temp=head;
    while(temp!=NULL){
        if(temp==current){
            printf("%s -> (current)\n",temp->dirName);
        }else{
            printf("%s\n",temp->dirName);
        }
        temp=temp->next;
    }
}

int main(){
    int choice;
    char dirName[MAX_SIZE];
    while(1){
         printf("\n--- File Directory History ---\n");
        printf("1. Visit Directory\n");
        printf("2. Go Back\n");
        printf("3. Go Forward\n");
        printf("4. Show History\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // clear newline

        switch (choice) {
            case 1:
                printf("Enter directory name: ");
                fgets(dirName, MAX_SIZE, stdin);
                dirName[strcspn(dirName, "\n")] = '\0'; // remove newline
                visitDir(dirName);
                break;
            case 2:
                goBack();
                break;
            case 3:
                goForward();
                break;
            case 4:
                showHistory();
                break;
            case 5:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
}