#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#include "forca.h"


char PalavraSecreta [TAMANHO_PALAVRA];
int rodadas = 0;
char ChuteRodada;
char chutes[26];
int NumeroTentativas;
int nivel;


void abertura(){
    printf("\n");
    printf("   ****************************\n\n");
    printf("   BEM VINDO AO JOGO DA FORCA\n\n");
    printf("   ****************************\n\n");

}

void menu(){

    printf("\n      ***** MENU ***** \n\n");
    printf("       1 - FÁCIL\n");
    printf("       2 - MÉDIO\n");
    printf("       3 - DIFÍCIL\n");

    printf("\n       RESPOSTA: ");
    scanf("%d", &nivel);

    switch (nivel){
    case 1:
        NumeroTentativas = 15;
        break;

    case 2:
        NumeroTentativas = 10;
        break;

    default:
        NumeroTentativas = 5;
        break;

    }

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

    fclose(f);
}

void DesenharForca(){

    int erros = NumeroErros();

    if (nivel == 1){
        printf("       +---+       \n");
        printf("       |   |      \n");
        printf("       %c   |      \n", (erros >= 5? 'O': ' '));
        printf("      %c%c%c  |     \n", (erros >= 8? '/': ' '), (erros >= 10? '|' : ' '), (erros >= 10? '\\': ' '));
        printf("      %c %c  |     \n", (erros >=13 ? '/': ' '), (erros >=14? '\\': ' '));
        printf("           |      \n");
        printf("      =========   \n");


    } else if (nivel == 2){
        printf("       +---+       \n");
        printf("       |   |      \n");
        printf("       %c   |      \n", (erros >= 3? 'O': ' '));
        printf("      %c%c%c  |     \n", (erros >= 4? '/': ' '), (erros >= 6? '|' : ' '), (erros >= 6? '\\': ' '));
        printf("      %c %c  |     \n", (erros >=8 ? '/': ' '), (erros >=9? '\\': ' '));
        printf("           |      \n");
        printf("      =========   \n");

    } else{

        printf("       +---+       \n");
        printf("       |   |      \n");
        printf("       %c   |      \n", (erros >= 1? 'O': ' '));
        printf("      %c%c%c  |     \n", (erros >= 2? '/': ' '), (erros >= 3? '|' : ' '), (erros >= 3? '\\': ' '));
        printf("      %c %c  |     \n", (erros >=4 ? '/': ' '), (erros >=4? '\\': ' '));
        printf("           |      \n");
        printf("      =========   \n");

    }



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
    int invalido = ChuteInvalido();

    if (!repetido && !invalido){

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


int ChuteInvalido(){

    int invalido = 1;

    if (ChuteRodada >= 65 && ChuteRodada <= 90 ){
        invalido = 0;

    } else {
        printf("\n\n   OPS, CARACTER INVALIDO\n");
        printf("   DIGITE UMA LETRA DE A a Z!\n");

    }

return invalido;
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

        int TentativasRestantes = NumeroTentativas-NumeroErros();

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

return erros >= NumeroTentativas;
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


        int PalavraR = PalavraRepetida(NovaPalavra, f, QntPalavras);

        if (!PalavraR){
            QntPalavras++;
            fseek(f, 0, SEEK_SET);
            fprintf(f, "%d", QntPalavras);


            fseek(f, 0, SEEK_END);
            fprintf(f, "\n%s", NovaPalavra);

            } else {

                AdicionarPalavra();
            }

         fclose(f);
    }
}

int PalavraRepetida(char* NovaPalavra, FILE* f, int QntPalavras){

    int PalavraRepetida;
    char PalavraBD[TAMANHO_PALAVRA];

    for (int i = 0; i <= QntPalavras; i++){

        PalavraRepetida = 0;
        fscanf(f, "%s", &PalavraBD);

        for (int n = 0; n <= strlen(PalavraBD); n++){
            if (PalavraBD[n] != NovaPalavra[n]){
                break;

            } else {
                PalavraRepetida = 1;
            }
        }
        if (PalavraRepetida){

            printf("\n\n   OPS, PALAVRA JÁ EXISTENTE\n");
            printf("    TENTE NOVAMENTE!\n");
            break;
        }
    }

return PalavraRepetida;
}



int main(){

    setlocale(LC_ALL, "Portuguese");

    abertura();
    menu();
    EscolhePalavra();


    do {

        printf("\n\n      RODADA: %d\n\n", (rodadas+1));

        DesenharForca();
        printf("\n");

        chute();


        printf("\n");
        printf("   ***********************\n\n");


    } while(!GanhouPartida() && !enforcou());

    MensagemFinal();

    if (GanhouPartida()){
        AdicionarPalavra();

    }


return 0;
}
