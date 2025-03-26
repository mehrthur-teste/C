#include <stdio.h>

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int *ptr;

    // Apontando para o início do array
    for (ptr = arr; ptr < arr + 5; ptr++) {
        printf("Valor: %d\n", *ptr);
    }

    return 0;
}
