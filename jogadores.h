#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define MAX_JOGADORES 50

typedef struct jogador{
	int num;
	int idade;
	int dados;
	char user[50];
	char password[50];
	char nacionalidade[50];
	int posicao;
	int perguntas_respondidas;
	char data_jogo[50];
	int resposta_errada;
}JOGADOR;

JOGADOR jogadores[MAX_JOGADORES];
JOGADOR create_player(int total_jogadores, JOGADOR jogadores[]);
void login_players(int total_jogadores, JOGADOR jogadores[]);
int readPlayers(JOGADOR jogadores[]);
void writePlayers(int total_jogadores, JOGADOR jogadores[], int qtd, JOGADOR players[]);
void show_name(int total_jogadores, JOGADOR jogadores[]);
void show_age(int total_jogadores, JOGADOR jogadores[]);
void show_date(int total_jogadores, JOGADOR jogadores[]);
char* obterDataAtual();
