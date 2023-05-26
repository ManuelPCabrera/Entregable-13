#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define NMED 1000
#define t_elem reading

typedef struct
{
    int minute;
    int temperature;
} reading;


//////////////////////TDA PILA///////////////////////////

typedef struct stack_node
{
    t_elem value;
    struct stack_node *next;
} stack_node;

typedef struct stack
{
    stack_node *head;
    int maxsize;
    int count;
} stack;

stack *stack_new(int maxsize);
stack_node *node_new_stack(t_elem value);
void stack_free_stack(stack* s);
void node_free(stack_node *h);
int stack_push(stack* pila, t_elem elem);
t_elem stack_pop(stack* pila);
t_elem top(stack* pila);
int stack_getsize(stack* pila);
int stack_getmaxsize(stack* pila);
void stack_destroy(stack* pila, void elem_free(t_elem));
int stack_isempty(stack* pila);
int stack_isfull(stack* pila);
stack *stack_copy(stack* s);

///////////////////////TDA COLA////////////////////////////

typedef struct queue_node
{
    t_elem value;
    struct queue_node *next;
} queue_node;

typedef struct queue
{
    queue_node *head;
    queue_node *tail;
    int maxsize;
    int count;
} queue;

queue* queue_new(int maxsize);
queue_node *node_new(t_elem value);
void node_free_queue(queue_node *nodo);
void queue_free (queue* q);
int queue_getsize (queue* q);
int queue_getmaxsize (queue* q);
int queue_isfull (queue* q);
int queue_isempty (queue* q);
void enqueue (queue* q, t_elem elem);
t_elem dequeue (queue* q);
t_elem peek (queue* q);
queue* queue_copy (queue* q);

//////////////////////////FUNCIONES////////////////////////////

stack *llenar();



#endif // FUNCIONES_H_INCLUDED
