#include <stdio.h>
#include <stdlib.h>

typedef struct sNode Node;

struct sNode {
    int val;
    Node* prev;
};

typedef struct {
    Node* head;
    int len;
} Queue;

void enqueue(Queue* q , int val);
Node dequeue(Queue* q);
Queue* new_queue(void);
void print_queue(Queue* q);
int main()
{
    Queue* q = new_queue();

    enqueue(q, 1);
    enqueue(q, 3);
    enqueue(q, 4);
    enqueue(q, 7);
    enqueue(q, 2);
    print_queue(q);
    Node d = dequeue(q);
    printf("dequeued %d \n" , d.val);
    d = dequeue(q);
    printf("dequeued %d \n" , d.val);
    print_queue(q);
    return 0;
}


Queue* new_queue(void)
{
    Queue* q = malloc(sizeof(Queue));
    q->head = NULL;
    q->len = 0;
    return q;
}

void enqueue(Queue* q , int val)
{
    Node* new_node = malloc(sizeof(Node));
    new_node->val = val;
    q->len++;        
    if (q->head == NULL) {
        q->head = new_node;
        return;
    }
    new_node->prev = q->head;
    q->head = new_node;
    return;
}


Node dequeue(Queue* q) {
    Node temp = *q->head;
    free(q->head);
    q->head = temp.prev;
    return temp;
}

void print_queue(Queue* q) {
    Node* curr = q->head; 
    for (size_t i =0; i < q->len; ++i) {
        printf("Item: %ld, value: %d \n" , i, curr->val);
        curr = curr->prev;
    }
}