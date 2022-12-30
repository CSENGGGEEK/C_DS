#include<stdio.h>
#define MAX 10

struct stack{
  int arr[MAX];
  int top;
};

// Initialization of Stack
void init_stack(struct stack *s);
// PUSH Operation on Stack
void push_stack(struct stack *s, int data);
// POP operation on Stack
int pop_stack(struct stack *s);
// print Stack
void display_stack(struct stack *s);

int main(int argc, char const *argv[]) {
  // Initializing stack
  struct stack s;

  init_stack(&s);
  push_stack(&s,10);
  push_stack(&s,20);
  push_stack(&s,30);
  push_stack(&s,40);
  push_stack(&s,50);
  push_stack(&s,60);
  display_stack(&s);
  pop_stack(&s);
  display_stack(&s);
  return 0;
}

void init_stack(struct stack *s){
  s->top = -1;
}

void push_stack(struct stack *s, int data){
  if (s->top==MAX-1) {
    printf("Stack is full !!");
  } else {
    s->top++;
    s->arr[s->top] = data;
  }
}


int pop_stack(struct stack *s){
  if (s->top == -1) {
    printf("Stack is empty !!");
  } else {
    int elm = s->arr[s->top];
    s->arr[s->top] = '\0';
    s->top--;
    return elm;
  }
}

void display_stack(struct stack *s){
  for (int i = 0; i <= s->top; i++) {
    printf("%d\n",s->arr[i]);
  }
}
