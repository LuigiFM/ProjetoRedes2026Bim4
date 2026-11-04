#include <stdio.h>
#include <stdlib.h>

int main() {

    int liberados[4] = {22, 53, 80, 443};
    int solicitacoes[8];
    int quantidades, l, i, x;
    int permitidas = 0;
    int bloqueadas = 0;

    do {
        printf("Quantas tentativas deseja fazer? (1 a 8): ");
        scanf("%d", &quantidades);

        if (quantidades < 1 || quantidades > 8) {
            printf("Numero invalido! Tente novamente.\n");
        }

    } while (quantidades < 1 || quantidades > 8);

    printf("\nDigite os numeros das portas (22,53,80,443) :\n");

    for (i = 0; i < quantidades; i++) {

        do {
            printf("Porta %d: ", i + 1);
            scanf("%d", &l);

            if (l < 1 || l > 65535) {
                printf("Numero da porta invalido! Tente novamente.\n");
            }

        } while (l < 1 || l > 65535);

        solicitacoes[i] = l;
    }

    for (i = 0; i < quantidades; i++) {

        int encontrada = 0;

        for (x = 0; x < 4; x++) {

            if (solicitacoes[i] == liberados[x]) {
                encontrada = 1;
            }
        }

        if (encontrada == 1) {
            printf("Porta %d: PERMITIDA\n", solicitacoes[i]);
            permitidas++;
        } else {
            printf("Porta %d: BLOQUEADA\n", solicitacoes[i]);
            bloqueadas++;
        }
    }

    printf("\nSolicitacoes: ");

    for (i = 0; i < quantidades; i++) {
        printf("%d ", solicitacoes[i]);
    }

    printf("\n\n--- RESULTADO FINAL ---\n");
    printf("Solicitacoes realizadas: %d\n", quantidades);
    printf("Portas permitidas: %d\n", permitidas);
    printf("Portas bloqueadas: %d\n", bloqueadas);

    return 0;
}