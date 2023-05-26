#include "funciones.h"

queue* queue_copy (queue* q)
{
    queue* aux = queue_new(queue_getmaxsize(q));
    while (!queue_isempty(q))
    {
        enqueue(aux, dequeue(q));
    }

    queue* result = queue_new(queue_getmaxsize(aux));
    while (!queue_isempty(aux))
    {
        enqueue(q, peek(aux));
        enqueue(result, dequeue(aux));
    }
    queue_free(aux);
    return result;
}

queue *queue_new(int maxsize)
{
    queue* q = (queue*)malloc(sizeof(queue));

    q->head = NULL;
    q->tail = NULL;
    q->maxsize = maxsize;
    q->count = 0;

    return q;
}

queue_node *node_new_queue(t_elem value)
{
    queue_node *nodo = (queue_node*)malloc(sizeof(queue_node));
    nodo->value = value;
    nodo->next = NULL;

    return(nodo);
}

void node_free_queue(queue_node *nodo)
{
    ///nodo->value = NULL;
    nodo->next = NULL;
    free(nodo);
}

void queue_free(queue* q)
{
    while(q->head)
    {
        dequeue(q);
    }
    free(q);
}

int queue_getsize(queue* q)
{
    return (q->count);
}

int queue_getmaxsize(queue* q)
{
    return (q->maxsize);
}

int queue_isfull(queue* q)
{
    if(q->count == q->maxsize)
    {
        return 1;
    }
    return 0;
}

int queue_isempty(queue* q)
{
    if(q->count == 0)
    {
        return 1;
    }
    return 0;
}

void enqueue(queue* q, t_elem elem)
{
    queue_node *nodo = node_new_queue(elem);

    if(!q->head)
    {
        q->head = nodo;
        q->tail = nodo;
        q->count++;
    }
    else
    {
        q->tail->next = nodo;
        q->tail = nodo;
        q->count++;
    }
}

t_elem dequeue(queue* q)
{
    if(q->head)
    {
        t_elem aux = q->head->value;

        queue_node* eliminado = q->head;
        q->head = q->head->next;
        node_free_queue(eliminado);

        return aux;
    }

    if(!q->head)
    {
        q->tail = NULL;
    }

    return ;
}

t_elem peek(queue* q)
{
    if(q->head)
    {
        return (q->head->value);
    }
    else
    {
        return ;
    }
}
