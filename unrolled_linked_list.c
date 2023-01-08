#include<stdio.h>
#include<stdlib.h>
#define MAX 10

int block_count = 0;

// Definition of node of linked list
struct node {
    int data;
    struct node *link;
};

// Definition of a block
struct block{
    struct node *head;
    struct node *tail;
    int node_count;
    struct block *link;
};

// Declaration of functions
void append(struct block **,int);
void display(struct block **);

// main function
int main()
{
    struct block *head;
    head = NULL;
    append(&head,1);
    append(&head,2);
    append(&head,3);
    append(&head,4);
    append(&head,5);
    append(&head,6);
    append(&head,7);
    append(&head,8);
    append(&head,9);
    append(&head,10);
    append(&head,11);
    append(&head,12);
    append(&head,13);
    append(&head,14);
    append(&head,15);
    display(&head);
    return 0;
}

// Display function definition
void display(struct block **block_ptr){
    struct block *block_temp; // A pointer variable to iterate over blocks
    struct node *temp; // A pointer variable to iterate over the nodes of linked list
    block_temp = *block_ptr; // Storing the first node 

    // Iterating over the blocks
    for (int i = 0; i < block_count; i++)
    {
        temp = block_temp->head;
        // Iterating over the lists inside the blocks
        for (int j = 0; j < block_temp->node_count; j++)
        {
            printf("%d ",temp->data); // Printing the data every time
            temp = temp->link;   // Chaging the pointer evertime we iterate
        }
        block_temp = block_temp->link; //  Changing the block pointer as we iterate
    }
}

// Append function definition
void append(struct block **block_ptr,int data){
    struct block *new_block,*block_temp; // Pointer variables related to blocks
    struct node *new_node,*temp; // Pointer variables related to nodes 

    // If the unrolled list is empty
    if(*block_ptr == NULL){
       new_block = malloc(sizeof(struct block)); // Creating a block 
       new_node = malloc(sizeof(struct node)); // Creating a node 
       *block_ptr = new_block; // Assigning the block 
       new_block->link = NULL; // Assigning new_block's next to NULL

       // As we created first node so assigning the node to head and tail
       new_block->head = new_node;  
       new_block->tail = new_node; 
       
       // Assigning the data    
       new_node->data = data;
       new_node->link = new_block->head;

       // Setting the count to 1
       new_block->node_count = 1;

       // As our first block is created increasing the counter 
       block_count++;
    }else{
        // Assigning the pointer 
        block_temp = *block_ptr;

        // Iterating till lass block 
        while (block_temp->link!=NULL)
        {
            block_temp = block_temp->link;
            // If we are at last node then break 
            if (block_temp->link==NULL)
            {
                break;
            }            
        }

        // Checking the number of nodes in last block 
        if(block_temp->node_count == MAX){
            new_block = malloc(sizeof(struct block));
            new_node = malloc(sizeof(struct node));
            block_temp->link = new_block;
            new_block->link = NULL;
            new_block->head = new_node;
            new_block->tail = new_node;
            new_node->data = data;
            new_block->node_count = 1;
            block_count++;
        }else
        {   
            // If number of nodes are less then max then create a new node and add it to the linked list 
            new_node = malloc(sizeof(struct node));
            new_node->data = data;
            new_node->link = block_temp->head;
            block_temp->tail->link = new_node;
            block_temp->tail = new_node;
            block_temp->node_count++;
            return;
        }        
    }
}
