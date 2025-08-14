#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 10

struct Node{
    int data;
    struct Node *next;
};

struct Node *hashTable[TABLE_SIZE];

struct Node *createNode(int data){
    struct Node *newNode=(struct Node *)malloc(sizeof(struct Node));
    newNode->data=data;
    newNode->next=NULL;
    return newNode;
}

int hashFunction(int key){
    return key%TABLE_SIZE;
}

void insert(int key){
    int index=hashFunction(key);
    struct Node *newNode=createNode(key);
    newNode->next=hashTable[index];
    hashTable[index]=newNode;
}

void display(){
    
}

int main() {
    int choice, key;

    // Initialize hash table
    for (int i = 0; i < TABLE_SIZE; i++)
        hashTable[i] = NULL;

    while (1) {
        printf("\nHash Table Menu:\n");
        printf("1. Insert\n2. Search\n3. Delete\n4. Display\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter key to insert: ");
                scanf("%d", &key);
                insert(key);
                break;
            case 2:
                printf("Enter key to search: ");
                scanf("%d", &key);
                search(key);
                break;
            case 3:
                printf("Enter key to delete: ");
                scanf("%d", &key);
                deleteKey(key);
                break;
            case 4:
                display();
                break;
            case 5:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }
}
