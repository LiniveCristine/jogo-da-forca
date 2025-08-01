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

void EscolhePalavra(char* PalavraSecreta){

    sprintf(PalavraSecreta, "MELANCIA");
}

void DesenharForca(char* PalavraSecreta, char* chutes, int tentativas){

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

int ChuteRepetido(int tentativas, char* chutes, char ChuteRodada){
    int repetido = 0;


    for(int i = 0; i < tentativas; i++){
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

void MensagemJogada(char ChuteRodada, char PalavraSecreta[]){

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


void chute (char* ChuteRodada, char* chutes, int* tentativas, char* PalavraSecreta){

    printf("   Chute uma letra: ");
    scanf(" %c", &*ChuteRodada);

    int repetido = ChuteRepetido(*tentativas, chutes, *ChuteRodada);

    if (!repetido){

        chutes[*tentativas] = *ChuteRodada;
        (*tentativas)++;
        MensagemJogada(*ChuteRodada, PalavraSecreta);
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
    int tentativas;
    char ChuteRodada;
    char chutes[26];

    GanhouPartida = 0;
    enforcou = 0;
    tentativas = 0;



    abertura();
    EscolhePalavra(PalavraSecreta);


    do {

        printf("      RODADA: %d\n", (tentativas+1));
        printf("\n");

        DesenharForca(PalavraSecreta, chutes, tentativas);

        printf("\n");

        chute(&ChuteRodada, chutes, &tentativas, PalavraSecreta);


        printf("\n");
        printf("   ***********************\n");
        printf("\n");


    } while(!GanhouPartida && !enforcou);


return 0;
}
