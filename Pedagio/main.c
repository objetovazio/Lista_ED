#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "veiculo.h"
#include "lista.h"
#include "filaPrioridade.h"

void printfilas(lista *l){
	int i;
	for(i = 0; i < get_size(l); i++)
	{
		fila_prioridade *f = (fila_prioridade*)get_index(l, i);
		
		int j;
		for(j = 0; j < get_size_fila(f); j++){
			Veiculo *v = (Veiculo*)get_index_fila(f, j);
			printf("%c ", get_tipo(v));
		}
		printf(" - end\n");	
	}
}

int main(int argc, char *argv[]) {
	int filas = 2; //atoi(argv[1]);
	char *entrada = "P P M G M M M P P G G P M P M M M M M M M G M M M P P P M P P P P";

	lista *listaFilas = criar_lista();
	
	int i;
	for(i = 0; i < filas; i++){
		inserir(listaFilas, criar_fila_prioridade());
	}
	
	int pos = 0;
	for(i = 0; i < strlen(entrada); i += 2){
		Veiculo *v = criar_veiculo(entrada[i]);
		
		fila_prioridade *f = get_index(listaFilas, pos);
		
		inserir_prioridade(f, v, v->Prioridade);
		
		if(pos == filas - 1) pos = 0;
		else pos++;
	}
	
	printfilas(listaFilas);
	
	Veiculo *v = criar_veiculo('P');
	
	printf("%f %c %d", v->Valor, v->Tipo, v->TempoPassagem);
	
	return 0;
}
