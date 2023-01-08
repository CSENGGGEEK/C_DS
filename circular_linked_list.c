#include<stdio.h>
#include<stdlib.h>

struct node {
  int data;
  struct node *link;
};

void display_cll(struct node**,struct node **);
void append_cll(struct node**,struct node **,int data);
void addaft_cll(struct node**,struct node **,int data,int loc);
void addbeg_cll(struct node**,struct node **,int data);

int main(int argc, char const *argv[])
{
  struct node *head,*tail;
  head = NULL;
  tail =  NULL;
  addbeg_cll(&head,&tail,10);
  append_cll(&head,&tail,50);
  append_cll(&head,&tail,1);
  append_cll(&head,&tail,2);
  append_cll(&head,&tail,3);
  append_cll(&head,&tail,20);
  addaft_cll(&head,&tail,3,1);
  addaft_cll(&head,&tail,4,2);
  display_cll(&head,&tail);
  return 0;
}

void append_cll(struct node **head,struct node **tail,int data){
  struct node *temp,*new_node;
  new_node = malloc(sizeof(struct node));
  new_node->data = data;
  if(*head==NULL){
    *head = new_node;
    new_node->link = *head;
    *tail = new_node;
  }else
  {
    temp = *tail;
    temp->link = new_node;
    *tail = new_node;
    new_node->link = *head;
  }
}

void addaft_cll(struct node **head,struct node **tail,int data,int loc){
  struct node *temp,*new_node;
  temp = *head;
  for (int i = 0; i < loc; i++)
  {
    temp = temp->link;
    if (temp->link==*tail)
    {
      printf("There are less than %d nodes !!",loc);
      return;
    }
  }  
  new_node = malloc(sizeof(struct node));
  new_node->data = data;
  new_node->link = temp->link;
  temp->link = new_node;
}

void addbeg_cll(struct node **head,struct node **tail,int data){
  struct node *temp,*new_node;
  new_node = malloc(sizeof(struct node));
  new_node->data = data;
  if (*head==NULL)
  {
    *head = new_node;
    *tail = new_node;
    new_node->link = *head;
  }
  else
  {
    temp = *head;
    while (temp->link!=*head)
    {
      temp = temp->link;
    }
    temp->link = new_node;
    new_node->link = *head;
    *head = new_node;
  }
  return;
}

void display_cll(struct node **head,struct node **tail){
  struct node *temp;
  temp = *head;
  do{
    printf("%d ",temp->data);
    temp=temp->link;
  }while (temp->link!=*head);
  if (temp->link == *head)
  {
    printf("%d ",temp->data);
  }
  
}
