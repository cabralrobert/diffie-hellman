#include <stdio.h>
#include "cripto.h"
#include "socket.h"

int main(int argc, char const *argv[]){
    time_t t;
    srand((unsigned) time(&t));

    int p, alfa, bezao;

    printf("ESPERANDO POR BOB");

    server();

    readClient(&bezao);
    readClient(&alfa);
    readClient(&p);

    printf("\n\nGerando o a...\n");
    sleep(1);
    long long int a = rand() % (p-2) + 2;
    printf("O valor de a é: %lld\n", a);

    printf("\n\n----- p, alfa, B recebidos de Bob -----\n");
    printf("\nP: %d\nalfa: %d\nB: %d", p,alfa,bezao);

    printf("\n\nCalculando A.....");
    sleep(1);
    long long int azao = modulo(alfa,a,p);
    printf("\nA(%lld) = alfa(%d)^a(%d) mod p(%d)",azao,alfa,a,p);

    sendClient(&azao);

    printf("\n\nCalculando B^a...\n");
    sleep(1);
    long long int key = modulo(bezao,a,p);
    printf("key(%d) = B(%d)^a(%d) mod p(%d)\n\n",key,bezao,a,p);


    return 0;
}
