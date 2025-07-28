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

    int GanhouPartida, enforcou, acertou;
    int i;
    char chute;

    GanhouPartida = 0;
    enforcou = 0;
    acertou = 0;


    do {


        for(i = 0; i< strlen(PalavraSecreta); i++){
            printf("_ ");
        }

        printf("\n");


        printf("Chute uma letra: ");
        scanf(" %c", &chute);

        for(i = 0; i<= strlen(PalavraSecreta); i++){
            if (chute == PalavraSecreta[i]){
                acertou = 1;
                break;

            }
        }

        if (acertou){
            printf("A letra %c esta CORRETA\n", chute);

        }else {
            printf("A letra %c esta INCORRETA\n", chute);

        }

        acertou = 0;
        //limpar_entrada();

        printf("\n");


    } while(!GanhouPartida && !enforcou);







return 0;
}
