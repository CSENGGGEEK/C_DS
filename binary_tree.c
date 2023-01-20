#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
};


void construct_tree(struct node **node){
    struct node *new_node;
    int data, left, right;
    new_node = malloc(sizeof(struct node));
    printf("Enter data : ");
    scanf("%d",&data);
    printf("Enter left child : ");
    scanf("%d",&left);
    printf("Enter right child : ");
    scanf("%d",&right);
    *node = new_node;
    new_node->data = data;
    
    if (left == 1)
    {
        construct_tree(&new_node->left);
    }
    
    if (right == 1)
    {
        construct_tree(&new_node->right);
    }
}

void traverse(struct node *node){
    struct node *temp = node;
    printf("%d ",temp->data);
    
    if (temp->left!=NULL)
    {
        traverse(temp->left);
    }

    if (temp->right!=NULL)
    {
        traverse(temp->right);
    }    
}

int main(){
    struct node *root_node = NULL;

    construct_tree(&root_node);
    traverse(root_node);
}

