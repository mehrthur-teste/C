#include <stdio.h>

int main() {
    FILE *file = fopen("file.txt", "w");
    if (file == NULL) {
        printf("Error to open the file\n");
        return 1;
    }

    // Escrever no arquivo
    fprintf(file, "Este é um exemplo de escrita em arquivo.\n");

    fclose(file);  // Fecha o arquivo
    return 0;
}
