#include<stdio.h>
#include<stdlib.h>

// structure of node
struct node{
  int data;
  struct node* link;
};


// type definition
typedef struct node Node;

/* Function declaration */
  // Insertion functions
void append(Node** head,int data);
void add_at_beg(Node** head,int data);
void add_after_node(int node_num,Node** head,int data);
  // Deletion function
void delete(Node** head,int data);
  // print_ll function
void print_ll(Node* head);


int main(int argc, char const *argv[]) {

  // Start pointer
  Node* start = NULL;
  // Function calls
  append(&start,10);
  append(&start,20);
  add_at_beg(&start,30);
  add_after_node(2,&start,40);
  add_after_node(2,&start,50);
  print_ll(start); //
  delete(&start,30);
  print_ll(start); //
  return 0;
}

// Function definitions
void append(Node** head,int data){
  Node* q = *head; // Value of start pointer

  // Creating a new node
  Node* new_node = malloc(sizeof(Node));
  new_node->data = data;
  new_node->link = NULL;

  // Checking if there is no node
  if(*head==NULL){
    *head = new_node;
  }else{
    while (q->link!=NULL) {
      q = q->link;
    }
    q->link = new_node;
  }
}

void add_at_beg(Node** head,int data){
  Node* new_node = malloc(sizeof(Node));
  new_node->data = data;
  new_node->link = *head;
  *head = new_node;
}

void add_after_node(int node_num,Node** head,int data){
  Node* q = *head;
  Node* new_node = malloc(sizeof(Node));
  new_node->data = data;
  for (int i = 0; i < node_num; i++){
    // print_ll
    q=q->link;
    if (q==NULL) {
      printf("These are less than %d number of nodes in linked list !!",node_num);
      return;
    }
  }
  new_node->link = q->link;
  q->link = new_node;
}

void print_ll(Node* head){
  Node* q = head;
  while (q!=NULL) {
    printf("%d ",q->data);
    q = q->link;
  }
}

void delete(Node** head,int data){
  Node *old, *current;
  current = *head;
  while (current!=NULL) {
    if(current->data == data) {
      if (current=*head) {
        *head = current->link;
      }else{
        old->link =  current->link;
        break;
      }
    }else{
      old = current;
      current = current->link;
    }
  }
  free(current);
  return;
}
