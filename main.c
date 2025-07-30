#include <stdio.h>
#include <string.h>


void abertura(){

    printf("\n");
    printf("   ****************************\n");
    printf("\n");
    printf("   BEM VINDO AO JOGO DA FORCA\n");
    printf("\n");
    printf("   ****************************\n");
    printf("\n");

}

void VerificarNumero(char PalavraSecreta[], char chutes[], int tentativas){

    int achou = 0;
    printf("  ");

    for(int i = 0; i< strlen(PalavraSecreta); i++){
        for (int n = 0; n < tentativas ; n++){

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

void MensagemJogada(int ChuteRodada, char PalavraSecreta[]){

        int acertou = 0;

        for(int i = 0; i < strlen(PalavraSecreta); i++){
          if (ChuteRodada == PalavraSecreta[i]){
                acertou = 1;
                break;

            } else{
                acertou = 0;
            }
        }

        if (acertou){
            printf("   OBA! LETRA ENCONTRADA\n");

        } else {
            printf("   OPS! TENTE OUTRA LETRA\n");

        }

}


int main(){

    char PalavraSecreta [20];
    PalavraSecreta[0] = 'M';
    PalavraSecreta[1] = 'E';
    PalavraSecreta [2] = 'L';
    PalavraSecreta[3] = 'A';
    PalavraSecreta[4] = 'N';
    PalavraSecreta [5] = 'C';
    PalavraSecreta[6] = 'I';
    PalavraSecreta[7] = 'A';
    PalavraSecreta[8] = '\0'; //indica que a string acabou

    int GanhouPartida, enforcou;
    int tentativas, achou;
    char ChuteRodada;
    char chutes[26];

    GanhouPartida = 0;
    enforcou = 0;
    tentativas = 0;
    achou = 0;



    abertura();


    do {


        VerificarNumero(PalavraSecreta, chutes, tentativas);

        printf("\n");


        printf("   Chute uma letra: ");
        scanf(" %c", &ChuteRodada);
        chutes[tentativas] = ChuteRodada;
        tentativas++;

        MensagemJogada(ChuteRodada, PalavraSecreta);


        printf("\n");
        printf("   ***********************\n");
        printf("\n");


    } while(!GanhouPartida && !enforcou);


return 0;
}
