#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "veiculo.h"
#include "lista.h"
#include "filaPrioridade.h"

struct Tuple {
    int tempo_total;
    float valor_arrecadado;
    int total_p, total_m, total_g;
    int total_veiculos;
};


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
		printf("-\n");	
	}
}

void cria_filas_pedagio(lista *lista_filas, int qtd_filas){
	int i;
	for(i = 0; i < qtd_filas; i++){
		inserir(lista_filas, criar_fila_prioridade());
	}
}

void preenche_filas_pedagio(lista *lista_filas, char *entrada){
	int i, pos = 0;
	for(i = 0; i < strlen(entrada); i += 2){
		Veiculo *v = criar_veiculo(entrada[i]);
		
		fila_prioridade *f = get_index(lista_filas, pos);
		
		inserir_prioridade(f, v, v->Prioridade);
		
		if(pos == get_size(lista_filas) - 1) pos = 0;
		else pos++;
	}
}


int main(int argc, char *argv[]) {
	int filas = 2; //atoi(argv[1]);
	char *entrada = "P P M G M M M P P G G P M P M M M M M M M G M M M P P P M P P P P";
	int hora_flag = 60, tempo_atual = 0;
	double valor_arrecadado = 0.0;

	lista *listaFilas = criar_lista();
	
	cria_filas_pedagio(listaFilas, filas);
	
	preenche_filas_pedagio(listaFilas, entrada);
	
	int i;
	Veiculo *veiculoPrincipal;
	while(get_size(listaFilas) != 0){
		for(i = 0; i < get_size(listaFilas); i++){
			fila_prioridade *fila = (fila_prioridade*)get_index(listaFilas, i);
			
			if(get_size_fila(fila) == 0){
				remover_index(listaFilas, i);
				break;
			} 
			
			Veiculo *v = peek(fila);
			
		}	
		break;
	}
	
	printf("%d fila(s)", filas);
	Tuple valores_finais = malloc(sizeof(Tuple));
	
	
	
	for(i = 0; i < )
	
	
	
	
	
	printfilas(listaFilas);
	
	return 0;
}
