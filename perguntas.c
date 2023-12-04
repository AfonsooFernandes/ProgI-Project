#include "perguntas.h"

ELEMM* imprimirPerguntas(ELEMM* iniELEMM)
{
    ELEMM* atual = iniELEMM; //vari?vel chamada atual e a inicializa com o valor do ponteiro iniELEMM, atual aponta para o mesmo elemento da lista que iniELEMM
    printf("Pergunta: %s\n", atual->PMULTIPLA.pergunta);
    printf("[A] - %s\n", atual->PMULTIPLA.respostaA);
    printf("[B] - %s\n", atual->PMULTIPLA.respostaB);
    printf("[C] - %s\n", atual->PMULTIPLA.respostaC);
    printf("[D] - %s\n", atual->PMULTIPLA.respostaD);
    atual = atual->seguinte;
    return atual;
}

void listarPerguntasMultipla(ELEMM *iniELEMM) //A fun??o percorre a lista e imprime informa??es sobre cada pergunta de m?ltipla escolha.
{
    if (iniELEMM == NULL)
    {
        printf("A lista esta vazia.\n");
        return;
    }

    ELEMM *atual = iniELEMM;
    while (atual != NULL)
    {
        printf("Pergunta: %s\n", atual->PMULTIPLA.pergunta);
        printf("Resposta A: %s\n", atual->PMULTIPLA.respostaA);
        printf("Resposta B: %s\n", atual->PMULTIPLA.respostaB);
        printf("Resposta C: %s\n", atual->PMULTIPLA.respostaC);
        printf("Resposta D: %s\n", atual->PMULTIPLA.respostaD);
        printf("Resposta Certa: %s\n", atual->PMULTIPLA.respostacerta);
        printf("\n");

        atual = atual->seguinte;
    }
}
