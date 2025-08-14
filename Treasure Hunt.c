//Implementation of treasure hunt game using linkedlist

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

struct Node{
    char quest[100];
    char ans[50];
    struct Node *prev;
    struct Node *next;
};
struct Node *head;
struct Node *tail;

void insertAtEnd(char quest[], char ans[]){
    struct Node *newNode=(struct Node *)malloc(sizeof(struct Node));
    strcpy(newNode->quest,quest);
    strcpy(newNode->ans,ans);
    newNode->next=NULL;
    newNode->prev=tail;
    if(tail!=NULL)
        tail->next=newNode;
    else
        head=newNode;
    tail=newNode;
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

void displayClue(int i){
    struct Node *temp=head;
    for(int j=1;j<i;j++){
        temp=temp->next;
    }
    printf("%s\n",temp->quest);
}

void display(){
    struct Node *temp=head;
    while(temp!=NULL){
        printf("%s->%s\n",temp->quest,temp->ans);
        temp=temp->next;
    }
    printf("\n");
}

int main(){
    insertAtEnd("1.What has to be broken before you can use it?","egg");
    insertAtEnd("2.What is full of holes but still holds water?","sponge");
    insertAtEnd("3.What gets wet while drying?","towel");
    insertAtEnd("4.I swallow warmth in silence, glowing only when revealed—who am I?","fridge");
    l1:
    char ans[50];
    printf("Welcome to Treasure Hunt\nType correct answers (in lowercase) to the given clues to reach end\n\n");
    displayClue(1);
    while(1){
        scanf("%s",ans);
        if(!strcmp(ans,"egg")){
            printf("Correct! Next clue\n");
            break;
        }
        else if(!strcmp(ans,"-1"))
            goto l1;
        else if(!strcmp(ans,"0"))
            goto l2;
        else{
            printf("Wrong answer try again!\n");
            printf("Press -1 to restart 0 to exit\n");
        }
    }
    displayClue(2);
    while(1){
        scanf("%s",ans);
        if(!strcmp(ans,"sponge")){
            printf("Correct! Next clue\n");
            break;
        }
        else if(!strcmp(ans,"-1"))
            goto l1;
        else if(!strcmp(ans,"0"))
            goto l2;
        else{
            printf("Wrong answer try again!\n");
            printf("Press -1 to restart 0 to exit\n");
        }
    }
    displayClue(3);
    while(1){
        scanf("%s",ans);
        if(!strcmp(ans,"towel")){
            printf("Correct! Next clue\n");
            break;
        }
        else if(!strcmp(ans,"-1"))
            goto l1;
        else if(!strcmp(ans,"0"))
            goto l2;
        else{
            printf("Wrong answer try again!\n");
            printf("Press -1 to restart 0 to exit\n");
        }
    }
    displayClue(4);
    while(1){
        scanf("%s",ans);
        if(!strcmp(ans,"fridge")){
            printf("Correct! Open the fridge there is your gift!!\n");
            break;
        }
        else if(!strcmp(ans,"-1"))
            goto l1;
        else if(!strcmp(ans,"0"))
            goto l2;
        else{
            printf("Wrong answer try again!\n");
            printf("Press -1 to restart 0 to exit\n");
        }
    }
    
    l2:
    return 0;
    
}
