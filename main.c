#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "funciones.h"


int main()
{
    int random = rand() % 15;
    stack* pila = NULL;
    list *lista = NULL;

    lista = list_new(19);

    for (int i = 0; i < random; i++)
    {
          pila = llenar_dia();
          lista = cargar_list(pila,i,lista);
    }

    //printf("%d",lista->head->value.s->temperature);

    //cargar_queue(lista,random);

    return 0;
}
