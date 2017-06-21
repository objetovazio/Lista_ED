#include <stdio.h>
#include <stdlib.h>
#include "filaPrioridade.h"

void printfila(fila_prioridade *f){
	int i;
	
	for(i = 0; i < f->tam; i++){		
		printf("%d ", ((int*)peek(f)));
		pop_Elem(f);
	}
}

int main(int argc,char **argv){
	fila_prioridade *f = criar_fila_prioridade();
	
	int i;
	for(i = 0; i < 10; i++){
		inserir_prioridade(f, i, 0);
		printfila(f);
	}
	
	printf("asd\n");
	
	printfila(f);
	
	//inserir_prioridade(f, 99, 1);
	
	printfila(f);
	
	return 0;
}

