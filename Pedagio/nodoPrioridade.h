#ifndef __nodoP__
#define __nodoP__

typedef struct nodo_prioridade nodo_prioridade;

struct nodo_prioridade{
	void* elem;
	int prioridade;
	nodo_prioridade *next, *prev;
};

nodo_prioridade* criar_nodo_prioridade(void* object,int prioridade);
nodo_prioridade* next_nodo(nodo_prioridade* current_nodo);
nodo_prioridade* previous_nodo(nodo_prioridade* current_nodo);
void* get_ElemNodo(nodo_prioridade* n);
int get_prioridade(nodo_prioridade* n);

#endif