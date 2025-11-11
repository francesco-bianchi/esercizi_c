#include <stdio.h>
#include <stdlib.h>

void function_arr(int *A, int N, int *M) {
    *M = 0;
    int write_pos = 0;

    for (int i = 0; i < N; i++) {
        // Salta i duplicati consecutivi
        if (i == 0 || A[i] != A[i-1]) {
            A[write_pos] = A[i];
            write_pos++;
        } else {
            (*M)++;
        }
    }

    // Riempie con zeri
    for (int i = write_pos; i < N; i++) {
        A[i] = 0;
    }
}
void rim_occorrenze(int *B, int N, int *M) {
    *M = 0;
    int k=0;
    int trovato;
    for (int i = 0; i < N; i++) {
        trovato = 0;
        // Controllo se B[i] è già nell'array "pulito" (da 0 a write_pos-1)
        for (int j = 0; j < k; j++) {
            if (B[i] == B[j]) {
                trovato = 1;
                break;
            }
        }

        if (trovato==0) {
            // È unico, lo scrivo nella posizione corrente
            B[k] = B[i];
            k++;
        } else {
            // È duplicato, incremento il contatore
            (*M)++;
        }
    }
    for (int i = N-*M; i < N; i++) {
        B[i] = 0;
    }
}

int array_pal(int *B, int N) {
    for (int i = 0; i < N/2; i++) {
        if (B[i] != B[N-1-i]) {
            return 0;
        }
    }
    return 1;
}

void rimuovi_pari(int *A, int N, int *M) {
    *M = 0;
    for (int i = 0; i < N-*M; i++) {
        if (A[i] % 2 == 0) {
            (*M)++;
            for (int j = i; j < N-*M; j++) {
                A[j] = A[j+1];
            }
            i--;
        }
    }
    for (int i = N-*M; i < N; i++) {
        A[i] = 0;
    }
}

void sposta_zeri_fine(int *B, int N, int *M) {
    *M = 0;
    for (int i = 0; i < N- *M; i++) {
        if (B[i] == 0) {
            for (int j = i; j < N-*M; j++) {
                B[j] = B[j+1];
            }
            (*M)++;
            i--;
        }
    }
    for (int i = N-*M; i < N; i++) {
        B[i] = 0;
    }
}

void separa_pari_dispari(int *A, int N) {
    int conta=0;
    for (int i = 0; i < N-conta; i++) {
        if (A[i] % 2 == 1) {
            int tmp = A[i];
            for (int j = i; j < N-1; j++) {
                A[j] = A[j+1];
            }
            A[N-1] = tmp;
            conta++;
            i--;
        }
    }
}

void rimuovi_somme_due_el_prec(int *A, int N, int *M) {
    *M = 0;
    int count = 0;

    for (int i = 0; i < N; i++) {
        int trovato = 0;

        // Controlla tutte le coppie in [0, count)
        for (int j = 0; j < count && !trovato; j++) {
            for (int k = j+1; k < count; k++) {
                if (A[j] + A[k] == A[i]) {
                    trovato = 1;
                    break;
                }
            }
        }

        if (!trovato) {
            A[count] = A[i];
            count++;
        } else {
            (*M)++;
        }
    }

    // Azzera il resto
    for (int i = count; i < N; i++) {
        A[i] = 0;
    }
}

void mantieni_freq_minima(int *A, int N, int K, int *M) {
    *M = 0;
    int trovato;
    int j;
    int num_unici =0;
    int *A_occ = (int *)malloc(sizeof(int) * 2*N);

    for (int i = 0; i < N; i++) {
        j=0;
        trovato = 0;
        while (j < num_unici*2 && !trovato) {
            if (A[i] == A_occ[j]) {
                trovato = 1;
            }
            else
                j+=2;
        }
        if (!trovato) {
            A_occ[j] = A[i];
            A_occ[j+1] = 1;
            num_unici++;
        }
        else {
            A_occ[j+1]++;
        }

    }
    int write = 0;

    for (int i = 0; i < N; i++) {
        // Trova la frequenza di A[i]
        int freq = 0;
        for (int j = 0; j < num_unici * 2; j += 2) {
            if (A[i] == A_occ[j]) {
                freq = A_occ[j + 1];
                break;
            }
        }

        if (freq >= K) {
            A[write] = A[i];
            write++;
        } else {
            (*M)++;
        }
    }
    free(A_occ);
}

int rim(int **A, int N) {
    if (N==0) {
        return 0;
    }
    int M=0;
    for (int i = 0; i < N; i++) {
        if (*A[i] == 0) {
            M++;
        }
    }
    if (M==0)
        return -2;

    int *V;
    V = (int *)malloc(sizeof(int) * M);
    int j=0;
    for (int i = 0; i < N; i++) {
        if (A[i] != 0) {
            V[j] = *A[i];
            j++;
        }
    }
    free(*A);
    *A = V;
    return M;
}

int copia_arr(int *A, int N, int target, int **V, int M, int *size) {
    if (M<=0)
        return -1;
    int count_d=0;
    int count_e=0;
    for (int i = 0; i < N; i++) {
        if (A[i] == target) {
            count_d++;
        }
        else {
            count_e++;
        }
    }
    *size = count_d*M + count_e;
    *V = (int *)malloc(*size * sizeof(int));
    if (*V == NULL) {
        return -2;
    }
    int j=0;
    for (int i = 0; i < N; i++) {
        if (A[i] != target) {
            *V[j] = A[i];
            j++;
        }
        else {
            for (int k = j; k < M; k++) {
                *V[k] = A[i];
            }
            j+=M;
        }
    }
    return 0;
}

int main(void) {
    int A[] = {2,3,3,3,1,5,6,4,4,7,6,13,14,20};
    int B[] = {2,0,0,5,5,5,4,3,2};
    int N1 = sizeof(A) / sizeof(int);
    int N2 = sizeof(B) / sizeof(int);
    int M;
    int M2;

    /*function_arr(A, N1, &M);

    printf("Elementi rimossi: %d\n", M);
    printf("Array: ");
    for (int i = 0; i < N1; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");

    rim_occorrenze(B, N2, &M2);
    printf("Elementi rimossi: %d\n", M2);
    printf("Array: ");
    for (int i = 0; i < N2; i++) {
        printf("%d ", B[i]);
    }

    int palindromo = array_pal(B, N2);
    if (palindromo == 1) {
        printf("Palindromo\n");
    }
    else
        printf("No palindromo\n");
    printf("Array: ");
    for (int i = 0; i < N2; i++) {
        printf("%d ", B[i]);
    }
    rimuovi_pari(A, N1, &M);
    printf("Elementi rimossi: %d\n", M);
    printf("Array: ");
    for (int i = 0; i < N1; i++) {
        printf("%d ", A[i]);
    }
    sposta_zeri_fine(B, N2, &M);
    printf("Elementi spostati: %d\n", M);
    printf("Array: ");
    for (int i = 0; i < N2; i++) {
        printf("%d ", B[i]);
    }
    separa_pari_dispari(A, N1);
    printf("Array: ");
    for (int i = 0; i < N1; i++) {
        printf("%d ", A[i]);
    }
    rimuovi_somme_due_el_prec(A, N1, &M);
    printf("Elementi rimossi: %d\n", M);
    printf("Array: ");
    for (int i = 0; i < N1; i++) {
        printf("%d ", A[i]);
    }*/
    mantieni_freq_minima(A, N1, 2, &M);
    printf("Array: ");
    for (int i = 0; i < N1; i++) {
        printf("%d ", A[i]);
    }
    return 0;
}