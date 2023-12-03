#include "jogadores.h"

JOGADOR create_player(int total_jogadores, JOGADOR jogadores[]) //FUNCAO PARA CRIAR UM NOVO JOGADOR
{
	
    JOGADOR novo_jogador; //CRIADA NOVA VARIAVEL
    printf("\tUsername: ");
    fflush(stdin);
    scanf("%s", novo_jogador.user);
    
    printf("\tPassword: ");
    scanf("%s", novo_jogador.password);
    
    printf("\tNacionalidade: ");
    scanf("%s", novo_jogador.nacionalidade);
    
    printf("\tIdade: ");
    scanf("%d", &novo_jogador.idade);
    
    novo_jogador.perguntas_respondidas = 0;
    time_t t = time(NULL); //HORA ATUAL
    struct tm *data = localtime(&t); //LOCALTIME = CONVERTE O TEMPO EM ESTRUTURA D-M-A
    strftime(novo_jogador.data_jogo, sizeof(novo_jogador.data_jogo), "%d/%m/%Y", data); //FORMATA DATA NO CAMPO DATA_JOGO
    total_jogadores++;
    return novo_jogador;
}

void login_players(int total_jogadores, JOGADOR jogadores[])
{
    int qtd = 0; //N* de jogadores para jogar
    printf("N� jogadores[2-4]: ");
    scanf("%i", &qtd);

    JOGADOR *players = (JOGADOR*)malloc(qtd * sizeof(JOGADOR)); //memoria alocada para array de jogadores "players"
    if (players == NULL) {
        printf("Erro ao alocar mem?ria");
        return;
     }

    int i, j;
    for (i = 0; i < qtd; i++)
    {
        printf("Username: ");
        scanf("%s", players[i].user);
        printf("Password: ");
        scanf("%s", players[i].password);

        int encontrado = 0;
        for (j = 0; j < total_jogadores; j++)
	   {
              if (strcmp(players[i].user, jogadores[j].user) == 0 && strcmp(players[i].password, jogadores[j].password) == 0)
		    {
		  
                encontrado = 1; //as informa??es do jogador correspondente em jogadores[] s?o copiadas para players[i]
                players[i] = jogadores[j];
                players[i].num = i + 1;
                printf("Login Efetuado!\n");
                char *data = obterDataAtual();
                strcpy(players[i].data_jogo, data);
                printf("[Jogador %i] - %s\n", players[i].num, players[i].user);
                break;
               }
          }

        if (!encontrado) //JOGADOR NAO ENCONTRADO E ? NECESSARIO CRIAR JOGADOR, create_player chamada
	   {
	   		printf("Nao existe um jogador %s\n Registando...\n", players[i].user);
            	players[i] = create_player(total_jogadores, jogadores);
            	players[i].num = i + 1;
            	printf("O registo do %s foi efetuado!\n", players[i].user);
            	char *data = obterDataAtual();
            	strcpy(players[i].data_jogo, data);
            	printf("[Jogador %i] - %s\n", players[i].num, players[i].user);
            	total_jogadores++;
        	}
    	}

    writePlayers(total_jogadores, jogadores, qtd, players); //Grava jogadores em arquivo
    escolher_tabuleiro(players, qtd, total_jogadores); //Escolher tamanho tabuleiro para jogar
    free(players);
}
