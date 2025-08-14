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

void addToPlaylist(char name[]){
    createNode(name);
    if(head==NULL){
        head=newNode;
    }
    else{
        newNode->next=head;
        head=newNode;
    }
    printf("---Song Added---\n");
}

void display(){
    struct Node *temp=head;
    if(head==NULL){
        printf("---No song in the Playlist---\n");
        return;
    }
    while(temp!=NULL){
        printf("%s ", temp->name);
        temp=temp->next;
    }
    printf("\n");
}

int main(){
    int n;
   
    do{ 
        printf("---Audio Player---\n1. Add Song\n2. Display All\n3. Exit\n");
        scanf("%d", &n);
        getchar();                           //handling newline
        switch(n){
            case 1:{
                printf("Enter the song name: ");
                char name[100];
                fgets(name, sizeof(name), stdin);
                name[strcspn(name, "\n")]=0;              //handling newline of the string
                addToPlaylist(name);break;
            }
            case 2:{
                printf("---Current Playlist---\n");
                display();break;
            }
            case 3:
                printf("Thank You!!!");break;
            default:
                printf("Invalid Input!!!\n");break;
        }
    }while(n!=3);
    
}