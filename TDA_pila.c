#include "funciones.h"

stack* stack_copy(stack* s)
{
    stack* aux = stack_new(stack_getmaxsize(s));
    while (!stack_isempty(s))
    {
        stack_push(aux, stack_pop(s));
    }

    stack* result = stack_new(stack_getmaxsize(s));
    while (!stack_isempty(aux))
    {
        stack_push(s,top(aux));
        stack_push(result, stack_pop(aux));
    }

    return result;
}

stack *stack_new(int maxsize)
{
    stack *pila = (stack*)malloc(sizeof(stack));
    if(pila != NULL)
    {
        pila->head = NULL;
        pila->count = 0;
        pila->maxsize = maxsize;
    }
    return pila;
}

stack_node *node_new_stack(t_elem value)
{
    stack_node *nodo = (stack_node*)malloc(sizeof(stack_node));
    nodo->value = value;
    nodo->next = NULL;

    return(nodo);
}

void node_free_stack(stack_node *head)
{
    stack_node *aux = NULL;
    while(head != NULL)
    {
        aux = head->next;
        free(head);
        head = aux;
    }
}

void stack_free(stack* s)
{
    node_free_stack(s->head);
    free(s);
}

int stack_push(stack* pila, t_elem elem)
{
    stack_node *nodo = node_new_stack(elem);
    int aux = 0;

    if(nodo != NULL)
    {
        nodo->next = pila->head;
        pila->head = nodo;
        pila->count++;
        aux++;
    }
    return (aux);
}

t_elem stack_pop(stack* pila)
{
    if(pila->head != NULL)
    {
        t_elem aux = pila->head->value;

        stack_node *eliminar = pila->head;
        pila->head = pila->head->next;
        free(eliminar);
        pila->count--;

        return(aux);
    }

    return;
}

t_elem top(stack* pila)
{
    if(pila->head == NULL)
    {
        return;
    }
    else
    {
        return(pila->head->value);
    }
}

int stack_getsize(stack* pila)
{
    return(pila->count);
}

int stack_getmaxsize(stack* pila)
{
    return(pila->maxsize);
}

void stack_destroy(stack* pila, void elem_free(t_elem))
{
    while(pila->head != NULL)
    {
        stack_pop(pila);
    }
    free(pila);
}

int stack_isempty(stack* pila)
{
    if(pila->count == 0)
    {
        return (1);
    }

    return(0);
}

int stack_isfull(stack* pila)
{
    if(pila->count == pila->maxsize)
    {
        return (1);
    }

    return(0);
}

