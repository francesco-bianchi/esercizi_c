#include <stdio.h>
#include <stdlib.h>

int main(void) {

    int n;

    printf("Esempio di Malloc, inserisci dimensione array:\n");

    scanf("%d", &n);

    printf("dimensione array: %d\n", n);

    int *a;
    a = (int*)malloc(n*sizeof(int));

    for (int i = 0; i < n; i++) {
        printf("Inserisci elemento a[%d]: ", i);
        scanf("%d", &a[i]);
    }

    for (int i = 0; i < n; i++) {
        printf("a[%d] = %d\n", i, a[i]);
    }

    printf("Libero lo spazio occupato da a: %d spazi di memoria heap\n", n*sizeof(int));
    free(a);

    return 0;
}
