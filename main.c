#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#include "forca.h"


char PalavraSecreta [TAMANHO_PALAVRA];
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

    int erros = NumeroErros();



    printf("       +---+       \n");
    printf("       |   |      \n");
    printf("       %c   |      \n", (erros >= 1? 'O': ' '));
    printf("      %c%c%c  |     \n", (erros >= 2? '/': ' '), (erros >= 3? '|' : ' '), (erros >= 3? '\\': ' '));
    printf("      %c %c  |     \n", (erros >=4 ? '/': ' '), (erros >=4? '\\': ' '));
    printf("           |      \n");
    printf("      =========   \n");

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
        MensagemJogada();
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
            printf("\n\n   OPS, LETRA REPETIDA\n");
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
           printf("\n\n    EBA! LETRA ENCONTRADA\n ");
        } else {
             printf("\n\n    OPS! TENTE OUTRA LETRA\n");

        }

        int TentativasRestantes = 5-NumeroErros();

        if(TentativasRestantes != 0 && !GanhouPartida()){
            printf("-> TENTATIVAS RESTANTES: %d\n\n", TentativasRestantes );
        }


}

void MensagemFinal(){

    if(GanhouPartida()){


         printf(" ##      ####                ##        ##    \n");
         printf(" ####      ##              ####      ##      \n");
         printf("   ##        ##            ##      ####      \n");
         printf("     ##      ####        ##        ##        \n");
         printf("     ####      ##      ####      ####        \n");
         printf("       ##              ##      ####          \n");
         printf("         ##          ##        ##            \n");
         printf("         ####      ####      ##              \n");
         printf("           ##  ################              \n");
         printf("           ##################                \n");
         printf("           ####################              \n");
         printf("         ########      ##########            \n");
         printf("         ########      ##########            \n");
         printf("       ############    ##########            \n");
         printf("       ############    ##########            \n");
         printf("         ##########    ##########            \n");
         printf("         ##########    ##########            \n");
         printf("         ######################              \n");
         printf("           ####################              \n");
         printf("             ##############                  \n");
         printf("                   ####                      \n");



        printf("\n");
        printf("       ***************************\n");
        printf("       ** VITÓRIA CONQUISTADA! **\n");
        printf("       ***************************\n\n");

    } else {


        printf("                  ################                \n");
        printf("              ########################            \n");
        printf("            ############################          \n");
        printf("         ################################         \n");
        printf("          ################################        \n");
        printf("        ####################################      \n");
        printf("        ####################################      \n");
        printf("        ######################################    \n");
        printf("      ########################################    \n");
        printf("      ########################################    \n");
        printf("      ########      ++##########      ########    \n");
        printf("      MM####          ########          ######    \n");
        printf("      @@####            @@##..          @@####    \n");
        printf("      --@@##            ######          MM####    \n");
        printf("        ####          ########          ####      \n");
        printf("        ####################################      \n");
        printf("        ################    ################      \n");
        printf("      --##############        ################    \n");
        printf("      @@##############        ################    \n");
        printf("        ##############  ::MM  ##############      \n");
        printf("                ####################              \n");
        printf("                @@##################              \n");
        printf("                  ##  ####++##  ####              \n");
        printf("                ::##  ####++##  ####              \n");
        printf("                        --..                      \n");


        printf("\n");
        printf("               ***********************\n");
        printf("               *** PERDEU O JOGO!! ***\n");
        printf("               ***********************\n");

    }

}

int enforcou(){

    int erros = NumeroErros();

return erros >= 5;
}

int NumeroErros(){

    int erros = 0;

    for(int i =0; i < rodadas; i++){
        int existe;

        existe = LetraExiste(i);

        if (!existe) erros++;

    }

    return erros;
}

int LetraExiste(int i){

    for (int n = 0; n < strlen(PalavraSecreta); n++){

        if (chutes[i] == PalavraSecreta[n]){
            return 1;

        }
    }

    return 0;
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

    return 1;

}


void AdicionarPalavra(){

    char adicionar;

    printf("\n");
    printf("   Deseja adicionar uma palavra?\n");
    printf("   S- SIM   N- Não\n");
    printf("   Resposta: ");
    scanf(" %c", &adicionar);

    if (adicionar == 'S'){

        char NovaPalavra[TAMANHO_PALAVRA];
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

    MensagemFinal();
    AdicionarPalavra();

return 0;
}
