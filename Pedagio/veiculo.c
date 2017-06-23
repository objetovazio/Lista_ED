#include <stdlib.h>
#include <stdio.h>
#include "veiculo.h"

Veiculo* criar_veiculo_custom(double valor, char tipo, int tempo, int prioridade){
	Veiculo *v = malloc(sizeof(Veiculo));
	v->Valor = valor;
	v->Tipo = tipo;
	v->TempoPassagem = tempo;
	v->Prioridade = prioridade;
	
	return v;
}

Veiculo* criar_veiculo(char tipo){
	Veiculo *v = malloc(sizeof(Veiculo));
	v->Tipo = tipo;
	
	switch(tipo){
		case 'P':
		case 'p':
			v->Valor = 2.00;
			v->TempoPassagem = 1;
			v->Prioridade = 1;
			break;
		case 'M':
		case 'm':
			v->Valor = 1.00;
			v->TempoPassagem = 1;
			v->Prioridade = 1;
			break;
		
		case 'G':
		case 'g':
			v->Valor = 3.00;
			v->TempoPassagem = 2;
			v->Prioridade = 0;
			break;		
	}
		
	return v;
}

double get_valor(Veiculo* v){
	return v->Valor;
}

int get_tempo(Veiculo *v){
	return v->TempoPassagem;
}

char get_tipo(Veiculo *v){
	return v->Tipo;
}
