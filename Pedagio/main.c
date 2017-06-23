#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "veiculo.h"
#include "lista.h"
#include "filaPrioridade.h"

typedef struct Tuple {
    int tempo_total;
    float valor_arrecadado;
    int total_p, total_m, total_g;
    int total_veiculos;
} Tuple;


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
	lista *lista_veiculos = criar_lista();
	
	printf("Reading: ");
	Veiculo *veic;
	char c = getchar();
	while (c != EOF && c != '\n'){
		veic = criar_veiculo(c);
		if(veic != NULL){
			inserir(lista_filas, veic);
		}
		c = getchar();
	}
	
	int i, pos = 0;
	for(i = 0; i < get_size(lista_veiculos); i += 1){
		printf("asd");
		Veiculo *v = get_index(lista_veiculos, i);
		
		fila_prioridade *f = get_index(lista_filas, pos);
		
		inserir_prioridade(f, v, v->Prioridade);
		
		if(pos == get_size(lista_filas) - 1) pos = 0;
		else pos++;
	}
}

Tuple* inicializa_valores_finais(){
	Tuple *valores_finais = malloc(sizeof(Tuple));
	valores_finais->tempo_total = 0;
	valores_finais->total_g = 0;
	valores_finais->total_m = 0;
	valores_finais->total_p = 0;
	valores_finais->total_veiculos = 0;
	valores_finais->valor_arrecadado = 0;
	
	return valores_finais;
}

void zera_veiculos(Tuple *valores){
	valores->total_g = 0;
	valores->total_m = 0;
	valores->total_p = 0;
}

int main(int argc, char *argv[]) {
	int filas = 2; //atoi(argv[1]);
	char *entrada = "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG";
	int hora_flag = 60, tempo_atual = 0;
	double valor_arrecadado = 0.0;

	lista *listaFilas = criar_lista();
	
	cria_filas_pedagio(listaFilas, filas);
	
	preenche_filas_pedagio(listaFilas, entrada);
	
	printf("%d fila(s)\n", filas);
	Tuple *valores_finais = inicializa_valores_finais();
	printf("aqui");
	
	while(get_size(listaFilas)){
		int popped = 0;
		
		int i;
		for(i = 0; i < get_size(listaFilas); i++){
			fila_prioridade *fila = (fila_prioridade*)get_index(listaFilas, i);
			printf("aqui X");
			if(valores_finais->tempo_total >= hora_flag){
				printf("%d min: %.2f (%dM, %dP, %dG)\n", hora_flag, valores_finais->valor_arrecadado, 
					valores_finais->total_m, valores_finais->total_p, valores_finais->total_g);
				hora_flag += 60;
				zera_veiculos(valores_finais);
			}
			printf("aqui Y");
			Veiculo *v = peek(fila);
			
			if(!popped){
				
				tempo_atual += v->TempoPassagem;
				printf("aqui Z"); // TODO: ERRO AQUI AF TNC
				popped = 1;
			}
			
			
			
			valores_finais->valor_arrecadado += v->Valor;
			
			switch(v->Tipo){
				case('P'):
					valores_finais->total_p += 1;
					break;
				case('G'):
					valores_finais->total_g += 1;
					break;
				case('M'):
					valores_finais->total_m += 1;
					break;
			}
			
			valores_finais->total_veiculos += 1;
			
			pop_Elem(fila);
			
			if(!get_size_fila(fila)){
				remover_index(listaFilas, i);
			}
		}
			
		
	}
	
	if(valores_finais->tempo_total){
		printf("%d min: %.2f (%dM, %dP, %dG)\n", valores_finais->tempo_total, valores_finais->valor_arrecadado, 
			valores_finais->total_m, valores_finais->total_p, valores_finais->total_g);
		hora_flag += 60;
	}
	printf("%d veiculos\n", valores_finais->total_veiculos);
	
	printfilas(listaFilas);
	
	return 0;
}
