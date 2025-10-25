#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    srand(time(NULL));
    int *A;
    int *B;
    int *C;
    int l;
    int m;
    int n;

    printf("Inserisci numero righe della prima matrice: ");
    scanf("%d", &l);

    printf("Inserisci numero colonne della prima e righe della seconda matrice: ");
    scanf("%d", &n);

    printf("Inserisci numero colonne della seconda matrice: ");
    scanf("%d", &m);

    A = (int*)malloc(sizeof(int)*l*n);
    B = (int*)malloc(sizeof(int)*n*m);
    C = (int*)malloc(sizeof(int)*l*m);

    for (int i = 0; i < l; i++) {
        for (int j = 0; j < n; j++) {
            A[i*n+j] = (rand() % 10) + 1;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            B[i*m+j] = (rand() % 10) + 1;
        }
    }

    if (A!=NULL && B!=NULL && C!=NULL) {
        for (int i = 0; i < l; i++) {
            for (int j = 0; j < m; j++) {
                C [i*m+j] = 0;
                for (int k = 0; k < n; k++) {
                    C[i*m+j] += A[i*n+k] * B[k*m+j];
                }
            }
        }
    }

    printf("\nMatrice A:");
    for (int i = 0; i < l; i++) {
        printf("\n");
        for (int j = 0; j < n; j++) {
            printf("%d ", A[i*n+j]);
        }
    }

    printf("\nMatrice B:");
    for (int i = 0; i < n; i++) {
        printf("\n");
        for (int j = 0; j < m; j++) {
            printf("%d ", B[i*m+j]);
        }
    }

    printf("\nMatrice C: ");
    for (int i = 0; i < l; i++) {
        printf("\n");
        for (int j = 0; j < m; j++) {
            printf("%d ", C[i*m+j]);
        }
    }

    return 0;
}
