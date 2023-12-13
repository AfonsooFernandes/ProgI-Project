#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "perguntas.h"
#include "jogadores.h"

#define casas_1 20
#define casas_2 30
#define casas_3 50
#define MAX_SIZE 2

typedef struct jogo{
	char data[50];
	char vencedor[100];
	int tipotab;
	int jogadores;
}JOGO;

int casas1[casas_1] = {1,2,4,1,4,1,2,3,5,1,3,3,6,1,4,5,6,1,1,2};
int casas2[casas_2] = {1,2,2,1,4,1,2,3,1,1,3,3,1,1,4,5,6,1,1,2,4,3,6,1,2,4,3,2,5,3};
int casas3[casas_3] = {1,2,2,1,4,1,2,3,1,1,3,3,1,1,4,5,6,1,1,2,4,3,6,1,2,4,3,2,5,3,1,2,4,1,4,1,2,3,5,1,3,3,6,1,4,5,6,1,1,2};


int escolher_tabuleiro(JOGADOR players[], int qtd, int total_jogadores);
int jogar(JOGADOR players[], int qtd, int casa[], int n_casas, int total_jogadores);
char* dataAtual();
