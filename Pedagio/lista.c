#include "nodo.h"
#include "lista.h"
#include <stdio.h>
#include <stdlib.h>

/*
	Faz a inicializa��o da LISTA para os valores DEFAULT.
*/
lista *criar_lista(){
	lista* l = malloc(sizeof(lista));
	l->start = NULL;
	l->end = NULL;
	l->size = 0;
	return l;
}

/*
	Retorna o tamanho da lista enviada
*/
int get_size(lista *list){
	return (list->size);
}

/*
	Retorna o elem do nodo equivalente ao index da lista
*/
void* get_index(lista* list, int index)
{
	// Caso lista vazia ou index > size
	if (!list->size || index >= list->size) {
		return NULL;
	}
	
	// Percorre a lista at� pegar o index desejado
	nodo *current = list->start; // index = 0
	int i;
	for (i = 0; i<index; i++) {
		current = current->next;
	}
		
	return current->elem;
}

/*
	Retorna o nodo equivalente ao index da lista
*/
nodo* _get_nodo_index(lista* list, int index)
{
	// Caso lista vazia ou index > size
	if (!list->size || index >= list->size) {
		return NULL;
	}
	
	// Percorre a lista at� pegar o index desejado
	nodo *current = list->start; // index = 0
	int i;
	for (i = 0; i<index; i++) {
		current = current->next;
	}
		
	return current;
}

/*
	Insere um elemento qualquer no in�cio da LISTA.
*/
void inserir_start(lista* list, void* elem){
	nodo *n = criar_nodo(elem);

	// Se tamanho da lista for 0
	if (!list->size) {
		// ent�o o ultimo elemento da lista � n
		list->end = n;
	} 
	else {
		nodo *start = list->start;	// Pega primeiro nodo
		start->prev = n; // Seta nodo anterior de start como N
		n->next = start; // Seta o nodo seguinte de N como start
	}
	
	list->start = n; // Seta primeiro elemento da lista como N
	list->size++; // Incrementa Lista
	return;
}

/*
	Insere o NODO ao final da LISTA.
*/
void inserir(lista* list, void* elem){
	nodo *n = criar_nodo(elem);

	// Se tamanho da lista for 0
	if (!list->size) {
		// J� que n�o h� outros n�s, esse ser� o inicial;
		list->start = n;
	} 
	else {
		nodo *end = list->end; // Pega ultimo nodo
		end->next = n; // Seta proximo nodo de END como N
		n->prev = end; // Seta anterior de N como END
	}

	list->end = n; // Seta N como n� final da lista
	list->size++; // Incrementa tamanho
}

/*
	Insere elemento no index enviado como parametro
*/
void inserir_index(lista* list, void* elem, int index){
	if(index == 0) inserir_start(list, elem); // Caso index seja 0, usa a fun��o insere_start
	else if(index >= list->size) inserir(list, elem); // Caso o index seja maior ou igual ao tamanho da lista, insere no final
	else{
		nodo *novo = criar_nodo(elem);
		nodo* cur = _get_nodo_index(list, index);
		
		novo->next = cur; // 
		novo->prev = cur->prev;
		
		(novo->prev)->next = novo;
		
		cur->prev = novo;
		(list->size)++;		
	}
}

/*
	Remove primeiro elemento da lista
*/
int remover_start(lista* list){
	if(!list->size){
		return 0; // Em caso de falha
	}
	
	nodo *start = list->start; // Pega primeiro elemento
	
	list->start = start->next; // Seta Elemento seguinte como primeiro elemento
	free(start);

	if(list->start != NULL){
		(list->start)->prev = NULL; // Seta anterior do novo primeiro elemento como NULL
	}
	
	(list->size)--;
	
	return 1;
}

/*
	Remove o elemento no index enviado como parametro
*/
int remover_index(lista* list, int index){
	
	if (index >= get_size(list)) return 0;
	else if (index == 0) remover_start(list);
	else if (index == get_size(list)-1) remover_final(list);
	else
	{
		nodo *n = _get_nodo_index(list,index); //Pega o nodo do index
		
		(n->prev)->next = n->next; //Seta o pr�ximo nodo do elemento anterior ao Index
		(n->next)->prev = n->prev; //Seta o nodo anterior do pr�ximo elemento do Index.
		
		free(n);
		
		(list->size)--;
	}
	
	return 1;
}

/*
	Remove ultimo elemento da lista
*/
int remover_final(lista* list){
	if(!list->size){
		return 0; // Em caso de falha
	}
	
	nodo *end = list->end;
	
	list->end = end->prev;
	//free(end->elem); // S� dar free no elemento caso seja um ponteiro!
	free(end);
	
	if(list->end != NULL){ // S� seta caso a lista ainda tenha elementos
		(list->end)->next = NULL;	
	}
	
	(list->size)--;
	return 1; // Em caso de sucesso 
}

/*
	Executa uma fun��o em cada elemento da lista
*/
void funcao_in_lista(lista* list, funcao do_func)
{
  nodo *current = list->start;
  int i;
  for (i = 0; i < list->size; i++) {
    do_func(current->elem);
    current = current->next;
  }
}

/*
	Executa uma fun��o em um unico elemento da lista
*/
void funcao_in_index(lista* list, int index, funcao do_func)
{
  nodo *current = list->start;
  
  int i;
  for (i = 0; i <= index; i++) {
    current = current->next;
  }
  
  do_func(current->elem);
}

/*
	Destr�i a lista inteira
*/
int destruir_lista(lista* list){
	nodo *current = list->start;
	
	int i;
	for(i = 0; i < get_size(list); i++){
		if (current->next == NULL){
			list->end = list->start = NULL; //Seta os valores do in�cio e fim para NULL
			free(current);
		}
		else{
			list->start = current->next;
			// free(current->elem); Caso seja uma struct, precisa dar free no elem
			free(current);
			current = list->start;
		}
	}
	
	free(list);
	
	return 1;
}

