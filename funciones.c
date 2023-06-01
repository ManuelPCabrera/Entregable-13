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
queue* cargar_queue(list* lista)
{
     

    list_node *aux = lista->head;
    while (aux != NULL)
    {
        stack* pila = &(aux->value);
        while (!stack_isempty(pila))
        {
            reading medida = pop(pila);
            enqueue(cola,medida);

        }
        
        aux = aux->next;
    }
    
return cola;
   
}

queue* sortbyminute_queue(queue* cola)
{

cola->

}
*/

btn* cargar_btn(btn *arbol ,list* lista)
{

    list_node *aux = lista->head;
    stack* pila= &(aux->value);
    arbol->value = pop(pila);

 //btn_new(pop(pila));

    while (aux != NULL){
        while (!stack_isempty(pila))
        {
            btn *new_node = btn_new(pop(pila));
            sbt_insert_node(&arbol,new_node,cmp(arbol->value,new_node->value));
            //reading medida = pop(pila); 
        }
    aux = aux->next;
    }
return arbol;
}

queue* cargar_queue(btn *node,queue* cola)
{
    if (!node) return;
    
    cargar_queue(node->left, cola);
    
    enqueue(cola,node->value);

    cargar_queue(node->right, cola);

    return cola;
}


void print_queue(queue* cola) {
    if (cola == NULL || cola->count == 0) {
        printf("La cola está vacía.\n");
        return;
    }

    int i, j;
    j = cola->head;

    for (i = 0; i < cola->count; i++) {
        printf("%d ", cola->a[j]);
        j = (j + 1) % cola->maxsize;
    }

    printf("\n");
}
