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

void writePlayers(int total_jogadores, JOGADOR jogadores[], int qtd, JOGADOR players[]) //GRAVA DADOS DOS JOGADORES EM ARQUIVO .TXT
{
    FILE *fp = fopen("jogadores.txt", "w");
    if (fp == NULL)
    {
        printf("Erro ao abrir o ficheiro!");
        return;
    }
    int i, j;
    for (i = 0; i < total_jogadores; i++)
    {
        int encontrado = 0;
        for (j = 0; j < qtd; j++)
	   {
            if (strcmp(players[j].user, jogadores[i].user) == 0 && strcmp(players[j].password, jogadores[i].password) == 0)
		  {
                jogadores[i] = players[j];
                encontrado = 1; //indicar que o jogador foi encontrado e n?o ? necess?rio escrever novamente os dados no arquivo.
                break;
            }
        }
        if (encontrado) //? usada para escrever os dados do jogador em jogadores[i] no arquivo de texto no formato
	   {
            fprintf(fp, "%s;%s;%s;%d;%d;%s\n", jogadores[i].user, jogadores[i].password, jogadores[i].nacionalidade, jogadores[i].perguntas_respondidas, jogadores[i].idade, jogadores[i].data_jogo);
        }
    }
    fclose(fp);
}

int readPlayers(JOGADOR jogadores[])
{
    FILE *fp = fopen("jogadores.txt", "r");
    if (fp == NULL)
    {
        printf("Erro ao abrir o ficheiro!");
        return 0;
    }
    int i = 0;
    while (i < MAX_JOGADORES && fscanf(fp, " %[^;];%[^;];%[^;];%d;%d;%[^;\n]\n", jogadores[i].user, jogadores[i].password, jogadores[i].nacionalidade, &jogadores[i].perguntas_respondidas, &jogadores[i].idade, jogadores[i].data_jogo) != EOF)
    {
        i++;
    }
    fclose(fp);
    return i;
}

void show_name(int total_jogadores, JOGADOR jogadores[])
{
	JOGADOR aux; //usada para auxiliar na troca de posi??es dos jogadores durante a ordena??o.
	int i = 0;
	int j = 0;
	for(i = 0; i < total_jogadores; i++)
	{
    		for(j = 0; j < total_jogadores - 1; j++)
    {
        		if(strcmp(jogadores[j].user, jogadores[j + 1].user) > 0)
	   { // indicar que o jogador atual ? maior que o pr?ximo jogador em ordem alfab?tica, ocorre uma troca de posi??es
            aux = jogadores[j];
            jogadores[j] = jogadores[j + 1];
            jogadores[j + 1] = aux;
        }
    }
}
for(i = 0; i < total_jogadores; i++){
    printf("Username: %s\n", jogadores[i].user);
    printf("Idade: %i\n", jogadores[i].idade);
    printf("Nacionalidade: %s\n", jogadores[i].nacionalidade);
    printf("Numero de Respostas: %i\n", jogadores[i].perguntas_respondidas);
    printf("Data de jogo: %s\n", jogadores[i].data_jogo);
}
	system("pause");
}

void show_age(int total_jogadores, JOGADOR jogadores[])
{
JOGADOR aux;
int i, j;
for (i = 0; i < total_jogadores; i++) {
    for (j = 0; j < total_jogadores - 1; j++) {
        if (jogadores[j].idade > jogadores[j + 1].idade) {
            aux = jogadores[j];
            jogadores[j] = jogadores[j + 1];
            jogadores[j + 1] = aux;
        }
    }
}
for (i = 0; i < total_jogadores; i++) {
    printf("Username: %s\n", jogadores[i].user);
    printf("Idade: %i\n", jogadores[i].idade);
    printf("Nacionalidade: %s\n", jogadores[i].nacionalidade);
    printf("Numero de Respostas: %i\n", jogadores[i].perguntas_respondidas);
    printf("Data de jogo: %s\n", jogadores[i].data_jogo);
}
system("pause");
}

void show_date(int total_jogadores, JOGADOR jogadores[])
{
    JOGADOR aux;
    int i, j;
    for (i = 0; i < total_jogadores; i++)
    {
        for (j = 0; j < total_jogadores - 1; j++)
	   {
            struct tm data1, data2;
            sscanf(jogadores[j].data_jogo, "%d/%d/%d", &data1.tm_mday, &data1.tm_mon, &data1.tm_year);
            sscanf(jogadores[j + 1].data_jogo, "%d/%d/%d", &data2.tm_mday, &data2.tm_mon, &data2.tm_year);
            data1.tm_mon -= 1;
            data1.tm_year -= 1900;
            data2.tm_mon -= 1;
            data2.tm_year -= 1900;
            time_t t1 = mktime(&data1);
            time_t t2 = mktime(&data2);
            if (t1 < t2)
		  {
                aux = jogadores[j];
                jogadores[j] = jogadores[j + 1];
                jogadores[j + 1] = aux;
            }
        }
    }
    for (i = 0; i < total_jogadores; i++)
    {
        printf("Username: %s\n", jogadores[i].user);
        printf("Idade: %i\n", jogadores[i].idade);
        printf("Nacionalidade: %s\n", jogadores[i].nacionalidade);
        printf("Numero de Respostas: %i\n", jogadores[i].perguntas_respondidas);
        printf("Data de jogo: %s\n", jogadores[i].data_jogo);
    }
    system("pause");
}

char* obterDataAtual()
{
    time_t t = time(NULL);
    struct tm *data = localtime(&t);
    static char dataStr[11];

    strftime(dataStr, sizeof(dataStr), "%d/%m/%Y", data);

    return dataStr;
}
