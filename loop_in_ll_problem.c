#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>


struct node{
    int data;
    struct node *link;
};

void append_sll(struct node **,int);
void loop_checker(struct node**);

void main(){
    struct node *head = NULL;
    
}

void loop_checker(struct node **head){
    struct node *temp = *head;
    int key = 1;
    while (temp->link!=NULL)
    {
        // if (/* condition */)
        // {
        //     /* code */
        // }
        temp = temp->link;
    }
}