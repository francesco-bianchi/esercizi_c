#include <stdio.h>

int main(void) {
    printf("Inizio programma, inizializzo matrici\n");
    int a[16] = {
        1, 2, 3, 4,
        5, 6, 7, 8,
        9, 10, 11, 12,
        13, 14, 15, 16
    };

    int b[20] = {
        16, 15, 14, 13, 3,
        12, 11, 10, 9, 6,
        8, 7, 6, 5, 9,
        4, 3, 2, 1, 12
    };

    int c[20];

    printf("Stampo prima matrice\n");
    for (int i = 0; i < 4; ++i) {
        for (int j =0; j < 4; ++j) {
            printf("%d ", a[4*i+j]);
        }
        printf("\n");
    }

    printf("Stampo seconda matrice\n");
    for (int i = 0; i < 4; ++i) {
        for (int j =0; j < 5; ++j) {
            printf("%d ", b[5*i+j]);
        }
        printf("\n");
    }

    for (int i = 0; i < 4; ++i) {
        for (int j =0; j < 5; ++j) {
            c[5*i+j] = 0;
        }
    }

    printf("eseguo il prodotto tra matrici\n");

    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 5; ++j) {
            for (int k =0; k < 4; ++k) {
                c[i*5+j] += a[i*4+k]*b[j+(k*5)];
            }
        }
    }

    printf("Stampo prodotto\n");
    for (int i = 0; i < 4; ++i) {
        for (int j =0; j < 5; ++j) {
            printf("%d ", c[5*i+j]);
        }
        printf("\n");
    }
    return 0;
}