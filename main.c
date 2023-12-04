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
