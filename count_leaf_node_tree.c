#include<stdio.h>
#include<stdlib.h>

// Node of a binary tree consisting of pointer of left and right childs and the data
struct node {
    int data;
    struct node *left;
    struct node *right;
};

typedef struct node BINARY_NODE;

int count = 0;

// Construction of the tree 
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
    
    // Creating the left Subtree
    if (left == 1)
    {
        construct_tree(&new_node->left);
    }
    
    // Creating the right Subtree 
    if (right == 1)
    {
        construct_tree(&new_node->right);
    }
}

void counter(struct node *root){
    struct node *temp = root;

    if (temp->left == NULL && temp->right == NULL)
    {
        count+=1;
    }
    
    
    if (temp->left!= NULL)
    {
        counter(temp->left);
    }
    
    if (temp->left!= NULL)
    {
        counter(temp->left);
    }
}

int main(int argc, char const *argv[])
{
    struct node *root = NULL;
    construct_tree(&root);
    counter(root);
    printf("%d",count);
    return 0;
}
