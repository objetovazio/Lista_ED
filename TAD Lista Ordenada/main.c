#include <stdio.h>
#include <stdlib.h>
#include "lista_ordenada.h"
#include <stdlib.h>
#include <stdio.h>

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
	
	
	printf("asd\n");
	
	int *i = (int *)malloc(sizeof(int));
	for(*i = 10; *i > 0; *i = *i - 1){
		inserir(l, *i);
	}
	
	
	
	print_lista(l);
	
	if(remover_index(l, 5)){
		print_lista(l);
	}
	
	destruir_lista(l);
	
	printf("end");
	
	return 0;
}
