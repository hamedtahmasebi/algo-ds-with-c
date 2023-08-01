#include <stdio.h>
#include <stdlib.h>
typedef struct sNode Node;
struct sNode {
    int val;
    Node* prev;
};

typedef struct {
    int len;
    Node* head;
} Stack;


Node pop(Stack* stack);
Stack* new_stack(void);
void push(Stack* stack ,int val);
void print_stack(Stack* stack);
Node* peek(Stack* stack);
int main() 
{
    Stack* my_stack = new_stack();

    printf("Pushed: %d\n" , 2);
    push(my_stack , 2);

    printf("Pushed: %d\n" , 5);
    push(my_stack , 5);

    Node* f;

    Node node = pop(my_stack);
    printf("Popped: %d\n" , node.val);

    f = peek(my_stack);
    printf("Peeked %d\n" , f->val);

    node = pop(my_stack);
    printf("Popped %d\n" , node.val);


    print_stack(my_stack);
    /* code */
    return 0;
}


Node pop(Stack* stack)
{
    if (stack->head == NULL) {
        Node empty = { .val = -1, .prev = NULL };
        return empty;
    }
    Node temp = *stack->head;
    free(stack->head);
    stack->head = temp.prev;
    
    stack->len--;
    return temp;
}

void push(Stack* stack , int val)
{
    Node* newNode = malloc(sizeof(Node));
    newNode->val = val;
    stack->len++;
    if (stack->head == NULL) {
        newNode->prev = NULL;
        stack->head = newNode; 
        return;
    }
    newNode->prev = stack->head;
    stack->head = newNode;
    return;
}

void print_stack(Stack* s)
{
   if (s->len <= 0) return;
   Node* curr = s->head;
   for (size_t i = 0; i < s->len; i++)
   {
    printf("%d\n" , curr->val);
    curr = curr->prev;
   }
   
} 

Stack* new_stack()
{
    Stack* s = malloc(sizeof(Stack));
    s->head = NULL;
    s->len = 0;
    return s;
}


Node* peek(Stack* stack) {
    if (stack->head == NULL) {
        return NULL;
    }
    return stack->head;
}