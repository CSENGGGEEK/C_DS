#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *prev;
    struct node *next;
};

typedef struct node DLL_NODE;

void append_dll(DLL_NODE **head,int data);
void addbeg_dll(DLL_NODE **head,int data);
void addaft_dll(DLL_NODE **head,int data,int loc);
void delnode_dll(DLL_NODE **head,int data);
void display_dll(DLL_NODE *head);

int main(int argc, char const *argv[])
{
    DLL_NODE *head;
    head = NULL;
    append_dll(&head,10);
    append_dll(&head,20);
    append_dll(&head,30);
    append_dll(&head,40);
    append_dll(&head,50);
    append_dll(&head,60);
    addbeg_dll(&head,80);   
    // delnode_dll(&head,40);
    printf("HEAD");
    display_dll(head);
    printf("NULL");
    return 0;
}

void append_dll(DLL_NODE **head,int data){
    DLL_NODE *temp,*new_node;
    temp = *head;
    new_node  = malloc(sizeof(DLL_NODE));
    new_node->data = data;
    new_node->next = NULL;
    if(temp==NULL){
        new_node->prev = *head;
        *head = new_node;
    }else
    {
        while (temp->next!=NULL)
        {
            temp = temp->next;
        }
        new_node->prev = temp;
        temp->next = new_node;
    }
}

void addbeg_dll(DLL_NODE **head,int data){
    DLL_NODE *temp,*new_node;
    new_node = malloc(sizeof(DLL_NODE));
    new_node->data = data;
    new_node->next = *head;
    *head = new_node;
    new_node->prev = *head;
}

void addaft_dll(DLL_NODE **head,int data,int loc){
    DLL_NODE *temp,*new_node;
    temp = *head;
    for (int i = 0; i < loc; i++)
    {
        temp =  temp->next;
        if (temp->next==NULL)
        {
            printf("There are less than %d nodes !!\n",loc);
            return;
        }
    }
    new_node = malloc(sizeof(DLL_NODE));
    new_node->data = data;
    new_node->next = temp->next;
    temp->next = new_node;
    new_node->prev = temp;
}

void delnode_dll(DLL_NODE **head,int data){
    DLL_NODE *old, *current;
    int flag = 0;
    current = *head;
    if (*head==NULL)
    {
        printf("Your linked list is now empty !!");
        return;
    }else{
        while (current->next!=NULL)
        {   
            if(current->data==data){
                if (current->prev==*head)
                {
                    *head = current->next;
                    current->next->prev = *head;
                    return;
                }else
                {
                    old->next = current->next;
                    current->next->prev = old;
                    return;
                }
            }
            old = current;
            current = current->next;
        }
    }
}

void display_dll(DLL_NODE *head){
    DLL_NODE *temp;
    temp = head;
    if (temp==NULL)
    {
        printf("There is no element is the links list !!");
        return;
    }else{
    
    while (temp!=NULL)
    {        
        if (temp->next==NULL)
        {
            printf("<==>%d<==>",temp->data);            
        }else{
            printf("<==>%d",temp->data);
        }        
        temp = temp->next;
    }
    }    
}
