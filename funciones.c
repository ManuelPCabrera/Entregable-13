#include "funciones.h"

stack *llenar_dia()
{
    stack *pila = NULL;
    pila = stack_new(NMED);

    int random = rand() % 1441;

    for (int i = 0; i < random; i++)
    {
        reading *dato = (reading *)malloc(sizeof(reading));

        dato->minute = rand() % 1441;
        dato->temperature = rand() % 51 - 10;

        push(pila, *dato);
    }

    return pila;
}

list* cargar_list(stack *pila, int i,list* lista)
{
    //  list *lista = NULL;
    //  lista = list_new(19);

    list_insert(lista, i, *pila);

    return lista;
}
/*
queue* cargar_queue(list* lista,int cant_nodes)
{
     queue* cola = queue_new(cant_nodes*1441);

    for(int i=0; i<cant_nodes ; i++)
    {
    enqueue(lista->head->value.s->);
    }
}
*/



