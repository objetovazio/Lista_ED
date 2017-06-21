#include <stdio.h>
#include <stdlib.h>
#include "filaPrioridade.h"

void printfila(fila_prioridade *f){
	int i;
	
	for(i = 0; i < f->tam; i++){		
		printf("%d ", ((int*)get_index(f, i)));;
	}
	printf("\n");
}

int main(int argc,char **argv){
	fila_prioridade *f = criar_fila_prioridade();
	
	int i;
	for(i = 0; i < 10; i++){
		inserir_prioridade(f, i, 0);
	}
		
	printfila(f);
	
	inserir_prioridade(f, 20, 1);
	inserir_prioridade(f, 21, 0);
	inserir_prioridade(f, 22, 3);
	inserir_prioridade(f, 23, 2);
	
	printfila(f);
	
	return 0;
}

