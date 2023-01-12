#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *link;
};

int count(struct node **);
void append_sll(struct node **,int);
void nth_last_ll(struct node **,int,int);
int nth_last_ll_opt(struct node **,int);

int main(int argc, char const *argv[])
{
    struct node *head = NULL;
    int res;
    for(int i = 0;i < 10;i++){
        append_sll(&head,i);
    }
    res = count(&head);
    nth_last_ll(&head,res,1);
    res = nth_last_ll_opt(&head,1);
    printf("%d",res);
    return 0;
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

int count(struct node **head){
    int count = 0;
    struct node *temp;
    temp = *head;
    while(temp->link != NULL){
        count++;
        temp = temp->link;
    }
    return count;
}

void nth_last_ll(struct node **head,int count,int n){
    struct node *temp = *head;
    if(n>count){
        printf("There are less number of nodes int the linked list !!");
    }else{
        for (int i = 0; i < (count-n); i++)
        {
            temp = temp->link;
        }
        printf("%d",temp->data);
    }
}


int nth_last_ll_opt(struct node **head,int n){
    struct node *temp = *head;
    int array[50] = {};
    int i = 1;
    while(temp->link != NULL){
        array[i] = temp->data;
        temp = temp->link;
        i++;
    }
    return array[i-n];
}