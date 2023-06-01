#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "funciones.h"


int main()
{
    int random = rand() % 15;
    stack* pila = NULL;
    list* lista = NULL;
    queue* cola = NULL;
    btn* arbol = NULL;

    lista = list_new(19);
    

    for (int i = 0; i < random; i++)
    {
          pila = llenar_dia();
          lista = cargar_list(pila,i,lista);
    }

    printf("%d",lista->head->value.s->temperature);
    arbol = cargar_btn(arbol,lista);
   // cola = queue_new((lista->maxsize)*(1441));

   // cola=cargar_queue(arbol,cola);

    print_queue(cola);
    printf("\n\n\n");
    return 0;
}