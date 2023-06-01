#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define NMED 1442
///////////////////////////////////////////////////////////

typedef struct
{
    int minute;
    int temperature;

} reading;


//////////////////////TDA PILA///////////////////////////

#define t_elems reading

typedef struct _stack {
  t_elems* s;
  int top;
  int maxsize;
} stack;

stack* stack_new(int maxsize);
void stack_free(stack* s);
int stack_getsize(stack* s);
int stack_getmaxsize(stack* s);
void push(stack* s, t_elems elem);
t_elems pop(stack* s);
t_elems top(stack* s);/////#define t_elem reading
int stack_isempty(stack* s);
int stack_isfull(stack* s);
void stack_destroy(stack* s, void elem_free(t_elems));

///////////////////////TDA COLA////////////////////////////

//#define t_element reading

typedef struct _queue{
    t_elems* a;
    int head;   //mark the first element
    int tail;   //mark the next empty position
    int maxsize;
    int count;
} queue;

queue* queue_new(int maxsize);
void queue_free (queue* q);
int queue_getmaxsize(queue* q);
int queue_getsize(queue* q);
int queue_isfull (queue* q);
int queue_isempty (queue* q);
void enqueue (queue* q, t_elems elem);
t_elems dequeue (queue* q);
t_elems peek (queue* q);


///////////////////////TDA LISTA////////////////////////////


#define t_elem_list stack
#define bool int
#define true 1
#define false 0

typedef struct list_node
{
    t_elem_list value;
    struct list_node *next;
} list_node;

typedef struct list
{
    list_node *head;
    int maxsize;
    int count;
} list;


list *list_new(int maxsize);
bool list_isempty(list *L);
bool list_isfull(list *L);
int list_length(list *L);
t_elem_list list_get(list *L, int index);
//t_elem_list list_search(list *L, t_elem_list elem);
int list_search(list *L, t_elem_list elem);
void list_insert(list *L, int index, t_elem_list elem);
void list_delete(list *L, int index);
void list_traverse(list *L, bool look(int elem, int index, void *ctx), void *ctx);

/////////////////////////// Temp.Tree ////////////////////////////
#define t_elem_btree reading

typedef struct _btn
{
    t_elem_btree value;
    struct _btn *left;
    struct _btn *right;
}btn;

int cmp(t_elem_btree a, t_elem_btree b);

btn* btn_new(t_elem_btree value);
void btn_free(btn** node);
int is_empty(btn *b);
int sbt_insert_node(btn **node, btn *newNode, int cmp(t_elem_btree,t_elem_btree));
int sbt_insert_value(btn **node, t_elem_btree *value, int cmp (t_elem_btree, t_elem_btree));
int btn_count(btn *node);
void btn_do_print_ctx (btn* node, void* ctx);
void btn_intToStr(btn* node, char* str);
int _btn_print(btn *tree, int is_left, int offset, int depth, char s[20][255], void toStr (btn*, char*));
void btn_print(btn *tree, void toStr (btn*, char*));
//////////////CHEKEAR LOS (;)
//void btn_inorder(btn *node);

//////////////////////////TDA_basicos///////////////////////////

int obtener_temperatura(stack* pila);
int obtener_minuto (stack* pila);

//////////////////////////FUNCIONES////////////////////////////

stack *llenar_dia();
list* cargar_list(stack *pila, int i,list* lista);
btn* cargar_btn(btn *arbol ,list* lista);
//queue* cargar_queue(btn* node,queue* cola);
//queue* sortbyminute_queue(queue* cola);
void print_queue(queue* cola);





#endif // FUNCIONES_H_INCLUDED
