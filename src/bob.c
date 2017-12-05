#include <stdio.h>
#include "cripto.h"
#include "socket.h"

int main(){

    time_t t;

    srand((unsigned) time(&t));

    int p;
    printf("Insira um numero primo: ");
    scanf("%d", &p);

    if(verificaPrimo(p) == 0){
        printf("\nNão é primo!\n");
        return -1;
    }

    printf("\nGerando o alfa...\n");
    sleep(1);
    long long int alfa = rand() % (p-2) + 2;
    printf("O valor de alfa é: %lld\n", alfa);


    printf("\nGerando o b...\n");
    sleep(1);
    long long int b = rand() % (p-2) + 2;
    printf("O valor de b é: %lld\n", b);

    printf("\nCalculando B...\n");
    sleep(1);
    int bezao = modulo(alfa,b,p);
    printf("B(%d) = alfa(%d)^b(%d) mod p(%d)\n", bezao,alfa,b,p);

    printf("\n#######\nB: %lld\nALFA: %d\nP: %lld\n",bezao,alfa,p);

    client();

    printf("\n----- Enviando (B,alfa,p) para Alice -----\n");
    sleep(1.5);
    printf("\n----- Esperando resposta de Alice -----\n");

    sendServer(&bezao);
    sendServer(&alfa);
    sendServer(&p);

    int azao;

    readServer(&azao);

    printf("\n\n ----- Valor de A recebido de Alice -----\n\n");
    printf("A: %d\n", azao);

    printf("\n\nCalculando A^b...\n");
    sleep(1);
    long long int key = modulo(azao,b,p);
    printf("key(%d) = A(%d)^b(%d) mod p(%d)\n\n",key,azao,b,p);

    return 0;
}
