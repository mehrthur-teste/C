#include <stdio.h>

int main() {
    FILE *file = fopen("file.txt", "r");
    if (file == NULL) {
        return 1;
    }

    // Ler e exibir o conteúdo
    char ch;
    while ((ch = fgetc(file)) != EOF) {
        putchar(ch);  // Exibe o caractere na tela
    }

    fclose(file);  // Fecha o arquivo
    return 0;
}
