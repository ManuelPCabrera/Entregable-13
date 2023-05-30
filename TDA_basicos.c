#include "funciones.h"

/////////Construir un TDA, básico para las lecturas: crear, borrar,
/////////obtener minuto, obtener temperatura y comparar.

int obtener_minuto (stack* pila)
{
    return (pila->s->minute);
}

int obtener_temperatura(stack* pila)
{
    return (pila->s->temperature);
}

/**
int comparar_()
{



}
**/
