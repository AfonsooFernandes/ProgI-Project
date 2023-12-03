#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "perguntas.h"
#define MAX_ADMIN 1

typedef struct admin{
	char user[50];
	char passwd[50];
}ADMIN;

ADMIN admins[MAX_ADMIN];

void novo_admin(int total_admins, ADMIN admins[]);
void login_admin(int total_admins,ADMIN admins[]);
void gerir_admins(char user[]);
