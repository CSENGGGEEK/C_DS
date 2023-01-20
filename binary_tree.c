#include<stdio.h>
#include<stdlib.h>

// Node of a binary tree consisting of pointer of left and right childs and the data
struct node {
    int data;
    struct node *left;
    struct node *right;
};

typedef struct node BINARY_NODE;

// Constructuon of the tree 
void construct_tree(BINARY_NODE **node){
    /*
    * Variables for new node 
    * Data, left_child and right_child 
    */
    BINARY_NODE *new_node;
    int data, left, right; 

    // New node craetion
    new_node = malloc(sizeof(BINARY_NODE));

    // Asking for details of a node 
    printf("Enter data : ");
    scanf("%d",&data);
    printf("Enter left child (1 : Yes): ");
    scanf("%d",&left);
    printf("Enter right child (1 : Yes): ");
    scanf("%d",&right);

    // Assigning the nodes every time
    *node = new_node;
    new_node->data = data;
    
    // Creating the left child 
    if (left == 1)
    {
        construct_tree(&new_node->left);
    }
    
    // Creating the right child 
    if (right == 1)
    {
        construct_tree(&new_node->right);
    }
}

void traverse(BINARY_NODE *node){
    BINARY_NODE *temp = node;
    // printf("%d ",temp->data);
    // 1 2 3 4 5 6 7 

    if (temp->left!=NULL)
    {
        traverse(temp->left);
    }
    
    // printf("%d ",temp->data);
    // 3 2 4 1 6 5 7 

    if (temp->right!=NULL)
    {
        traverse(temp->right);
    }    

    printf("%d ",temp->data);
    // 3 4 2 6 7 5 1
}

int main(){
    BINARY_NODE *root_node = NULL;

    construct_tree(&root_node);
    traverse(root_node); 

    return 0;
}

