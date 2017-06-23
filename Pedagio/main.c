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

void preenche_filas_pedagio(lista *lista_filas){
	lista *lista_veiculos = criar_lista();
	
	printf("Reading: ");
	Veiculo *veic;
	char c = getchar();
	while (c != EOF && c != '\n'){
		veic = criar_veiculo(c);
		if(veic != NULL){
			inserir(lista_veiculos, veic);
		}
		c = getchar();
	}
	
	int i, pos = 0;
	for(i = 0; i < get_size(lista_veiculos); i += 1){
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
	int filas = atoi(argv[1]);
	
	int hora_flag = 60, tempo_atual = 0;

	lista *listaFilas = criar_lista();
	
	cria_filas_pedagio(listaFilas, filas);
	
	preenche_filas_pedagio(listaFilas);
	
	printf("\n%d fila(s)\n", filas);
	Tuple *valores_finais = inicializa_valores_finais();

	int vet[filas], i;
	for(i = 0; i < filas; i++){
		vet[i] = 0;
	}
	
	while(get_size(listaFilas)){	
		// Pecorre filas
		for(i = 0; i < get_size(listaFilas); i++){			
			fila_prioridade *fila = (fila_prioridade*)get_index(listaFilas, i);
			if(get_size_fila(fila) == 0) continue;
						
			while(vet[i] < hora_flag && get_size_fila(fila) > 0){	
				Veiculo *v = peek(fila);
				
				vet[i] += get_tempo(v);
				valores_finais->total_veiculos += 1;
				valores_finais->valor_arrecadado += get_valor(v);
				
				switch(get_tipo(v)){
					case('P'):
					case('p'):
						valores_finais->total_p += 1;
						break;
					case('G'):
					case('g'):
						valores_finais->total_g += 1;
						break;
					case('M'):
					case('m'):
						valores_finais->total_m += 1;
						break;
				}
				
				pop_Elem(fila);
			}
			
		}
		
		int menor_hora = hora_flag;
		for(i = 0; i < filas; i++){
			int tempo = vet[i];
			
			if(tempo < menor_hora){
				menor_hora = tempo;
				valores_finais->tempo_total = tempo;
			}else{
				valores_finais->tempo_total = menor_hora;
			}
		}
		
		printf("%d min: %.2f (%dM, %dP, %dG)\n", valores_finais->tempo_total, valores_finais->valor_arrecadado, 
			valores_finais->total_m, valores_finais->total_p, valores_finais->total_g);
			
		hora_flag += 60;
		zera_veiculos(valores_finais);
		
		int isEmpty = 1;
		for(i = 0; i < get_size(listaFilas); i++){
			fila_prioridade *fila = (fila_prioridade*)get_index(listaFilas, i);
			if(get_size_fila(fila) > 0){
				isEmpty = 0;
				break;
			}
		}
		
		if(isEmpty) {
			break;
		}
	}
	
	printf("%d veiculos\n", valores_finais->total_veiculos);
	
	return 0;
}
