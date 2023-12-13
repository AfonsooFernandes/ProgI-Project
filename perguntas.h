#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct perguntaMultipla{
    char pergunta[100];
    char respostaA[100];
    char respostaB[100];
    char respostaC[100];
    char respostaD[100];
    char respostacerta[100];
} PMULTIPLA;

typedef struct elemM{
	PMULTIPLA PMULTIPLA;
	struct elemM *seguinte;	 
	struct elemM *anterior;	
}ELEMM;
