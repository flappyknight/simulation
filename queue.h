#include <stdlib.h>

typedef struct {
    double mass;
    double velocity;
    double x;
} Item;


typedef struct Node {
    void *item;
    struct Node *next;
} Node;

typedef struct {
    Node *front;
    Node *rear;
    int counts;
} Queue;

void init_queue(Queue *queue);

void add_item(Queue *queue,const void *item);

void pop_item(Queue *queue, void **item);

void clear_queue(Queue *queue);

void traverse_queue(Queue *queue, void (*func)(void*, void*), void* additional_arg);


