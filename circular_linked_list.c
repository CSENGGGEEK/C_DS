#include <stdio.h>
#include <stdlib.h>

struct circ_node{
  int data;
  struct circ_node *link;
};

typedef struct circ_node CIRC_NODE;

// Function declaration
void circ_add_at_beg(CIRC_NODE **start,int data);
void circ_add_after_node(CIRC_NODE **start,int data);
void circ_append(CIRC_NODE **start,int data);
void display(CIRC_NODE *start);

int main(int argc, char const *argv[]) {
  CIRC_NODE *start;
  start = NULL;
  circ_append(&start,10);
  circ_append(&start,20);
  // display(start);
  return 0;
}

void circ_append(CIRC_NODE **start,int data) {
  CIRC_NODE *new_node, *head = *start;
  new_node = malloc(sizeof(CIRC_NODE));
  new_node->link = *start;
  new_node->data = data;
  if (*start != NULL) {
    while (1) {
      head = head->link;
      if (head == *start) {
        head->link = *start;
        return;
      }
    }
    head->link = new_node;
  }else{
    *start = new_node;
  }
}

void display(CIRC_NODE *start){
  CIRC_NODE *temp = start;
  while (temp != start) {
    printf("%d\n",temp->data);
    temp = temp->link;
  }
}

// head -> n1 -> n2 -> n3 -> n4 -> head
