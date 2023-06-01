#include "funciones.h"

/////////Construir un TDA, b�sico para las lecturas: crear, borrar,
/////////obtener minuto, obtener temperatura y comparar.

int obtener_minuto (stack* pila)
{
    return (pila->s->minute);
}


 
int obtener_temperatura(stack* pila)
{
    return (pila->s->temperature);
}


int cmp(t_elem_btree a , t_elem_btree b)
{
  if (a.minute > b.minute)
  {
    return 1;
  }
  else if (a.minute < b.minute)
  {
    return 2;
  }    
  else if (a.minute == a.minute)
  {
    if (a.temperature < b.temperature) 
    {
        return 3;
    }
    else if ((a.temperature < b.temperature))
    {
        return 4;
    }
  }  
}

