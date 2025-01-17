#include <stdlib.h>

typedef struct {
    double mass;
    double velocity;
    double x;
} Item;


typedef struct Node {
    Item item;
    struct Node *next;
} Node;

typedef struct {
    Node *front;
    Node *rear;
    int counts;
} Queue;

void init_queue(Queue *queue);

void add_item(Queue *queue,const Item *item);

void pop_item(Queue *queue, Item *item);

void clear_queue(Queue *queue);

void traverse_queue(Queue *queue, void (*func)(Item *));

static void copy_node(Node *dest, Node *src);

