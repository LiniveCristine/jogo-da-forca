#include <stdio.h>
#include <string.h>


void limpar_entrada() {
    char c;
    while ((c = getchar()) != '\n' && c != EOF) {}
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

    int GanhouPartida, enforcou, errou;
    int tentativas, achou;
    char ChuteRodada;
    char chutes[26];

    GanhouPartida = 0;
    enforcou = 0;
    errou = 0;
    tentativas = 0;
    achou = 0;



    do {


        for(int i = 0; i< strlen(PalavraSecreta); i++){
            for (int n = 0; n < tentativas ; n++){

                if (PalavraSecreta[i] == chutes[n]){
                    achou = 1;
                    break;

                }
            }

            if (achou){
                printf("%c", PalavraSecreta[i]);
            } else{
                printf(" _");

            }

            achou = 0;

        }

        printf("\n");


        printf("Chute uma letra: ");
        scanf(" %c", &ChuteRodada);
        chutes[tentativas] = ChuteRodada;


        for(int i = 0; i < strlen(PalavraSecreta); i++){
          if (ChuteRodada == PalavraSecreta[i]){
                errou = 0;
                break;

            } else{
                errou = 1;
            }
        }

        if (errou){
            printf("OPS! TENTE OUTRA LETRA\n");
        } else {
            printf("OBA! LETRA ENCONTRADA\n");
        }

        tentativas++;

        printf("\n");


    } while(!GanhouPartida && !enforcou);







return 0;
}
