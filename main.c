#include "jogadores.h"
#include "admin.h"

int menu()
{
	int option=0;
	system("cls");	
	printf("\n\n\t/////////////////////////////////////\n");
	printf("\t/////////////////////////////////////\n");
	printf("\t/////////////////////////////////////\n");
	printf("\n\t\tBem-vindo ao GOOSE GAME!\n\n");
	printf("\t/////////////////////////////////////\n");
	printf("\t/////////////////////////////////////\n");
	printf("\t/////////////////////////////////////\n\n\n");
	printf("\tEscolha uma opcao:\n\n");
	printf("\t1. Administrar o jogo\n");
	printf("\t2. Jogar\n");
	printf("\t3. Listar jogadores por nome\n");
	printf("\t4. Listar jogadores por idade\n");
	printf("\t5. Listar jogadores por data de jogo\n");
	printf("\t6. Sair\n\n");
	printf("\t   Prima a sua opcao:\n");
	scanf("\t%d", &option);
	return option;
}

int main()
{
	int total_admins = 0;
	int total_jogadores = 0;
	total_jogadores = readPlayers(jogadores);
	int option = -1;
	while(option!= 0)
	{
		option = menu();
		switch(option)
		{
			case 1:
				{
					login_admin(total_admins,admins);
					break;
			}
			case 2:
				{
					login_players(total_jogadores,jogadores);
					break;
			}
			case 3:
				{
					show_name(total_jogadores,jogadores);
					break;
			}
			case 4:
				{
					show_age(total_jogadores,jogadores);
					break;
			}
			case 5:
				{
					show_date(total_jogadores,jogadores);
					break;
			}
		}
	}
	return 0;
}
