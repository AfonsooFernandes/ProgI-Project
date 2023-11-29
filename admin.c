#include "admin.h"

void novo_admin(int total_admins, ADMIN admins[]) //adicionar um novo administrador ao arquivo de texto 
{ 
	FILE *fp = NULL;
	fp = fopen("admins.txt", "a");
	if(fp == NULL)
	{
		printf("Erro ao abrir o ficheiro!\n");
		return;
	}
	printf("\tUsername do admin: ");
	fflush(stdin);
	gets(admins[total_admins].user);
	printf("\tPassword: ");
	gets(admins[total_admins].passwd);
	fprintf(fp,"%s;",admins[total_admins].user);
	fprintf(fp,"%s;\n",admins[total_admins].passwd);
	fclose(fp);
	total_admins++;
}

void login_admin(int total_admins,ADMIN admins[]) //verificar se um administrador est� registrado no arquivo "admins.txt" com base no nome de usu�rio e senha fornecidos.
{
	char line[100];
	char username[50], password[50];
    char user[50], passwd[50];
    int found = 0; // flag para indicar se o admin foi encontrado

    printf("Username do admin: ");
    fflush(stdin);
    gets(username);
    printf("Password: ");
    gets(password);
    FILE *fp = NULL;
    fp = fopen("admins.txt", "r");
    if (fp == NULL) {
        printf("Erro ao abrir o ficheiro.");
    	return;
    }

    while (fgets(line, sizeof(line), fp))
    {
       sscanf(line, "%[^;];%[^;];", user, passwd);
       if (strcmp(user, username) == 0 && strcmp(passwd, password) == 0)
	  {
          found = 1;
          break;
       }
    }

	fclose(fp);

	if (found == 1)
	{
    	printf("O admin %s foi encontrado.\n", username);
    	gerir_admins(username);
	} 
	else
	{
    	printf("O admin %s nao foi encontrado, registando...\n", username);
    	novo_admin(total_admins,admins);	
	}
	return;
}
