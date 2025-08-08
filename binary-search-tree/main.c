#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *left;
    struct Node *right;
};
struct Node *newNode;

struct Node* createNode(int val){
    newNode=(struct Node *)malloc(sizeof(struct Node));
    newNode->data=val;
    newNode->left=NULL;
    newNode->right=NULL;
    return newNode;
}

struct Node* insert(struct Node *root, int val){
    if(root==NULL)
        return createNode(val);
    if(val < root->data)
        return insert(root->left, val);
    else
        return insert(root->right, val);
}

void inOrder(struct Node *root){
    if(root!=NULL){
        inOrder(root->left);
        printf("%d ",root->data);
        inOrder(root->right);
    }
}

void preOrder(struct Node *root){
    if(root!=NULL){
        printf("%d ",root->data);
        preOrder(root->left);
        preOrder(root->right);
        
    }
}

void postOrder(struct Node *root){
    if(root!=NULL){
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ",root->data);
    }
}

int main(){
    struct Node *root=NULL;
    int n,data;

    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&data);
        root=insert(root, data);
    }
    inOrder(root);
}

