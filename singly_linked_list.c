#include <stdio.h>
#include <stdlib.h>

// Structure of a node
struct node
{
  int data;
  struct node *link;
};

// Declatration of functions
void disp_sll(struct node *head);
void append_sll(struct node **head, int data);
void addbeg_sll(struct node **head, int data);
void addaft_sll(struct node **head, int data, int loc);
void delnode_sll(struct node **head, int loc);

void main()
{
  struct node *head;
  head = NULL;
  append_sll(&head, 10); /* code */
  append_sll(&head, 20);
  append_sll(&head, 30);
  addbeg_sll(&head, 40);
  addbeg_sll(&head, 70);
  delnode_sll(&head, 10);
  addbeg_sll(&head, 80);
  addbeg_sll(&head, 90);
  addbeg_sll(&head, 100);
  append_sll(&head, 120);
  addaft_sll(&head,50,5);
  addaft_sll(&head,500,100);
  printf("head-->");
  disp_sll(head);
  printf("NULL");
}

void disp_sll(struct node *head)
{
  struct node *temp;
  temp = head;
  while (temp != NULL)
  { 
    printf("%d-->", temp->data);
    temp = temp->link;
  }
}

void append_sll(struct node **head, int data)
{
  struct node *temp, *new_node;
  temp = *head;
  new_node = malloc(sizeof(struct node));
  new_node->data = data;
  new_node->link = NULL;
  if (*head == NULL)
  {
    *head = new_node;
  }
  else
  {
    while (temp->link != NULL)
    {
      temp = temp->link;
    }
    temp->link = new_node;
  }
}

void addbeg_sll(struct node **head, int data)
{
  struct node *new_node;
  new_node = malloc(sizeof(struct node));
  new_node->data = data;
  new_node->link = *head;
  *head = new_node;
}

void addaft_sll(struct node **head, int data, int loc){
  struct node *new_node, *temp;
  temp = *head;
  for (int i = 0; i < loc; i++){
    temp = temp->link;
    if (temp->link == NULL)
    {
      printf("There  are less than %d nodes !! \n", loc);
      return;
    }
  }
  new_node = malloc(sizeof(struct node));
  new_node->data = data;
  new_node->link = temp->link;
  temp->link = new_node;
}

void delnode_sll(struct node **head, int data)
{
  struct node *temp, *prev;
  temp = *head;
  while (temp != NULL)
  {
    if (temp->data == data)
    {
      if (temp == *head)
      {
        *head = temp->link;
        break;
      }
      else
      {
        prev->link = temp->link;
        break;
      }
    }
    else
    {
      prev = temp;
      temp = temp->link;
    }
  }
  free(temp);
  return;
}