#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>

#define PORT 8085

int main() {
    int sock = 0;
    struct sockaddr_in server_address;

    // Criando o socket
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Falha ao criar o socket");
        return -1;
    }

    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(PORT);

    // Convertendo o IP para formato binário
    if (inet_pton(AF_INET, "127.0.0.1", &server_address.sin_addr) <= 0) {
        perror("Falha na conversão de endereço");
        return -1;
    }

    // Conectando ao servidor
    if (connect(sock, (struct sockaddr*)&server_address, sizeof(server_address)) < 0) {
        perror("Falha na conexão");
        return -1;
    }

    printf("Conectado ao servidor!\n");

    // Mensagem para o servidor
    const char* message = "Hello Smarters!!!";

    // Enviando a mensagem para o servidor
    send(sock, message, strlen(message), 0);
    printf("Mensagem enviada: %s\n", message);

    // Fechar o socket
    close(sock);

    return 0;
}
