#include <stdio.h>
#include <stdlib.h>
#include "lista_ordenada.h"
#include <time.h>

void print_lista(lista *list){
	int i;
	
	for(i = 0; i < get_size(list); i++){
		printf("%d ", get_index(list, i));
	}
	printf("-\n");
}

int comp(int a, int b){
	if(a == b) return 0;
	if(a > b) return -1;
	if(a < b) return 1;
}

int main(int argc,char **argv){
	lista* l;
	l = criar_lista(comp);
	srand(time(NULL));   // should only be called once
	 
	printf("start\n");
	
	int *i = (int *)malloc(sizeof(int));
	for(*i = 10; *i > 0; *i = *i - 1){
		inserir_ordenado(l, rand() % 100);
	}
	
	if(remover_index(l, 5)){
		print_lista(l);
	}
	
	destruir_lista(l);
	
	printf("end");
	
	return 0;
}
