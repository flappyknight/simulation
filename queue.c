#include "queue.h"

void init_queue(Queue *queue)
{
    queue->front = queue->rear = NULL;
    queue->counts = 0;
}

void add_item(Queue *queue, const void *item)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->item = item;
    node->next = NULL;
    if (queue->rear == NULL)
    {
        queue->front = queue->rear = node;
    }
    else
    {
        queue->rear->next = node;
        queue->rear = node;
    }
    queue->counts++;
}

void pop_item(Queue *queue, void **item)
{
    if (queue->front == NULL)
    {
        return;
    }
    *item = queue->front->item;
    Node *node = queue->front;
    queue->front = queue->front->next;
    free(node);
    queue->counts--;
}

void clear_queue(Queue *queue)
{
    while (queue->front != NULL)
    {
        Node *node = queue->front;
        queue->front = queue->front->next;
        free(node);
    }
    queue->rear = NULL;
    queue->counts = 0;
}

void traverse_queue(Queue *queue, void (*func)(void*, void*), void* additional_arg) {
    Node *current = queue->front;
    while (current != NULL) {
        func(current->item, additional_arg);  // 传递队列元素和额外参数
        current = current->next;
    }
}