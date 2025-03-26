#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>

#define PORT 8085

int main() {
    // Criando o socket do servidor
    int server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd == 0) {
        perror("Falha ao criar o socket");
        return -1;
    }

    struct sockaddr_in address;
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY; // Escuta em todos os IPs disponíveis
    address.sin_port = htons(PORT);

    // Bind o socket ao endereço e porta
    if (bind(server_fd, (struct sockaddr*)&address, sizeof(address)) < 0) {
        perror("Falha no bind");
        return -1;
    }

    // Escutando por conexões
    if (listen(server_fd, 3) < 0) {
        perror("Falha no listen");
        return -1;
    }

    printf("Servidor aguardando conexão na porta %d...\n", PORT);

    int new_socket;
    struct sockaddr_in client_address;
    socklen_t addr_len = sizeof(client_address);

    // Aceitando a conexão do cliente
    new_socket = accept(server_fd, (struct sockaddr*)&client_address, &addr_len);
    if (new_socket < 0) {
        perror("Falha no accept");
        return -1;
    }

    printf("Cliente conectado!\n");

    // Recebendo a mensagem do cliente
    char buffer[1024] = {0};
    int valread = read(new_socket, buffer, 1024);
    if (valread < 0) {
        perror("Falha ao ler a mensagem");
        return -1;
    }

    // Exibe a mensagem recebida
    printf("Mensagem recebida do cliente: %s\n", buffer);

    // Fechar o socket
    close(new_socket);
    close(server_fd);

    return 0;
}
