#include <stdio.h>

typedef struct {
    int *queue;
    int rsp;
} Queue;

void push(Queue *queue, int value) {
    queue->queue[queue->rsp] = value;
    queue->rsp = queue->rsp + 1;
}

int pop(Queue *queue) {
    if (queue->rsp == 0) {
        return 0;
    }

    int res = queue->queue[0];

    for (unsigned i = 0; i < queue->rsp; i++) {
        queue->queue[i] = queue->queue[i + 1];
    }

    queue->rsp = queue->rsp - 1;
    
    return res;
}

int main() {
    Queue *queue;
    queue->queue[5];
    
    push(queue, 3);
    push(queue, 2);

    printf("%u\n", queue->queue[0]); // 3

    printf("%u\n", pop(queue)); // 3

    printf("%u\n", queue->queue[0]); // 2
}