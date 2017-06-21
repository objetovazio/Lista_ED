#ifndef VEICULO_H_
#define VEICULO_H_

typedef struct Veiculo
{
	double Valor;
	char Tipo;
	int TempoPassagem;
	int Prioridade;
} Veiculo;

Veiculo* criar_veiculo_custom(double valor, char tipo, int tempo, int prioridade);
Veiculo* criar_veiculo(char tipo);
double get_valor(Veiculo* v);
char get_tipo(Veiculo* v);
int get_tempo(Veiculo* v);

#endif
