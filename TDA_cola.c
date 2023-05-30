#include "funciones.h"

#include <stdio.h>
#include <stdlib.h>



queue* queue_new(int maxsize){
    queue* q = (queue*)malloc(sizeof(queue));
    q->a = (t_elemt*)malloc(sizeof(t_elemt)*maxsize);
    q->head = 0;
    q->tail = 0;
    q->maxsize = maxsize;
    q->count = 0;
    return q;
}

void queue_free (queue* q){
    free(q->a);
    free(q);
}

int queue_getmaxsize(queue* q){
    return q->maxsize;
}

int queue_getsize(queue* q){
    return q->count;
}

int queue_isfull (queue* q){
    //return (q->count == q->maxsize)?1:0;
    return q->count == q->maxsize;
}

int queue_isempty (queue* q){
    //return (q->count == 0)?1:0;
    return q->count == 0;
}

void enqueue (queue* q, t_elemt elem){
    if (queue_isfull(q)){
        printf("Queue overflow\n");
        exit(1);
    }

    q->a[q->tail] = elem;
    q->tail = (q->tail+1)%(q->maxsize);
    q->count++;
}

t_elemt dequeue (queue* q){

    if (queue_isempty(q)){
        printf("Queue underflow\n");
        exit(1);
    }

    t_elemt result = (t_elemt) q->a[q->head];
    q->head = (q->head+1)%(q->maxsize);
    q->count--;
    return result;
}

t_elemt peek (queue* q){
    if (queue_isempty(q)){
        printf("Queue underflow\n");
        exit(1);
    }
    return q->a[q->head];
}
