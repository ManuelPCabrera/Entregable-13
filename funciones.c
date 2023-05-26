#include "funciones.h"
#include "TDA_lista.h"

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

        stack_push(pila, *dato);
    }

    return pila;
}

list cargar_list (stack* pila)
{





}