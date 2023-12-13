#include "tabuleiros.h"

int escolher_tabuleiro(JOGADOR players[], int qtd, int total_jogadores) //PERMITE AO JOGADOR ESCOLHER O TAMANHO DO TABULEIRO
{
	int option = 0;
	system("cls");
	printf("\n\n\t/////////////////////////////////////\n");
	printf("\t/////////////////////////////////////\n");
	printf("\t/////////////////////////////////////\n");	
	printf("\n\t\tBem-vindo ao GOOSE GAME!\n\n");
	printf("\t/////////////////////////////////////\n");
	printf("\t/////////////////////////////////////\n");
	printf("\t/////////////////////////////////////\n\n\n");
	printf("Escolha o tamanho do tabuleiro:\n\n");
	printf("1. S-20 casas\n");
	printf("2. M-30 casas\n");
	printf("3. L-50 casas\n\n");
	printf("Escola a opcao:\n");
	scanf("%d", &option);
	switch(option)
	{
		case 1:
		{
			jogar(players, qtd, casas1, casas_1, total_jogadores);
			break;
		}
		case 2:
		{
			jogar(players, qtd, casas2, casas_2, total_jogadores);
			break;
		}
		case 3:
		{
			jogar(players, qtd, casas3, casas_3, total_jogadores);
			break;
		}
	}
}

int jogar(JOGADOR players[], int qtd, int casa[], int n_casas, int total_jogadores) //C�DIGO DO JOGO
{
	ELEMM *iniELEMM=NULL;
	ELEMM *fimELEMM=NULL;
	lerPerguntasBinario(&iniELEMM, &fimELEMM);
	char resposta[100];
	int i = 0;
	while((players[0].posicao + 1) < n_casas || (players[1].posicao + 1) < n_casas || (players[2].posicao + 1) < n_casas || (players[3].posicao + 1) < n_casas)
	{
		for(i = 0; i < qtd; i++)
		{
			players[i].resposta_errada = 0;
			while(players[i].resposta_errada == 0 && players[i].posicao < n_casas)
			{
				printf("Username: %s\n", players[i].user);
				printf("Posicao [%i]\n", players[i].posicao + 1);
				iniELEMM = imprimirPerguntas(iniELEMM);
				fflush(stdin);
				printf("Resposta: ");
				gets(resposta);
				players[i].perguntas_respondidas++;
				if(verificarRespostaCorreta(iniELEMM,resposta) == 1)
				{
					//verificar se a resposta t? correta
					players[i].posicao += casa[players[i].posicao];
				}
				else if(players[i].posicao > 0)
				{
					players[i].posicao -= casa[players[i].posicao];
					players[i].resposta_errada = 1;
					if(players[i].posicao < 0)
					{
						players[i].posicao = 0;
					}
				}
				if(players[i].posicao == n_casas - 1)
				{
						printf("VENCEDOR - %s\n", players[i].user);
						JOGO jogo;
				}
			}
		}
	}
}

char* dataAtual() //retorna a data atual no formato de uma string. 
{
	time_t t = time(NULL);
	struct tm *data = localtime(&t);
	static char dataStr[11];
	
	strftime(dataStr, sizeof(dataStr), "%d/%m/%Y", data);
	
	return dataStr;
}
