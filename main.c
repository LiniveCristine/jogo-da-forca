#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#include "forca.h"


char PalavraSecreta [20];
int rodadas =0;
char ChuteRodada;
char chutes[26];


void abertura(){

    printf("\n");
    printf("   ****************************\n\n");
    printf("   BEM VINDO AO JOGO DA FORCA\n\n");
    printf("   ****************************\n\n");

}

void EscolhePalavra(){

    FILE* f;
    int QntPalavras;

    f = fopen("palavras.txt", "r");

    if(f == 0){
        printf("\n");
        printf("   Banco de dados de palavras não disponível \n");
        exit(1);

    }

    fscanf(f, "%d", &QntPalavras);

    srand(time(0));
    double NumeroAleatorio = rand()%QntPalavras;


    for(int i = 0; i <= NumeroAleatorio; i++){

        fscanf(f, "%s",PalavraSecreta);

    }
    //printf("%s\n", PalavraSecreta);

    fclose(f);
}

void DesenharForca(){

    int achou = 0;
    printf("  ");

    for(int i = 0; i< strlen(PalavraSecreta); i++){
        for (int n = 0; n < rodadas ; n++){

            if (PalavraSecreta[i] == chutes[n]){
                achou = 1;
                break;

            }
        }

        if (achou){
            printf(" %c", PalavraSecreta[i]);

        } else{
            printf(" _");

        }
        achou = 0;
    }

}

void chute (){

    printf("   Chute uma letra: ");
    scanf(" %c", &ChuteRodada);

    int repetido = ChuteRepetido();

    if (!repetido){

        chutes[rodadas] = ChuteRodada;
        rodadas++;
        MensagemJogada(ChuteRodada, PalavraSecreta);
    }

}

int ChuteRepetido(){
    int repetido = 0;


    for(int i = 0; i < rodadas; i++){
       if (ChuteRodada == chutes[i]){
            repetido = 1;
            break;

        }
    }
        if (repetido){
            printf("   OPS, LETRA REPETIDA\n");
            printf("   TENTE NOVAMENTE!\n");
            }

    return repetido;
}

void MensagemJogada(){

        int acertou = 0;

        for(int i = 0; i < strlen(PalavraSecreta); i++){
          if (ChuteRodada == PalavraSecreta[i]){
                acertou = 1;
                break;

            }
        }

        if (acertou){
           printf("   EBA! LETRA ENCONTRADA\n ");
        } else {
             printf("   OPS! TENTE OUTRA LETRA\n");

        }

}


int enforcou(){

    int erros = 0;

    for(int i =0; i < rodadas; i++){
        int existe = 0;

        for (int n = 0; n < strlen(PalavraSecreta); n++){

            if (chutes[n] == PalavraSecreta[i]){
                existe =1;
                break;

                }
        }

        if (!existe) erros++;

    }

        printf("\n\n\n");
        printf(" -> TENTATIVAS RESTANTES: %d\n\n", (5-erros));

return erros >= 5;
}

int GanhouPartida(){

    for(int i = 0; i < strlen(PalavraSecreta); i++){
        int ganhou = 0;
        int achou = 0;

        for (int n = 0; n < rodadas; n++){
            if (PalavraSecreta[i] == chutes[n]){
                achou = 1;
                continue;
            }

        }
        if (!achou) return 0;
    }

        printf("\n");
        printf("   ***************************\n");
        printf("   ** VITÓRIA CONQUISTADA! **\n");
        printf("   ***************************\n\n");
    return 1;

}


void AdicionarPalavra(){

    char adicionar;

    printf("\n");
    printf("   Deseja adicionar uma palavra?\n");
    printf("   S- SIM \n   N- Não\n");

    scanf(" %c", &adicionar);

    if (adicionar == 'S'){

        char NovaPalavra[20];
        FILE* f;

        printf("\nDigite uma palavra em MAIÚSCULO: ");
        scanf("%s", &NovaPalavra);


        f = fopen("palavras.txt", "r+");
        if(f == 0){
            printf("\nBanco de dados não dosponível\n\n");
            exit(1);
        }

        int QntPalavras;
        fscanf(f,"%d", &QntPalavras);

        QntPalavras++;
        fseek(f, 0, SEEK_SET);
        fprintf(f, "%d", QntPalavras);


        fseek(f, 0, SEEK_END);
        fprintf(f, "\n%s", NovaPalavra);

        fclose(f);

    }



}



int main(){

    setlocale(LC_ALL, "Portuguese");

    abertura();
    EscolhePalavra();


    do {

        printf("      RODADA: %d\n\n", (rodadas+1));

        DesenharForca();
        printf("\n");

        chute();


        printf("\n");
        printf("   ***********************\n\n");


    } while(!GanhouPartida() && !enforcou());

    AdicionarPalavra();

return 0;
}
